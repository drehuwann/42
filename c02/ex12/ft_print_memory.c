#include <unistd.h>

char pf_Hex(unsigned char c)
{
  if ( c <= 9 )
    c += '0';
  else if ( c <= 15 )
    c += 'W'; // 'W' is 'a' - 10
  else //Error : c >= 16
    c = '?';
  return c;
}

void pf_printByte(unsigned char c)
{
  char toPrint[2] = "00";
  toPrint[1] = pf_Hex(c % 16);
  toPrint[0] = pf_Hex(c / 16);
  for (int i = 0; i < 2; i++)
    write(1, &toPrint[i], 1);
}

void pf_printAddr(unsigned long long ull)
{
  char toPrint[16] = "0000000000000000";
  for (int i = 15; i >= 0; i--)
    {
      toPrint[i] = pf_Hex(ull % 16);
      ull /= 16;
    }
  for (int i = 0; i < 16; i++)
    write(1, &toPrint[i], 1);
}

void pf_printDumpLine(void *addr, unsigned int size)
{
  if (size == 0)
    return;
  unsigned char charToWrite = 0 ;
  unsigned char *savAddr= (unsigned char*)addr;
  pf_printAddr((unsigned long long)addr);
  write(1, ":", 1);
  write(1, " ", 1);
  for (unsigned int i = 0; i < size; i ++)
    {
      pf_printByte( *((unsigned char*)addr) );
      if ( i % 2 != 0 )
	write(1, " ", 1);
      (unsigned char*)addr ++;
    }
  if ( size < 16 )
    {
      // Pads with spaces to next double byte
      int nbPads = 5 - ( 2 * (size % 2) );
      for (int i = 0; i < nbPads; i ++)
	write(1, " ", 1);
    }
  for (unsigned int i = 0; i < size; i ++)
    {
      charToWrite = savAddr[i];
      if ( (charToWrite < ' ') || (charToWrite > '~') )
	charToWrite = '.';
      write(1, &charToWrite, 1);
    }
  write (1, "\n", 1);
}

void *ft_print_memory(void *addr, unsigned int size)
{
  void *savAddr = addr;
  unsigned int lineSize = 16;
  unsigned int nbFullLines = size / 16;
  while (nbFullLines --)
    {
      pf_printDumpLine(addr, lineSize);
      addr += lineSize;
    }
  pf_printDumpLine(addr, size % 16);
  return savAddr;
}
