.PHONY: all clean
.PRECIOUS: %.po %.cpp

all: dungeon-xrawler

include ../src/Makefile

clean:
	$(RM) *.o dungeon-xrawler

dungeon-xrawler: $(objects)
	$(Q)$(CXX) $(CXXFLAGS) -o dungeon-xrawler $(objects)

$(objects): $(addprefix ../src/,dungeon-xrawler.hpp $(objects:.o=.hpp))
	$(Q)$(CXX) $(CXXFLAGS) -c ../src/$(patsubst %.o,%.cpp,$@) -o $@
