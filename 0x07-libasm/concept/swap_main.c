#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void swap(int *a, int *b);

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

  if (argc < 3)
    {
      dprintf(STDERR_FILENO, "Usage: %s <a> <b>\n", argv[0]);
      return (EXIT_FAILURE);
    }

  a = atoi(argv[1]);
  b = atoi(argv[2]);

  printf("Before: a = %d, b = %d\n", a, b);

  swap(&a, &b);

  printf("After: a = %d, b = %d\n", a, b);

  return (EXIT_SUCCESS);
}
