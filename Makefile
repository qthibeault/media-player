FLAGS=`wx-config --cxxflags --libs`

all:
	g++ base.cc mainframe.cc $(FLAGS) -o bobcat
