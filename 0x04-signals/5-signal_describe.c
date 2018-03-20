#include "signals.h"
#include <string.h>

/**
 * main - this program describes the signal passed as an argument
 *
 * @argc: number of arguments
 * @argv: the argument vector
 *
 * Return: EXIT_SUCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char **argv)
{
	sigset_t set;

	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	sigfillset(&set);
	if (sigismember(&set, atoi(argv[1])))
		printf("%d: %s\n", atoi(argv[1]), strsignal(atoi(argv[1])));
	return (EXIT_SUCCESS);
}
