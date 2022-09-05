#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t mypid;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}

	mypid = getpid();

	printf("%u is my pid\t", mypid);

	if (child_pid == 0)
	{
		printf("This is the child process: %u\n", mypid);
	}
	else
	{
		printf("This is the parent process to %u\n", child_pid);
	}
	return (0);
}
