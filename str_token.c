#include <stdlib.h>
#include <stdio.h>

int is_delim(char c, const char *delim);
char *_strtok(char *str, const char *delim);

int main(void)
{
/*	char *str = "Betty Butter Bought Some butter";*/
	char str[] = " This is the ./meningi, ./sanaga and ./abalo";
	char *token = NULL;

	token = _strtok(str, ".");
/*	token = _strtok(NULL, " ");
	printf("%s\n", token);
	token = _strtok(NULL, " ");
	printf("%s\n", token);
	token = _strtok(NULL, " ");
	printf("%s\n", token);
	token = _strtok(NULL, " ");
	printf("%s\n", token);
	token = _strtok(NULL, " ");

	if (token != NULL)
		printf("%s\n", token);
	else
		printf("%s\n", "NILL");*/

	while (token != NULL)
	{
		printf("%s\n", token);
		token = _strtok(NULL, ".");
	}
	return (0);
}

/**
 * _strtok - a function that tokenizes a string
 * @str: string to be tokenized
 * @delim: the delimiter with which to tokenize the string
 * Return: a string
 * Description - Do not fail to free memory after return.
 */

char *_strtok(char *str, const char *delim)
{
	static char *line;
	char *token = NULL;
	int len = 0, i = 0, letter_flag = 1;

	if (str != NULL)
		line = str;
	if (line == NULL || *line == '\0')
		return (NULL);

	while (is_delim(line[len], delim) != 1 && line[len] != '\0')
		len++;

	token = malloc(sizeof(char) * (len + 1));

	if (token == NULL)
		return (NULL);

	while (*line)
	{

		if (is_delim (*line, delim) != 1)
		{
			if (letter_flag == 0)
				break;
			token[i] = *line;
		}
		else
		{
			letter_flag = 0;
			*line = '\0';
		}

		line++;
		i++;
	}
	return (token);
}


/**
 * is_delim - check if character is a delim
 * @c: character to be checked
 * @delim: the delimiters to check against the characters.
 * Return: 1 if successful, 0 otherwise
 */

int is_delim(char c, const char *delim)
{
	int i = 0;

	while (delim[i])
	{
		if (delim[i] == c)
			return (1);
		i++;
	}

	return (0);
}
