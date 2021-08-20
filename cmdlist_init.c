#include "pipex.h"

/* Creates -with malloc- a string that is <path> + "/" + <cmd> */
static char	*add_pathcmd(char *path, char *cmd)
{
	char	*aux;
	char	*output;

	output = ft_strjoin(path, "/");
	if (!output)
		return (NULL);
	aux = output;
	output = ft_strjoin(output, cmd);
	free(aux);
	if (!output)
		return (NULL);
	return (output);
}

/* Returns -using malloc- the file of a command if its path
is included in <paths>. Returning NULL if the command dont exit in PATHS. */
static char	*get_cmd_file(char *cmd, char **paths)
{
	char	*output;
	char	*str;
	int		fd;

	while (*paths)
	{
		str = add_pathcmd(*paths, cmd);
		if (!str)
			return (null_error("Memory allocation error \n"));
		fd = open(str, O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			return (str);
		}
		close (fd);
		free (str);
		paths++;
	}
	return (null_error("Error: invalid command\n"));
}

/* Creates -with malloc- a 2D chart table containing all paths in <envp> */
static char	**get_all_paths(char **envp)
{
	char	**paths;

	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH", 10))
		{
			while (**envp != '/')
				*envp += 1;
			paths = ft_split(*envp, ':');
			if (!paths)
				return (null_error("Memory allocation error \n"));
			return (paths);
		}
		envp++;
	}
	return (null_error("Error: No PATHS in envp \n"));
}

/* Returns a list with <cmd_count> nodes where
each node's content is a t_command* containing the
argv and file thats indicated in <argv> and <envp>. */
t_list	*init_cmdlist(int cmd_count, char **argv, char **envp)
{
	t_list		*cmd_lst;
	t_command	*cmd;
	char		**paths;
	int			i;

	paths = get_all_paths(envp);
	if (paths == NULL)
		return (NULL);
	i = 2;
	cmd_count += 2;
	cmd_lst = NULL;
	while (i < cmd_count)
	{
		cmd = malloc (sizeof (t_command));
		if (cmd == NULL)
			return (initlst_error(cmd_lst, &paths));
		ft_lstadd_back(&cmd_lst, ft_lstnew(cmd));
		cmd->argv = ft_split(argv[i], ' ');
		cmd->file = get_cmd_file(cmd->argv[0], paths);
		if (!cmd->file || !cmd->argv)
			return (initlst_error(cmd_lst, &paths));
		i++;
	}
	ft_free_table((void ***)&paths);
	return (cmd_lst);
}
