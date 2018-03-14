#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h> 		/* signal(2) */

/* handle_signal - handles a signal */
int handle_signal(void);

/* interrupt_handler - function called upon receiving a signal */
void interrupt_handler(int signum);

#endif
