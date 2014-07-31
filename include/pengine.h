// pengine.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_PENGINE_H
#define PAUJO_PENGINE_H

#include "logger.h"

#ifdef __cplusplus
extern "C" {
#endif

  class Pengine {
  public:
    static Pengine& getPengine();
    bool startup();
    bool shutdown();
  private:
    Pengine();
    Pengine(Pengine const&);
    ~Pengine();
    void operator=(Pengine const&);

    Logger log;
    bool live;
  };

  void startPengine();
  void stopPengine();

#ifdef __cplusplus
}
#endif

#endif
