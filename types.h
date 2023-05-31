#pragma once

#include <stdint.h>

typedef struct {
  char** pkg;
  uint8_t flags;
} Servant;

enum {
  FLAG_INSTALL =   0b00000001,
  FLAG_BUILD =     0b00000010,
  FLAG_FETCH =     0b00000100,
  FLAG_VERBOSE =   0b00001000,
  FLAG_CHECK =     0b00010000,
  FLAG_LOCAL =     0b00100000,
  FLAG_VERSION =   0b01000000,
};

enum {
  NOTFOUND=1,
  NOTAFOLDER,
  NOBUILD,
  NOINSTL,
};
