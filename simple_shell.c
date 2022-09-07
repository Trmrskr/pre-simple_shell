#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void parse_to_cmd(char *line, char **cmdline);

int main(int argc, char **argv, char *envp[])
{
	pid_t cpid, wpid;
	int status;
	ssize_t nread = 1;
	char *line = NULL, *cmdline, *cmd[4];
	size_t len = 0;

	while (nread != -1)
	{
		printf("$: ");
		nread = getline(&line, &len, stdin);

		if (nread == 1)
			continue;

		line = strtok(line, "\n");
		cmdline = strdup(line);
		parse_to_cmd(line, cmd);
/*		printf("%lu\n", strlen(cmd[0]));
		printf("%lu\n", strlen(cmd[1]));
		printf("%lu\n", strlen(cmd[2]));*/
		cpid = fork();

		if (cpid == -1)
		{
			perror("Fork: ");
			return (1);
		}

		if (cpid == 0)
		{
			if (execve(cmdline, cmd, envp) == -1)
			{
				perror("exece");
				return (1);
			}
		}
		else
		{
			wpid = waitpid(-1, &status, 0);
			if (wpid == -1)
			{
				perror("waitpid: ");
				return (1);
			}
		}
	}

	free(line);
	free(cmdline);
	fclose(stdin);

	return (0);
}

void parse_to_cmd(char *line, char **cmdline)
{
	char *path, *cmd, *opt, *dir, **a;
	int i;
	path = strtok(line, " ");
	opt = strtok(NULL, " ");
	dir = strtok(NULL, " ");
	cmd = strtok(path, "/");

	while (cmd != NULL)
	{
		cmdline[0] = cmd;
		cmd = strtok(NULL, "/");
	}

	cmdline[1] = opt;
	cmdline[2] = dir;
	cmdline[3] = NULL;

}
