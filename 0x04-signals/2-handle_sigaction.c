#include "signals.h"

/**
 * handle_sigaction - sets a handler for SIGINT
 *
 * Return: -1 on failure, 0 on success.
 */
int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_handler = print_hello2;
}

/**
 * print_hello2 - prints "Hello :)" and ignores the parameter
 *
 * @signum: this parameter holds the number associated with the signal.
 *
 * Return: Nothing.
 */
void print_hello2(int signum __attribute__((unused)))
{
	printf("Hello :)\n");
}
