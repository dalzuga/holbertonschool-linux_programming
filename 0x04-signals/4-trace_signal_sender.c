#include "signals.h"

/**
 * trace_signal_sender - returns the PID of the SIGQUIT sending process
 *
 * Return: 0 on success, -1 on error.
 */
int trace_signal_sender(void)
{
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler_print_pid;

	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		return (-1);

	return (0);
}

/**
 * handler_print_pid - a handler that prints information
 *
 * @signum: signal number
 * @si: pointer to siginfo_t struct
 * @unused: an unused pointer
 */
void handler_print_pid(int signum __attribute__((unused)), siginfo_t *si,
		     void *unused __attribute__((unused)))
{
	printf("SIGQUIT sent by %d\n", si->si_pid);
}
