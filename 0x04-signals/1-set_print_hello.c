#include "signals.h"

/**
 * print_hello - prints "Hello :)" and ignores the parameter
 *
 * @signum: this parameter holds the number associated with the signal.
 *
 * Return: Nothing.
 */
void print_hello(int signum __attribute__((unused)))
{
	printf("Hello :)\n");
}

/**
 * set_print_hello - this sets the signal to print_hello
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
