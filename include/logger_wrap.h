// logger_wrap.h by Paul R Jones (paujo) on 7.31.2014

#include <boost/python.hpp>
#include "logger.h"

void init_logger() {

  boost::python::class_<Logger>("Logger")
    .def("debugMsg", &Logger::debugMsg)
    .def("errorMsg", &Logger::errorMsg)
    .def("infoMsg", &Logger::infoMsg)
    .add_property("debugEnabled", &Logger::getDebugEnabled, &Logger::setDebugEnabled)
    .add_property("errorEnabled", &Logger::getErrorEnabled, &Logger::setErrorEnabled)
    .add_property("infoEnabled", &Logger::getInfoEnabled, &Logger::setInfoEnabled);
}
