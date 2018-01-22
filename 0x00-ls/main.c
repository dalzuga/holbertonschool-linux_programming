#include <stdio.h>
#include <dirent.h>

/**
 * main - entry point for ls.
 */
int main(void)
{
	DIR *dir;
	struct dirent *read;
	int tmp;
	
	dir = NULL;
	read = NULL;
	tmp = 0;

	dir = opendir(".");
	if (dir == NULL)
	{
		perror("ls");
		return (1);
	}

	read = readdir(dir);
	while (1)
	{
		if (read == NULL)
			break;

		printf("%s\n", read->d_name);
		read = readdir(dir);
		if (read == NULL)
			break;
	}

	tmp = closedir(dir);

	if (tmp == -1)
	{
		perror("closedir");
		return (1);
	}

	return (0);
}
