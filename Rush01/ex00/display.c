#include "./display.h"

#include <unistd.h>

static void putchr(char c) {
  if (write(1, &c, 1)) {}
}

static void print(const char *s) {
  char c;
  while((c = *s)) {
    if (write(1, &c, 1)) {}
    ++s;
  }
}

void err() {
  print("Error\n");
}

void displaymap(const t_map *map) {
  short int ity = 0;
  t_coord coords;
  while (ity < MAPSIZE) {
    short int itx = 0;
    while (itx < MAPSIZE) {
      coords.x = itx;
      coords.y = ity;
      putchr(map_read_at(map, coords));
      putchr(0x20);
      ++ itx;
    }
    putchr('\n');
    ++ ity;
  }
}

void displaystr(const char *s) {
  print(s);
}

