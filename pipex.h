#ifndef PIPEX_H
# define PIPEX_H

// -------------------------------------

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

// -------------------------------------
// TYPES

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

/* Info needed to call new processes */
typedef struct s_command
{
	char				*file;
	char				**argv;
}	t_command;

/* A defined pipe with two file descriptors */
typedef int	t_pipefd[2];

/* File descriptors */
enum e_descriptors
{
	READ_END = 0,
	WRITE_END = 1,
	STDIN = 0,
	STDOUT = 1
};

/* Struct with all info */
typedef struct s_pipex
{
	int			in_fd;
	int			out_fd;
	t_list		*cmd_list;
}	t_pipex;

// --------------------------------------
// --- FUNCTIONS ---

t_bool		valid_files(int argc, char **argv);
t_list		*init_cmdlist(int cmd_count, char **argv, char **envp);

t_command	*get_cmd(t_list *lst);
void		exec_cmd(t_pipex *data, t_list *current);

int			error(char *message);
void		*null_error(char *message);
void		*initlst_error(t_list *lst, char ***table);

#endif