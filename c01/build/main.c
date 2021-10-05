#include <unistd.h>

#include "./protos.h"
void pf_test42(int i)
{
  if ( i == 42 )
    write(1, "Y", 1);
  else
    write(1, "N", 1);
  write(1, "\n", 1);
}
void pf_testArrayOfInt()
{
  int a1[8] = {7, 6, 5, 4, 3, 2, 1, 0};
  int a2[9] = {16, 14, 12, 10, 8, 6, 4, 2, 0};
  ft_rev_int_tab(a1, 8);
  for (int k = 0; k < 8; k++)
    {
      if (a1[k] == k)
	write(1, "Y", 1);
      else
	write(1, "N", 1);
    }
  write(1, "\n", 1);
  ft_rev_int_tab(a2, 9);
  for (int k = 0; k < 9; k++)
    {
      if (a2[k] == 2 * k)
	write(1, "Y", 1);
      else
	write(1, "N", 1);
    }  
  write(1, "\n", 1);
}

int main()
{
  int i = 0;
  ft_ft(&i);
  pf_test42(i);
  i = 0;
  void *pOnSomething[9];
  pOnSomething[0] = (void*)&i;
  for (int k = 1; k < 9; k++)
    {
      pOnSomething[k] = (void*)&pOnSomething[k -1];
    }
  int *********superPtr = (int*********)pOnSomething[8];
  ft_ultimate_ft(superPtr);
  pf_test42(i);
  int a = 0xcafebabe;
  i = 0x0badb002;
  ft_swap(&a, &i);
  if ( (a == (int)0x0badb002) && (i == (int)0xcafebabe) )
    pf_test42(42);
  else
    pf_test42(-42);
  ft_div_mod(3042, 1000, &a, &i);
  if ( a == 3 )
    pf_test42(i);
  else
    pf_test42(-42);
  a = 424242;
  i = 100;
  ft_ultimate_div_mod(&a, &i);
  if ( a == 4242 )
    pf_test42(i);
  else
    pf_test42(-42);
  ft_putstr("Test de ft_putstr ...\n");
  ft_putstr("");
  ft_putstr("Ok ");
  ft_putstr("!\n");
  char* str = "Quarante-deux=Trois.Quatorze=Quarante-deux";
  i = ft_strlen(str);
  pf_test42(i);
  pf_test42(ft_strlen("") + 42); // Test (strlen(nullString) == 0)
  ft_putstr("Tests tableaux pairs et impairs ...\n");
  pf_testArrayOfInt();
}                           
