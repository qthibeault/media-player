FLAGS=`wx-config --cxxflags --libs`
CC_DEPS=base.cc mainframe.cc
HH_DEPS=base.hh mainframe.hh

all: $(CC_DEPS) $(HH_DEPS)
	g++ -std=c++11 $^ $(FLAGS) -o bobcat
