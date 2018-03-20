#include "signals.h"

/* include prototype */
void print_hello(int);

/**
 * current_handler_signal - gets the handler of the signal
 *
 * Return: The address of the handler function.
 */
void (*current_handler_signal(void))(int signum)
{
	typedef void (*sighandler_t)(int);
	sighandler_t curr = NULL;

	curr = signal(SIGINT, print_hello);

	return (curr);
}
