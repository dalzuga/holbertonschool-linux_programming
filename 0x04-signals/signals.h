#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h> 		/* signal(2) */

int handle_signal(void);
void interrupt_handler(int signum);

#endif
