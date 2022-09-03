#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point of program
 * Return: 0
 */

int main(void)
{
	pid_t my_ppid = getppid();
	pid_t my_pid = getpid();
	pid_t child_pid = fork();

	printf("parent pid: %u\n", my_ppid);
	printf("My pid: %u\n", my_pid);
	printf("My child pid: %u\n", child_pid);
	return (0);
}
