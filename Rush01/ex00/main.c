#include "./map.h"
#include "./display.h"

#include <stdlib.h>

int main(int argc, char **argv) {
  t_map *mapArgs = (t_map *)0;
  if (argc != 2 || (mapArgs = arg2map(argv[1])) == (t_map *)0) {
    err();
    return -1;
  }
  displaystr("args map :\n");
  displaymap(mapArgs);
  t_map *resultMap = map_create();
  seen2map(resultMap, mapArgs);
  displaystr("seen map :\n");
  displaymap(resultMap);
  if (resultMap) free(resultMap);
  if (mapArgs) free(mapArgs);
}
