const char ULcorner = '/';
const char URcorner = '\\';
const char DLcorner = '\\';
const char DRcorner = '/';
const char horline = '*';
const char verline = '*';
const char inner = ' ';
const char eol = '\n';

void ft_putchar(char c);

void printline(int size, const char triplet[3]) {
  if (size < 1) return;
  int it = 0;
  char c;
  while (it < size) {
    if (it == 0) {
      c = triplet[0];
    } else if (it == (size - 1)) {
      c = triplet[2];
    } else {
      c = triplet[1];
    }
    ft_putchar(c);
    ++ it;
  }
  ft_putchar(eol);
}

void rush(int x, int y) {
  int it = 0;
  char triplet[3];
  while (it < y) {
    if (it == 0) {
      triplet[0] = (char)ULcorner;
      triplet[1] = (char)horline;
      triplet[2] = (char)URcorner;
    } else if (it == y - 1) {
      triplet[0] = (char)DLcorner;
      triplet[1] = (char)horline;
      triplet[2] = (char)DRcorner;
    } else {
      triplet[0] = (char)verline;
      triplet[1] = (char)inner;
      triplet[2] = (char)verline;
    }
    printline(x, triplet);
    ++ it;
  }
}
