#include "signals.h"

/**
 * current_handler_signal - gets the handler of the signal
 *
 * @signum: the signal number.
 *
 * Return: Nothing.
 */
void (*current_handler_signal(void))(int signum)
{
	return (signal(SIGINT, SIG_DFL));
}
