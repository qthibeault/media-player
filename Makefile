FLAGS=`wx-config --cxxflags --libs`
CC_DEPS=base.cc mainframe.cc
HH_DEPS=base.hh mainframe.hh

all: increment_build bobcat

bobcat: $(CC_DEPS) $(HH_DEPS)
	CXX -std=c++11 $^ $(FLAGS) -o bobcat

increment_build: $(CC_DEPS) $(HH_DEPS)
	@echo $$(($$(cat .build_number) + 1)) > .build_number
	@echo "Build Number: " $$(cat .build_number)
