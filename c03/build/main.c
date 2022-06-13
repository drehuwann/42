#include <unistd.h>

#include "./protos.h"

void pf_test42(int i)
{
  if ( i == 42 ) {
    if (write(1, "Y", 1)) {}
  } else {
    if (write(1, "N", 1)) {}
  }
  if (write(1, "\n", 1)) {}
}

int main()
{
  pf_test42(42 + ft_strcmp("abcdefg","abcdefg"));
  pf_test42(10 + ft_strcmp("1bcdef 123", "1bcdef"));
  pf_test42(74 + ft_strcmp("bcd", "bcd 123"));
  pf_test42(43 + ft_strcmp("bcdefY", "bcdefZ"));
  pf_test42(42 + ft_strncmp("abcdefg","abcdefg", 10));
  pf_test42(42 + ft_strncmp("1bcdef 123", "1bcdef", 6));
  pf_test42(74 + ft_strncmp("bcd", "bcd 123", 4));
  pf_test42(42 + ft_strncmp("bcdefY", "bcdefZ", 5));
  char s[20] ="1234567890-qwertyui";
  char s1[20]="1234567890-";
  char s2[9] =           "qwertyui";
  pf_test42(42 + ft_strcmp(s, ft_strcat(s1, s2)));
  char s3[20]="1234567890-"; 
  pf_test42(42 + ft_strcmp(s, ft_strncat(s3, "qwertyuiop[]", 8)));
  pf_test42(42 + ( ft_strstr(s2, "jklmn") != 0));
  pf_test42(39 + (int)(ft_strstr(s2, "rtyu") - s2));
  char s4[16]="abraracour";
  char s5[20]="cixFoisTroisDixHuit";
  pf_test42(13 + (int)(ft_strlcat(s4, s5, 14)));
  pf_test42(42 + ft_strcmp("abraracourcix", s4));
}                           
