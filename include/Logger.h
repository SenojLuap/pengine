// Logger.h by Paul R Jones (paujo) on 7.31.2014

#ifndef PAUJO_LOGGER_H
#define PAUJO_LOGGER_H

#include <string>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

  class Logger {
  public:
    Logger();
    ~Logger();

    void debugMsg(std::string);
    void errorMsg(std::string);
    void infoMsg(std::string);

    bool getDebugEnabled();
    bool getErrorEnabled();
    bool getInfoEnabled();

    void setDebugEnabled(bool);
    void setErrorEnabled(bool);
    void setInfoEnabled(bool);
  private:
    bool debugEnabled;
    bool errorEnabled;
    bool infoEnabled;
  };


#ifdef __cplusplus
}
#endif

#endif
