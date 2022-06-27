#include <unistd.h>

static void pf_writeArg(char *arg)
{
  char toWrite = *arg;
  while ( toWrite != 0 )
    {
      write(1, &toWrite, 1);
      arg ++;
      toWrite = *arg;
    }
  write(1, "\n", 1);
}
static int pf_strcmp(char *s1, char *s2)
{
  char result = *s1 - *s2;
  while (result == 0)
    {
      if ((*s1 == 0) || (*s2 == 0))
	return (int)(*s1 -*s2);
      result = *s1++ - *s2++;
    } 
  return (int)result;
}

static void pf_insertion_sort(char **args, int size)
{
  for (int i = 0; i < size; i++)
    {
      char *currentArg = args[i];
      int currentLeftIndex = i - 1;
      while ((currentLeftIndex >= 0) &&
	     (pf_strcmp(args[currentLeftIndex], currentArg) > 0))
	{
	  args[currentLeftIndex + 1] = args[currentLeftIndex];
	  currentLeftIndex --;
	}
      args[currentLeftIndex + 1] = currentArg;
    }
}

int main(int argc, char **argv)
// returns number of params (except program name)
{
  if (argc == 1) return 0;
  char* sortedArgs[argc-1]; // allocate tab of indexes for triage
  for (int i = 1; i < argc; i ++)
    sortedArgs[i - 1] = argv[i];
  pf_insertion_sort(sortedArgs, argc -1);
  for (int i = 1; i < argc; i++)
    {
      char *arg = sortedArgs[i - 1];
      pf_writeArg(arg);
    }
  return argc - 1;
}
