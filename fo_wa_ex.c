#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int ac, char *argv[], char *envp[])
{
	int status, i = 0;
	char *cmd[] = {"ls", "-l", "/tmp", NULL};
	char *path = "/bin/ls";
	pid_t cpid_1, cpid_2, cpid_3, cpid_4, cpid_5, rpid;

	cpid_1 = fork();

	if (cpid_1 == -1)
	{
		perror("Error: ");
		return (1);
	}

	if (cpid_1 == 0)
	{
		if (execve(path, cmd, envp) == -1)
		{
			perror("execve");
			return (1);
		}
	}
	else
	{
		rpid = waitpid(-1, &status, 0);
		if (rpid == -1)
		{
			perror("waitpid");
			return (1);
		}
		printf("Child process control returned to parent\n");
	}
	
	return (0);
}
