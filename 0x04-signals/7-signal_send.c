#include "signals.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

/**
 * main - Sends the signal SIGINT to a given process PID
 *
 * @argc: number of arguments
 * @argv: the argument vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	int n = 0; char *endptr = NULL;

	errno = 0;
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	n = strtol(argv[1], &endptr, 10); /* man strtol is complex */
	if (errno != 0 || endptr == argv[1] || *endptr != '\0')
		return (EXIT_FAILURE);
	kill(n, SIGINT);
	return (EXIT_SUCCESS);
}
