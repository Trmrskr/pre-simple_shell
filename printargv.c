#include <stdio.h>

int main(int argc __attribute__((unused)), char **argv)
{
	int i = 0;

	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}
}
