// RenderJob.h by Paul R Jones (paujo) on 8.27.2014

#ifndef PAUJO_RENDERJOB_H
#define PAUJO_RENDERJOB_H

#ifdef __cplusplus
extern "C" {
#endif

  struct RenderJob {
    int image;
    Placement placement;
    RenderJob();
  }

#ifdef __cplusplus
}
#endif

#endif
