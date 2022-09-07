#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void child_process(char *path, char **cmd, char *envp[]);

int main(int ac __attribute__((unused)), char *argv[], char *envp[])
{
	char *cmd[] = {"ls", "-l", "/tmp", NULL};
	char *path = "/bin/ls";
	
	child_process(path, cmd, envp);
	printf("First child process returned to parent\n");
	child_process(path, cmd, envp);
	printf("Second child process returned to parent\n");
	child_process(path, cmd, envp);
	printf("Third child process returned to parent\n");
	child_process(path, cmd, envp);
	printf("Fourth child process returned to parent\n");
	child_process(path, cmd, envp);
	printf("Fifth child process returned to parent\n");

	return (0);
}

void child_process(char *path, char **cmd, char *envp[])
{
	int status, i = 0;
	pid_t cpid_1, rpid;

	cpid_1 = fork();

	if (cpid_1 == -1)
	{
		perror("Error: ");
		return;
	}
	if (cpid_1 == 0)
	{
		if (execve(path, cmd, envp) == -1)
		{
			perror("execve");
			return;
		}
	}
	else
	{
		rpid = waitpid(-1, &status, 0);
		if (rpid == -1)
		{
			perror("waitpid");
			return;
		}
	}
}
