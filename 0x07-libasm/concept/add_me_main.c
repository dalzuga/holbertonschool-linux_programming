#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int add_me(int a, int b);

/**
 * main - Program entry point
 * @argc: Arguments counter
 * @argv: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, const char *argv[])
{
  int a;
  int b;
  int res;

  if (argc < 3)
    {
      dprintf(STDERR_FILENO, "Usage: %s <a> <b>\n", argv[0]);
      return (EXIT_FAILURE);
    }

  a = atoi(argv[1]);
  b = atoi(argv[2]);
  res = add_me(a, b);

  printf("%d + %d = %d\n", a, b, res);

  return (EXIT_SUCCESS);
}
