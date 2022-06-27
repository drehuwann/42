#include <unistd.h>

static void pf_writeArg(char *arg)
{
  char toWrite = *arg;
  while ( toWrite != 0 )
    {
      if (write(1, &toWrite, 1)) {}
      arg ++;
      toWrite = *arg;
    }
  if (write(1, "\n", 1)) {}
}

int main(int argc, char **argv)
{
  char *arg = argv[0];
  pf_writeArg(arg);
  return argc;
}
