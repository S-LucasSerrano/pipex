#include <stdio.h>
#include "pipex.h"

/* Prints <message> in red and returns FALSE */
int	error(char *message)
{
	if (1)
	{
		write(0, "\033[31m   ", 8);
		write(0, message, ft_strlen(message));
		write(0, "\033[0m", 4);
	}
	return (FALSE);
}

/* Prints <message> in red and returns NULL */
void	*null_error(char *message)
{
	error(message);
	return (NULL);
}

/* Frees a t_command, its file and argv */
static void	free_cmd(t_command *cmd, char **file, char ***argv)
{
	if (*file != NULL)
	{
		free(*file);
		*file = NULL;
	}
	if (*argv != NULL)
	{
		ft_free_table((void ***)argv);
	}
	free (cmd);
	cmd = NULL;
}

/*	Frees the t_command list and the paths char table.
*	Returning NULL and printing an error message. */
void	*initlst_error(t_list *lst, char ***paths)
{
	ft_free_table((void ***)paths);
	if (lst == NULL)
		null_error("Mem-alloc error initializing the command list \n");
	while (TRUE)
	{
		free_cmd(get_cmd(lst), &get_cmd(lst)->file, &get_cmd(lst)->argv);
		free(lst);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	lst = NULL;
	return (NULL);
}
