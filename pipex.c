/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:51:51 by latahbah          #+#    #+#             */
/*   Updated: 2022/02/19 23:43:21 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(t_data *data, int num, char **paths)
{
	char	*correct_path;
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(data->argv[num], ' ');
	if (cmd == NULL)
		end_with_description("Cmd split error");
	while (paths[i])
	{
		correct_path = ft_strjoin(paths[i], "/");
		correct_path = ft_strjoin(correct_path, cmd[0]);
		if (access(correct_path, 0) == 0)
		{
			break ;
		}
		i++;
	}
	if (execve(correct_path, cmd, data->envp) == -1)
		exit(EXIT_FAILURE);
}

static void	child_proc1(t_data *data, int fd[], int f1, char **paths)
{
	if (close(fd[0]) == -1)
		end_with_description("Close fd[0] error");
	if (dup2(f1, STDIN_FILENO) == -1)
		end_with_description("Dup2 f1 error");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		end_with_description("Dup2 fd[1] error");
	if (close(fd[1]) == -1)
		end_with_description("Close fd[1] error");
	exec_cmd(data, 2, paths);
}

static void	child_proc2(t_data *data, int fd[], int f2, char **paths)
{
	if (close(fd[1]) == -1 )
		end_with_description("Close fd[1] error");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		end_with_description("Dup2 fd[0] error");
	if (dup2(f2, STDOUT_FILENO) == -1)
		end_with_description("Dup2 f2 error");
	if (close(fd[0]) == -1)
		end_with_description("Close fd[0] error");
	exec_cmd(data, 3, paths);
}

static void	pipex(t_data *data, int f1, int f2)
{
	char		**paths;
	pid_t		id;
	int			status;
	int			fd[2];

	paths = retrieve_path(data->envp);
	if (paths == NULL)
		end_with_description("Retrive paths func error");
	if (pipe(fd) == -1)
		end_with_description("Pipe error");
	id = fork();
	if (id == -1)
		end_with_description("Fork error");
	else if (id == 0)
		child_proc1(data, fd, f1, paths);
	id = fork();
	if (id == -1)
		end_with_description("Fork error");
	else if (id == 0)
		child_proc2(data, fd, f2, paths);
	if (close(fd[0]) == -1)
		end_with_description("Close fd[0] error");
	if (close(fd[1]) == -1)
		end_with_description("Close fd[1] error");
	waitpid(-1, &status, 0);
}

int	main(int argc, char *argv[], char **envp)
{
	int		f1;
	int		f2;
	t_data	data;

	if (argc != 5)
		return (0);
	f1 = open(argv[1], O_RDONLY);
	if (f1 == -1)
		end_with_description("Open f1 error");
	f2 = open(argv[4], O_RDWR | O_CREAT, 0777);
	if (f2 == -1)
		end_with_description("Open f1 error");
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	pipex(&data, f1, f2);
	if (close(f1) == -1 || close(f2) == -1)
		end_with_description("Close f1 or f2 error");
	return (0);
}
