#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>		/* signal(2) */

/* handle_signal - handles a signal */
int handle_signal(void);

/* interrupt_handler - function called upon receiving a signal */
void interrupt_handler(int signum);

/* current_handler_signal - gets the handler of the signal */
void (*current_handler_signal(void))(int);

/* handle_sigaction - sets a handler for SIGINT */
int handle_sigaction(void);

/* interrupt_handler2 - function called upon receiving a signal */
void interrupt_handler2(int signum);

/* current_handler_sigaction - return the current handler using sigaction */
void (*current_handler_sigaction(void))(int);

/* trace_signal_sender - returns the PID of the SIGQUIT sending process */
int trace_signal_sender(void);

/* handler_print_pid - a handler that prints information */
void handler_print_pid(int signum, siginfo_t *si, void *unused);

#endif
