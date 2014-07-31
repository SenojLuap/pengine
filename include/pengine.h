// pengine.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_PENGINE_H
#define PAUJO_PENGINE_H

#ifdef __cplusplus
extern "C" {
#endif

#define DEBUG

  class Pengine {
  public:
    static Pengine& getPengine();
    bool startup();
    bool shutdown();
  private:
    Pengine() {}
    Pengine(Pengine const&);
    void operator=(Pengine const&);
  };

  void startEngine();
  void stopEngine();

#ifdef __cplusplus
}
#endif

#endif
