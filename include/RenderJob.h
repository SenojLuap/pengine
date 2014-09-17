// RenderJob.h by Paul R Jones (paujo) on 8.27.2014

#ifndef PAUJO_RENDERJOB_H
#define PAUJO_RENDERJOB_H

#include "Placement.h"

#ifdef __cplusplus
extern "C" {
#endif

  struct RenderJob {
    int image;
    Placement placement;
    RenderJob(int, int=0, int=0, double=1.0, double=0.0, int=0, int=0, bool=false, bool=false);
    RenderJob(int, Placement);
  };

#ifdef __cplusplus
}
#endif

#endif
