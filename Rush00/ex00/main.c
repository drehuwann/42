typedef struct {
  int x;
  int y;
} intpair;

void rush(int x, int y);

/*! @brief make int from string.
 * @returns -1 on error */
static int stoi(const char *s) {
  char c;
  int toRet = 0;
  while ((c = (char)(*s)) != 0) {
    if (c < '0' || c >'9') return -1;
    toRet *= 10;
    toRet += (c - '0');
    ++ s;
  }
  return toRet;
}

int main(int argc, char **argv) {
  intpair area;
  area.x = 5;
  area.y = 3;
  if (argc == 3) {
    int it = 0;
    while (it < 2) {
      int ret = stoi((const char *)(argv[it + 1]));
      if (ret > 0) {
	if (it == 0) {
	  area.x = ret;
	} else {
	  area.y = ret;
	}
      }
      ++it;
    }
  }
  rush(area.x, area.y);
  return (0);
}
