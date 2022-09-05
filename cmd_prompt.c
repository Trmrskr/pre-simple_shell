#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	ssize_t nread;
	char *line = NULL;
	size_t len = 0;

	printf("$: ");
	nread = getline(&line, &len, stdin);

	while (nread != -1)
	{
		printf("%s", line);
		printf("$: ");
		nread = getline(&line, &len, stdin);
	}

	putchar('\n');

	free(line);
	fclose(stdin);

	return (0);
}
