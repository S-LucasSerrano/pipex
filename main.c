#include "pipex.h"

/* Returns FALSE and prints an error if the parameters are invalid */
t_bool	valid_files(int argc, char **argv)
{
	t_bool	valid;

	valid = TRUE;
	if (argc < 5)
		valid = error("Error: Too few parameters \n");
	else
	{
		if (access(argv[1], R_OK) == -1)
			valid = error("Error: Could't read from the <infile> \n");
	}
	if (!valid)
		ft_putstr_fd("usage: ./pipex infile \"cmd1\" \"cmd2\" outfile \n", 0);
	return (valid);
}

/*	Initialice the t_pipex <data> structure
*	according to the program parameters.
*	Returning FALSE and printing an error if
*	there is a problem initializing the command list. */
t_bool	init_data(t_pipex *data, int argc, char **argv, char **envp)
{
	data->cmd_list = init_cmdlist(argc - 3, argv, envp);
	if (!data->cmd_list)
		return (FALSE);
	data->in_fd = open(argv[1], O_RDONLY);
	data->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (data->out_fd == -1)
	{
		error ("Error: Could't write on the <outfile> \n");
		ft_putstr_fd("usage: ./pipex infile \"cmd1\" \"cmd2\" outfile \n", 0);
		return (FALSE);
	}
	return (TRUE);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (!valid_files(argc, argv))
		return (0);
	if (!init_data(&data, argc, argv, envp))
		return (0);
	exec_cmd(&data, ft_lstlast(data.cmd_list));
	return (0);
}
