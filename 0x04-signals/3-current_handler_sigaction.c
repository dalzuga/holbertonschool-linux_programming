#include "signals.h"

/**
 * current_handler_sigaction - return the current handler using sigaction
 *
 * Return: The address of the handler function, or NULL on error.
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction sa;

	if (sigaction(SIGINT, NULL, &sa) == -1)
		return (NULL);

	return (sa.sa_handler);		/* return the address */
}
