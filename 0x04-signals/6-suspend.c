#include "signals.h"

/**
 * main - this program waits for SIGINT to be called and prints information.
 *
 * Return: EXIT_SUCESS on success, EXIT_FAILURE on failure.
 */
int main(void)
{
	struct sigaction sa;

	sa.sa_handler = handler_print_caught;

	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (EXIT_FAILURE);

	pause();

	return (EXIT_SUCCESS);
}

/**
 * handler_print_caught - a handler that prints information
 *
 * @signum: signal number
 */
void handler_print_caught(int signum)
{
	printf("Caught %d\nSignal received\n", signum);
}
