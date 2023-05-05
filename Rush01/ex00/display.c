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
  t_coord coor;
  while (ity < MAPSIZE) {
    short int itx = 0;
    while (itx < MAPSIZE) {
      coor.x = itx;
      coor.y = ity;
      putchr(map_read_at(map, coor));
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

