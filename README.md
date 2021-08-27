# pipex | slucas-s

This program replicates the functionality of the shell command ``< infile cmd1 | cmd2 | cmd3 | ... > outfile``. Taking whatever is in *infile* and using it as the input for the first command, passing the result as the input of the next command with a pipe, and so on. Saving the final result in *outfile*. To use it, once generated with the Makefile, just do ``./pipex infile “cmd1” “cmd2” “cmd3” … outfile``.

### Index
---
* [Pipex data structure and initialization](#Code)
* [Executing the commands](#Executing-the-commands)
* [Contact](#Contact)

### Code
---
First, as always, I check if the parameters of the program are valid. If there are at least 4 parameters: the name of the input file, 2 commands and an output file. And if we have read permission to the *infile*.

After that, I initialize the pipex data structure. Which contains all variables the program needs to work. A couple of file descriptors for the input and output files, and a list of commands. The list, as done in the [libft](https://github.com/S-LucasSerrano/Libft), contains a pointer to a command structure for the content, and a pointer to the next element of the list.

The command struct has a *file* string and a *argv* string array. This is the info that we need to pass to the ``execve`` function, that we use to execute the commands.

````c
typedef struct s_command	// Each element of the list has a pointer to one of these as its content
{
	char				*file;
	char				**argv;
}	t_command;

typedef struct s_pipex
{
	int		in_fd;		// the fd of the opened input file
	int		out_fd;		// the fd of the output file
	t_list		*cmd_list;	// the list of commands to execute
}	t_pipex;
````
To initialize the list I use the PATHS environment variable. I add each command passed as a program parameter to each path and try to open it. If one of the openings works, it’s because the command exists. So I add a new element to the list saving that as the *file* of the command struct and a ``split`` of the pipex program argument as the *argv*. If something in this process fails, it prints an error with what was wrong -like an invalid command or there not existing paths in envp- and the program ends.

So if, for example, I do ``./pipex infile “ls -l” “wc -w” outfile``. I will end up with a list wich first element has ``/bin/ls`` as *file* and ``{“ls”, “-l”, NULL}`` as *argv*. The second element of the list will be the same for the *wc* command.

###### Executing the commands
Now that I have all that is needed in the data structure, I start a **recursive loop** that executes all commands in the command list. The function receives the data structure and a pointer to the command of the list that it should execute. The first call to the function would execute the last command of the list.
````c
void	exec_cmd(t_pipex *data, t_list *current);
````
Then I generate a pipe with ``pipe(int [2])`` < https://www.tutorialspoint.com/unix_system_calls/pipe.htm >. This function generates a couple of file descriptors. The fd[0] is for reading, and fd[1] for writing.
Next, if the *current* element is not the first one of the command list,``int fork()`` is called < https://man7.org/linux/man-pages/man2/fork.2.html >. This creates a new copy of the current process. Essentially, your program is now running twice, both copies with the same info. But *Fork* will return a different value to each copy. The new process, the child, received 0.  While the father has the process identifier of the new child process.
Now a couple of ifs statements allow us to make something different in each case.

If we are **the child process**, we need to make sure that the standard output, where all commands write by default, is the write end of the pipe using ``dup2(int fd1, int fd2)`` < https://man7.org/linux/man-pages/man2/dup.2.html >. This function makes the file descriptor *fd2* be the same as *fd1*. With this, the next command will write its output in the pipe. Then, the child process calls the recursive function again, passing the data structure and the previous command to *current* of the list.

**The father process** waits until the child ends. Uses ``dup2`` to make the standard input the read end of the pipe. So whatever was written in the pipe by the previous command will be the input for the current one. And calls the function ``execve (...)`` to replace this process with a new one. For that it needs to receive the file to execute, with its path. A ``char **`` that will be the new process’ *argv* and other ``char **`` that will be its *envp*. Calling this function ends the current process, so nothing after the call will ever be executed.

````
To execute < ls | grep | wc >, the program will do:
---(fork)---(wait to child)---> wc
      ---(fork)---(wait to child)---> grep
            ---------> ls
````

### Contact
---
Feel free to clone this project, check the code or contact me if you want or find something wrong or missing in this documentation.

* 42 Login:	*slucas-s*
* Email:		*Lucas.ss.Serrano@Gmail.com*
* Portfolio:	*https://sergiolucasserrano.wixsite.com/website*

Good luck with your projects!