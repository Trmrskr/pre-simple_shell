#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_to_cmd(char *line, char **cmdline);

int main(void)
{
	
	int i = 0;
	char *cmd[4];
	char line[] = "/src/bin/ls -a /tmp";

	parse_to_cmd(line, cmd);

	while (cmd[i] != NULL)
	{
		printf("%s\n", cmd[i]);
		i++;
	}
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
