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

#endif
