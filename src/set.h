#pragma once

#include "utils.h"

#define SET_BRIGHT 1
#define SET_COMMA (1 << 3)
#define SET_HEX (1 << 2)

typedef struct {
  char **colours;
  u8 flags;
} Set;
