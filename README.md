# Ecole 42: Pipex

In this project I implemented a pipe functionaity, using unix system calls `fork`, `pipe`, `execve` and `dup2`

### How to build:

Clone repo and type:

```Bash
$ make
```

To clean object files:

```Bash
$ make clean
```

To clean object and library files:

```Bash
$ make fclean
```

To remake:

```Bash
$ make re
```

## How to use:

The program handles two commands. It takes 4 arguments:

* `file` and `file2` are file names
* `cmd1` and `cmd2` are shell commands with their parameters

To execute program:

```Bash
./pipex file1 cmd1 cmd2 file2
```

It is exactly the same as the shell command:

$> < file1 cmd1 | cmd2 > file2
