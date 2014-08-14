// Logger.cpp by Paul R Jones (paujo) on 7.31.2014

#include "Logger.h"

// Ctor.
Logger::Logger() {
#ifdef DEBUG
  debugEnabled = true;
  errorEnabled = true;
  infoEnabled = true;
#else
  debugEnabled = false;
  errorEnabled = true;
  infoEnabled = false;
#endif
}

// Dtor.
Logger::~Logger() { }

// Output a debug message, if they are enabled
void Logger::debugMsg(std::string message) {
  if (debugEnabled)
    std::cout << "[DEBUG] " << message << std::endl;
}

// Output an error message, if they are enabled
void Logger::errorMsg(std::string message) {
  if (errorEnabled)
    std::cout << "[ERROR] " << message << std::endl;
}

// Output an info message, if they are enabled
void Logger::infoMsg(std::string message) {
  if (infoEnabled)
    std::cout << "[INFO] " << message << std::endl;
}

// Return debugEnabled
bool Logger::getDebugEnabled() {
  return debugEnabled;
}

// Return errorEnabled
bool Logger::getErrorEnabled() {
  return errorEnabled;
}

// Return infoEnabled
bool Logger::getInfoEnabled() {
  return infoEnabled;
}

// Set debugEnabled
void Logger::setDebugEnabled(bool enabled) {
  debugEnabled = enabled;
}

// Set errorEnabled
void Logger::setErrorEnabled(bool enabled) {
  errorEnabled = enabled;
}

// Set infoEnabled
void Logger::setInfoEnabled(bool enabled) {
  infoEnabled = enabled;
}

