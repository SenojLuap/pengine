# main.mk by Paul R Jones (paujo) on 7.29.2014

PYTHON_VERSION = 2.7
PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)
PYTHON_LIB = /usr/lib/python$(PYTHON_VERSION)/config

BOOST_INCLUDE = /usr/include
BOOST_LIB = /usr/lib

LIB_DIRS = -L$(PYTHON_LIB) -L$(BOOST_LIB)
INCLUDE_DIRS = -I$(PYTHON_INCLUDE) -I$(BOOST_INCLUDE) -Iinclude
LIBS = -lboost_python -lpython$(PYTHON_VERSION) -lSDL2 -lSDL2_image
