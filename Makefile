# Makefile by Paul R Jones (paujo) on 7.30.2014

include main.mk

SOURCES = $(wildcard ./src/*.cpp)
HEADERS = $(wildcard ./include/*.h)
OBJECTS = $(subst src,build,$(SOURCES:.cpp=.o))

MODULE = Pengine

all: directories $(OBJECTS)
	g++ -shared -Wl,--export-dynamic $(OBJECTS) $(LIB_DIRS) $(LIBS) -o $(MODULE).so

debug: directories $(OBJECTS)
	g++ -shared -Wl,--export-dynamic -DDEBUG $(OBJECTS) $(LIB_DIRS) $(LIBS) -o $(MODULE).so

./build/%.o : ./src/%.cpp
	g++ -g $(INCLUDE_DIRS) -fPIC -o $@ -c $<

directories: ./build

./build:
	@mkdir -p build

clean:
	@rm ./build/* -f
	@if [ -d "build" ]; then rmdir build; fi
	@rm *~ -f
	@echo "Done."