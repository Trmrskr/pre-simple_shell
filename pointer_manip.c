#include <stdio.h>

int main(void)
{
	char *line = "abcdefghijklmnopqrstuvwxyz";
	int i = 0;

	while (i < 4)
	{
		printf("%c", *line);
		line++;
		i++;
	}
	
	printf("\n%c", *line);
	printf("\n%c", line[3]);
	printf("\n%c", *line + 3);
	printf("\n");	
	return (0);
}
