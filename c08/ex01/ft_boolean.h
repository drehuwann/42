#ifndef _FT_BOOLEAN_H_
#define _FT_BOOLEAN_H_

#include <unistd.h>

#define EVEN(nb) ((nb % 2) == 0)
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"

typedef enum
  {
    TRUE,
    FALSE
  } t_bool;

#define SUCCESS 0

#endif  // _FT_BOOLEAN_H_
