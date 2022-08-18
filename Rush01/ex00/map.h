/// @file map.h
#ifndef _MAP_H_
#define _MAP_H_

/// size of a line in t_map
#define MAPSIZE 4

/// EMPTYCHAR should be < 0x31 (eq. '1')
#define EMPTYCHAR 0x2e

typedef struct {
  short int x;
  short int y;
} t_coord;

/*! @brief returns a t_coord from two shorts. */
t_coord coords(short int x, short int y);

/*! @brief the 1st index is y, the 2nd is x */
typedef char t_map[MAPSIZE][MAPSIZE];

/*! @brief array of pointers on map elements to hold any line in map.*/
typedef char *t_line[MAPSIZE];

/*! @brief the point from where we view lines */
typedef enum {
  up,
  down,
  left,
  right
} t_pov;

/*! @brief allocates a t_map, filled with EMPTYCHARs */
t_map *map_create();

/*! @brief allocates a t_map, copy map into it */
t_map *mapdup(const t_map *map);

/*! @brief allocates a t_map from arg.
 *  filled as {y{1..n}up, y{1..n}down, x{1..n}left, x{1..n}right} 
 *  @return a pointer on this allocated line; NULL if arg is invalid */
t_map *arg2map(const char *arg);

/*! @brief puts c at coord in map*/
void map_fill_at(t_map *map, const t_coord coord, const char c);

/*! @brief returns char at coord in map */
char map_read_at(const t_map *map, const t_coord coord);

/*! @brief allocates a t_line = num'th line seen from pov, in map. 
 *  @return a pointer on this allocated line; NULL on error */
t_line *get_line(const t_map *map, t_pov pov, short int num);

/*! @brief returns the number of seen boxes, looking at line from line[0].
 * @return -1 on error */
int seen(t_line *p_line);

/*! @brief fullfills 'seen_map' with 'seen' values of 'map'. seen_map is 
 * ordered such as arg2map() */
void seen2map(t_map *const seen_map, const t_map *const map);
#endif  //_MAP_H_
