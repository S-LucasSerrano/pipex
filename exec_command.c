#include "pipex.h"
#include <stdio.h>

/* Returns a pointer to the t_command that is the content of <lst> */
t_command	*get_cmd(t_list *lst)
{
	return ((t_command *)lst->content);
}

/* Does all the fd operations of the child process */
static void	chid_fdops(int	*pipefd)
{
	close(pipefd[READ_END]);
	dup2(pipefd[WRITE_END], STDOUT);
	close(pipefd[WRITE_END]);
}

/* Does all the fd operations of the father process */
static void	father_fdops(int *pipefd, t_pipex *data, t_list *current)
{
	close(pipefd[WRITE_END]);
	if (data->cmd_list == current)
		dup2(data->in_fd, STDIN);
	else
		dup2(pipefd[READ_END], STDIN);
	if (ft_lstlast(data->cmd_list) == current)
		dup2(data->out_fd, 1);
}

/*	Executes all commands in the <data->cmd_lst> using <data->in_fd>
*	as the starting info. And passing the output of each command to next.
*	Saving the final result in the <data->out_fd>. */
void	exec_cmd(t_pipex *data, t_list *current)
{
	t_pipefd	pipefd;
	t_list		*prev_cmd;
	pid_t		pid;
	int			status;

	pipe(pipefd);
	pid = 1;
	prev_cmd = ft_lstprev(data->cmd_list, current);
	if (prev_cmd != NULL)
		pid = fork();
	if (pid < 0)
		error("Fork error while sarting a new process \n");
	else if (pid == 0)
	{
		chid_fdops(pipefd);
		exec_cmd(data, prev_cmd);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		father_fdops(pipefd, data, current);
		execve(get_cmd(current)->file, get_cmd(current)->argv, NULL);
	}
}
