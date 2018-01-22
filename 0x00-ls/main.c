#include <stdio.h>
#include <dirent.h>

/**
 * main - entry point for ls.
 */
int main(void)
{
	DIR *dir;
	struct dirent *read;
	
	dir = opendir(".");

	read = readdir(dir);
	while (read != NULL)
	{
		printf("%s\n", read->d_name);
		read = readdir(dir);
	}

	closedir(dir);

	return (0);
}
