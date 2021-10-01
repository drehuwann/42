#include <unistd.h>

#define N_MAX 10

#ifdef _DEBUG
//* macro BreakPoint
#define MBP __asm__("int $3");
#else
#define MBP
#endif //_DEBUG


//* null_kPlet is defined as {0x00,0x00,..,0x00}
//* returns 1 if kPletIsNull, else returns 0
//* k is the size of kPlet
int pf_kplet_isNull(int k, char *kPlet)
{
  for (int i = 0; i < k; i++)
    if (kPlet[i] != 0)
      return 0;
  return 1;
}

/** n is the N of parmiN; if *kPlet==NULL => computes the first kPlet
 returns 0 if computed nPlet is not the last.
 assertion : input kplet must verify for any n :
 (n >= kPlet[n] > *kPlet[n-1] >= 1) **/
int pf_nextKplet(char n, char k, char *kPlet)
{
  char m = 0; // holds one element parmi n
  char h = 0; // index of the element in kPlet (from right to left)
  if ( pf_kplet_isNull( (int)k, kPlet ) ) // no previous kPlet
  {
    MBP
  m = 0;
    h = k;
  }
  else
  {
    if ( kPlet[0] > n - k ) // last kPlet inputted
      return -1; // prevents crash in the while loop.
    h = 0;
    do
    {
      h ++;
      m = kPlet[k - h];
    } while (m > n - h);
  }
  for (int j = 0; j < h; j++)
  {
    kPlet[k + j - h] = m + j + 1;
  }
  return (kPlet[0] > n - k); 
}

// Public function
void ft_print_combn(int n)
{
  typedef char k_plet[n];
  const char space = ' ';
  const char virg = ',';

  //* Assertion
  if ( ( n <= 0 ) || ( n >= N_MAX ) )
    return;

  //* Allocations
  k_plet nullKplet;
  for (int i = 0; i < n; i++)
    nullKplet[i] = 0; // Set initial k_plet full of zeros
  k_plet *pKplet = &nullKplet;
  char charToWrite = '\0';
  int returnCode = 0;

  do 
    {
      returnCode = pf_nextKplet(N_MAX, (char)n, (char*)pKplet);
      // Ecriture resultats en console
      for (int c = 0; c < n; c++)
      {
	charToWrite = '0' - 1 + nullKplet[c];
	write(1, &charToWrite, 1);
      }
      if ( ! returnCode )
	{
	  write(1, &virg, 1);
	  write(1, &space, 1);
	}
    } while ( ! returnCode );
}
