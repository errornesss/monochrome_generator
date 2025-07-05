#pragma once

#include <stdio.h>
#include <stdint.h>

// types ---
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;
typedef long double f128;
// ---


static inline
f32 clamp(f32 min, f32 value, f32 max) {
  if (value > max) 
    return max;
  else if (value < min)
    return min;
  return value;
}

static inline
u8 arrayLength(void **arr) {
  u8 len = 0;
  while (arr[len] != NULL)
    len++;
  return len;
}
