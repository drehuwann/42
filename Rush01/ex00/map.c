#include "./map.h"

#include <stdlib.h>

t_coord coords(short int x, short int y) {
  t_coord toRet;
  toRet.x = x;
  toRet.y = y;
  return toRet;
}

t_map *map_create() {
  char c = EMPTYCHAR;
  t_map *toRet = (t_map *)malloc(sizeof(t_map));
  if (toRet) {
    int it = 0;
    while (it < MAPSIZE * MAPSIZE) {
      ((char *)toRet)[it] = c;
      ++ it;
    }
  }
  return toRet;
}

t_map *mapdup(const t_map *map) {
  t_map *toRet = (t_map *)0;
  if (map) {
    toRet = map_create();
    int it = 0;
    while (it < MAPSIZE * MAPSIZE) {
      ((char *)toRet)[it] = ((char*)map)[it];
      ++ it;
    }
  }
  return toRet;
}

t_map *arg2map(const char *arg){
  t_map localMap;
  if (!arg) return (t_map *)0;
  int itx = 0;
  int ity = 0;
  while (ity < MAPSIZE) {
    while (itx < MAPSIZE) {
      int itstring = 2 * (ity * MAPSIZE + itx);
      int itstringplus2 = itstring + 2;
      while (itstring < itstringplus2) {
        char c = arg[itstring];
        if (itstring % 2 == 0) {
          if (c < '1' || c > ('0' + MAPSIZE)) return (t_map *)0;
          localMap[ity][itx] = c;
        } else {
	        if (itstring < (2 * MAPSIZE * MAPSIZE - 1) &&
              c != 0x20) return (t_map *)0;
	        if (itstring == (2 * MAPSIZE * MAPSIZE - 1) &&
              c != 0x00) return (t_map *)0;
        }
        ++itstring;
      }
      ++ itx;
    }
    itx = 0;
    ++ ity;
  }
  return mapdup(&localMap);
}

void map_fill_at(t_map *map, const t_coord coord, const char c) {
  if (map) {
    (*map)[(int)(coord.y)][(int)(coord.x)] = c;
  }
}

char map_read_at(const t_map *map, const t_coord coord) {
  char toRet = 0;
  if (map) {
    toRet = (*map)[(int)(coord.y)][(int)(coord.x)];
  }
  return toRet;
}

t_line *get_line(const t_map *map, t_pov pov, short int num) {
  if (!map || num >= MAPSIZE) return (t_line *)0;
  t_line *toRet = (t_line *)malloc(sizeof(t_line));
  int it = 0;
  if (pov == up) {
    while (it < MAPSIZE) {
      (*toRet)[it] = (char *)&((*map)[it][(int)num]);
      ++ it;
    }
  } else if (pov == down) {
    while (it < MAPSIZE) {
      (*toRet)[it] = (char *)&((*map)[MAPSIZE - 1 - it][(int)num]);
      ++ it;
    }
  } else if (pov == left) {
    while (it < MAPSIZE) {
      (*toRet)[it] = (char *)&((*map)[(int)num][it]);
      ++ it;
    }
  } else { // pov == right 
    while (it < MAPSIZE) {
      (*toRet)[it] = (char *)&((*map)[(int)num][MAPSIZE - 1 - it]);
      ++ it;
    }
  }
  return toRet;
}

int seen(t_line *p_line) {
  if (!p_line) return -1;
  char tallest_seen = EMPTYCHAR;
  char current_char = EMPTYCHAR;
  int toRet = 0;
  int it = 0;
  while (it < MAPSIZE &&
	 ((current_char = *((*p_line)[it])) < ( '1' + MAPSIZE))) {
    if (current_char > tallest_seen) {
      ++ toRet;
      tallest_seen = current_char;
    }
    ++ it;
  }
  if (p_line) free(p_line);
  return toRet;
}

void seen2map(t_map *const seen_map, const t_map *const map) {
  if (!seen_map || !map) return;
  t_pov itpov = up;
  while (itpov < 4) {
    short int it = 0;
    while(it < MAPSIZE) {
      (*seen_map)[itpov][(int)it] = '0' + seen(get_line(map, itpov, it));
      ++ it;
    }
    ++ itpov;
  }
}
