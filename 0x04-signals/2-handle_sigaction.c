#include "signals.h"

/**
 * handle_sigaction - sets a handler for SIGINT
 *
 * Return: -1 on failure, 0 on success.
 */
int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_handler = interrupt_handler2;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (-1);

	return (0);
}

/**
 * interrupt_handler2 - function called upon receiving a signal
 *
 * @signum: the signal number passed
 *
 * Return: Nothing.
 */
void interrupt_handler2(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}
