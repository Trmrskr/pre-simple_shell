#include <string.h>
#include <stdio.h>

int main(void)
{
	char str[] = "This is the ./meningi, ./sanaga and ./abalo";
	char *token = NULL;

	token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, "./");
	}
	return (0);
}
