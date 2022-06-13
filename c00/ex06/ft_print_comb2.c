#include <unistd.h>

void ft_print_comb2(void)
{
  char space = ' ';
  char virg=',';
  char couplet[5] = "00 00";
  for (char i = '0'; i <= '9'; i++)
  {
    couplet[0] = i;
    for (char j = '0'; j <= '9' ; j++)
    {
      couplet[1] = j;
      couplet[2] = space;
      for (char k = i; k <= '9' ; k++)
      {
        couplet[3] = k;
        for (char l = j + 1; l <= '9' ; l++)
        {
          couplet[4] = l;
          for (int c = 0; c <= 4; c++)
            if (write(1, &couplet[c], 1)) {}
          if ( ! (couplet[1] == '8' && couplet[0] == '9') )
          {
            if (write(1, &virg, 1)) {}
            if (write(1, &space, 1)) {}
          }
        }
      }
    }
  }
}
