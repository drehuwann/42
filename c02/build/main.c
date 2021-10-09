#include <unistd.h>
#include <string.h>

#include "./protos.h"

void pf_test42(int i)
{
  if ( i == 42 )
    write(1, "Y", 1);
  else
    write(1, "N", 1);
  write(1, "\n", 1);
}

int main()
{
  char *strSrc = "Quarante-deux=Trois.Quatorze=Quarante-deux";
  char strDst[43] = "..........................................";
  int i = strcmp(ft_strcpy(strDst, strSrc), strSrc);
  pf_test42(42 + i);
  char *stSrc="42";
  i = strcmp(ft_strncpy(strDst, stSrc, 13), "42");
  pf_test42(42 + i);
  i = 42;
  for (int k = 2; k < 13; k++) // Check trailing Zeroes
    i += strDst[k];
  pf_test42(i);
  i = ft_str_is_alpha("rastapopoulos");
  pf_test42(41 + i);
  i = ft_str_is_alpha("");
  pf_test42(41 + i);
  i = ft_str_is_alpha("rastarocket2");
  pf_test42(42 + i);
  i = ft_str_is_numeric("4894521574");
  pf_test42(41 + i);
  i = ft_str_is_numeric("");
  pf_test42(41 + i);
  i = ft_str_is_numeric("rastarocket2");
  pf_test42(42 + i);
  i = ft_str_is_lowercase("rootadmin");
  pf_test42(41 + i);
  i = ft_str_is_lowercase("");
  pf_test42(41 + i);
  i = ft_str_is_lowercase("marvIn");
  pf_test42(42 + i);
  i = ft_str_is_uppercase("HNFJKBVHWEFJKL");
  pf_test42(41 + i);
  i = ft_str_is_uppercase("");
  pf_test42(41 + i);
  i = ft_str_is_uppercase("MARVIn");
  pf_test42(42 + i);
  i = ft_str_is_printable("~!@#$%^&*()_+");
  pf_test42(41 + i);
  i = ft_str_is_printable("");
  pf_test42(41 + i);
  i = ft_str_is_printable("rasta\tpopoulos"); // \t = \0x09 = TABul.
  pf_test42(42 + i);
  i = ft_str_is_printable("rasta\\totoulos"); // \t = \0x09 = TABul.
  pf_test42(41 + i);
  char str[16] = "azErtyUIoP!@#$%";
  pf_test42(42 + strcmp(ft_strupcase(str), "AZERTYUIOP!@#$%"));
  pf_test42(42 + strcmp(ft_strlowcase(str), "azertyuiop!@#$%"));
  char s1[62] ="salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
  char s2[62] ="Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un";
  char *ret = ft_strcapitalize(s1);
  pf_test42(42 + strcmp(ret, s2));
  char s3[10] = ".........";
  pf_test42(sizeof(s2) - ft_strlcpy(s3, s2, 6) + 41);
  pf_test42(42 + strcmp("Salut\0", s3));
  ft_putstr_non_printable("Coucou\ntu vas bien ?");
  write (1, "\n", 1);

  ft_print_memory((void*)strSrc, 249);
}                           
