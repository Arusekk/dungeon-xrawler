include ../src/mkspec/props

.PHONY: all clean

all: dungeon-xrawler

clean:
	$(RM) *.o dungeon-xrawler

dungeon-xrawler: $(objects) main.o
	$Q$(CXX) $(CXXFLAGS) -o dungeon-xrawler $(objects) main.o

$(objects) main.o: $(addprefix ../src/,dungeon-xrawler.hpp $(objects:.o=.hpp))
	@echo make $@
	$Qmkdir -p $(@D)
	$Q$(CXX) $(CXXFLAGS) -c ../src/$(@:.o=.cpp) -o $@

main.o: ../src/main.cpp
player.o: ../src/player.cpp
screen.o: ../src/screen.cpp
storage.o: ../src/storage.cpp
