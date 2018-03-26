#include <signal.h>
#include <errno.h>

/**
 * pid_exist - checks if a PID exists
 *
 * @pid: the process id
 *
 * Return: 1 if it exists, 0 if it does not.
 */
int pid_exist(pid_t pid)
{
	return ( !((kill(pid, 0) == -1) && (errno == ESRCH)) );
}
