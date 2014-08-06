// pengine_util_Color.h by Paul R Jones (paujo) on 8.6.2014

#ifndef PAUJO_PENGINE_UTIL_COLOR_H
#define PAUJO_PENGINE_UTIL_COLOR_H

#ifdef __cplusplus
extern "C" {
#endif
  
#define COLOR_ARGS(C) (C.r, C.g, C.b, C.a)
#define COLOR_ARGSP(C) (C->r, C->g, C->b, C->a)

  struct Color {
  public:
    Color();
    Color(int, int, int, int);
    int r;
    int g;
    int b;
    int a;
  };

#ifdef __cplusplus
}
#endif

#endif
