#include <unistd.h>

static char pf_hex(char c)
{
  if ( c <= 9 )
    c += '0';
  else if ( c <= 15 )
    c += 'W'; // 'W' is 'a' - 10
  else //Error : c >= 16
    c = '?';
  return c;
}

static void pf_writeHex(char c)
{
  char toPrint[3] = { 0x5c, 0x5c, 0x5c }; // "\\\"
  toPrint[1] = pf_hex(c / 16);
  toPrint[2] = pf_hex(c % 16);
  for (int i = 0; i < 3; i++)
    if (write(1, &toPrint[i], 1)) {}
}

static int pf_isPrintable(char c)
{
  return ( ( c >= 0x20 ) && ( c <= '~' ) );
}

void ft_putstr_non_printable(char *str)
{
  char c = *str;
  while (c != 0)
    {
      if ( pf_isPrintable(c) ) {
	if (write (1, &c, 1)) {}
      } else {
	pf_writeHex(c);
      }
      c = *(++str);
    }
}
