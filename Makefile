FLAGS=`wx-config --cxxflags --libs`

all:
	g++ main.cc $(FLAGS) -o bobcat
