#include <unistd.h>

void ft_print_comb(void)
{
  char space = ' ';
  char virg = ',';
  char triplet[3] = "000";
  for (char i = '0'; i <= '7'; i++)
  {
    triplet[0] = i;
    for (char j = i + 1; j <= '8' ; j++)
    {
      if (j != i)
        triplet[1]  = j;
      for (char k = j + 1; k <= '9' ; k++)
      {
        if (k != i && k != j)
        {
          triplet[2] = k;
          for (int c = 0; c <= 2; c++)
            write(1, &triplet[c], 1);
          if (triplet[0] != '7')
          {
            write(1, &virg, 1);
            write(1, &space, 1);
          }
        }
      }
    }
  }
}
