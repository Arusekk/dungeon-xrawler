.PHONY: all clean

all: dungeon-xrawler

include ../src/Makefile

clean:
	$(RM) *.o dungeon-xrawler

dungeon-xrawler: $(objects)
	@echo make $@
	$Q$(CXX) $(CXXFLAGS) -o dungeon-xrawler $(objects)

$(objects): $(addprefix ../src/,dungeon-xrawler.hpp $(objects:.o=.hpp))
	@echo make $@
	$Q$(CXX) $(CXXFLAGS) -c ../src/$(@:.o=.cpp) -o $@
