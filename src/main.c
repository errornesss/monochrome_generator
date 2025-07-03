#include <stdio.h>
#include <stdlib.h>

#include "../dep/raylib.h"

#include "utils.h"

#include "set.h"

Colour *coloursGenerate(f32 min, f32 max, u8 step, Colour *tint) {
  Colour *colours = malloc(step * sizeof(Colour));
  f32 interval = (max - min) / (step - 1);
  {
    u8 i = 0;
    f32 val = min;
    for (
      ;
      i < step && val <= max + 1;
      i++, val += interval
    ) {
      colours[i] = (Colour){
        clamp(0, val + tint->r, 255),
        clamp(0, val + tint->g, 255),
        clamp(0, val + tint->b, 255),
        255
      };
    }
  }
  return colours;
}

void colourWrite();

#include "colours.c"

i32 main(/* i32 argc, char *argv[] */) {
  Set set = st;

  u16
    HEI_S = 32,
    STEP = (set.flags & SET_BRIGHT)
      ? arrayLength((void*)set.colours) / 2
      : arrayLength((void*)set.colours),
    WID = STEP * HEI_S,
    HEI = (set.flags & SET_BRIGHT) ? 2 * HEI_S : HEI_S;

  // edit variables start
  f32
    perc_edit = 0.20f,
    frame_edit = 0.35f;
  Colour tint_edit = (Colour){
    255 * 0.00f,
    255 * 0.00f,
    255 * 0.00f,
  };
  // edit variables stop

  Colour *colours, *colours_b;
  f32 perc = 255 * perc_edit;
  colours = coloursGenerate(perc, 255-perc, STEP, &tint_edit);
  if (set.flags & SET_BRIGHT){
    f32 frame = (colours[1].r - colours[0].r) * frame_edit;
    colours_b = coloursGenerate(perc+frame, (255-perc)+frame, STEP, &tint_edit);
  }

  InitWindow(WID, HEI, "monochrome generator");
  SetTargetFPS(144);

  while (!WindowShouldClose()) {

    BeginDrawing(); {
      ClearBackground(BLACK);
      for (u8 i = 0; i < STEP; i++) {
        DrawRectangle(i * HEI_S, 0, HEI_S, HEI_S, colours[i]);
        if (set.flags & SET_BRIGHT)
          DrawRectangle(i * HEI_S, HEI_S, HEI_S, HEI_S, colours_b[i]);
      }
    } EndDrawing();
  }

  free(colours);
  if (colours_b != NULL) free(colours_b);

  CloseWindow();
  return 0;
}
