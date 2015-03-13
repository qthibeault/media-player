FLAGS=`wx-config --cxxflags --libs`

all: base.cc mainframe.cc
	g++ $^ base.hh mainframe.hh $(FLAGS) -o bobcat
