// pengine_wrap.cpp by Paul R Jones (paujo) on 7.31.2014

#include <boost/python.hpp>

#define DEBUG 

#include "pengine.h"
#include "logger_wrap.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(pengine) {
  object package = scope();
  package.attr("__path__") = "pengine";
  
  def("startEngine", startEngine);
  def("stopEngine", stopEngine);

  init_logger();
}
