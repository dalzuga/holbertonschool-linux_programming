#include "signals.h"

/**
 * handle_signal - handles a signal
 *
 * Return: Returns 0 on success, -1 on error.
 */
int handle_signal(void)
{
	if (signal(SIGINT, interrupt_handler) == SIG_ERR)
	{
		perror("signal");
		return (-1);
	}

	return (0);
}

/**
 * interrupt_handler - function called upon receiving a signal
 *
 * @signum: the signal number passed
 *
 * Return: Nothing.
 */
void interrupt_handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}
