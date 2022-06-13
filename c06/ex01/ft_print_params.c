#include <unistd.h>

void pf_writeArg(char *arg)
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
// returns number of params (except program name)
{
  if (argc == 1) return 0;
  for (int i = 1; i < argc; i++)
    {
      char *arg = argv[i];
      pf_writeArg(arg);
    }
  return argc - 1;
}
