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

	while ((read = readdir(dir)) != NULL)
	{
		printf("%s\n", read->d_name);
	}

	closedir(dir);

	return (0);
}
