FLAGS=`wx-config --cxxflags --libs`

all:
	g++ base.cc mainframe.cc base.hh mainframe.hh $(FLAGS) -o bobcat
