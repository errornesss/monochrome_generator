#include <stdio.h>

#include "set.h"

Set st = (Set){
  .colours = (char*[]){
    "[0]",
    "[1]",
    "[2]",
    "[3]",
    "[4]",
    "[5]",
    "[6]",
    "[7]",

    "[8]",
    "[9]",
    "[10]",
    "[11]",
    "[12]",
    "[13]",
    "[14]",
    "[15]",

    NULL,
  },
  .flags = SET_BRIGHT | SET_COMMA,
};

Set eyes = (Set){
  .colours = (char*[]){
    "hex00",
    "hex01",
    "hex02",
    "hex03",
    "hex04",
    "hex05",
    "hex06",
    "hex07",
    "hex08",
    "hex09",
    "hex10",

    NULL,
  },
  .flags = SET_COMMA,
};

Set alacritty = (Set){
  .colours = (char*[]){
    "black",
    "red",
    "green",
    "yellow",
    "blue",
    "magenta",
    "cyan",
    "white",

    "black",
    "red",
    "green",
    "yellow",
    "blue",
    "magenta",
    "cyan",
    "white",

    NULL,
  },
  .flags = SET_BRIGHT,
};
