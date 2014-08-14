// Logger_wrap.h by Paul R Jones (paujo) on 7.31.2014


#ifndef PAUJO_LOGGER_WRAP_H
#define PAUJO_LOGGER_WRAP_H

#include <boost/python.hpp>
#include "Logger.h"

#ifdef __cplusplus
extern "C" {
#endif

void init_Logger() {

  boost::python::class_<Logger>("Logger")
    .def("debugMsg", &Logger::debugMsg)
    .def("errorMsg", &Logger::errorMsg)
    .def("infoMsg", &Logger::infoMsg)
    .add_property("debugEnabled", &Logger::getDebugEnabled, &Logger::setDebugEnabled)
    .add_property("errorEnabled", &Logger::getErrorEnabled, &Logger::setErrorEnabled)
    .add_property("infoEnabled", &Logger::getInfoEnabled, &Logger::setInfoEnabled);
}

#ifdef __cplusplus
}
#endif

#endif
