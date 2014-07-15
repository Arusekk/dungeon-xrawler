CXXFLAGS=-O2 -Wall -Wextra -Wshadow -pedantic -lm --std=gnu++0x

.PHONY: all clean

clean:
	rm *.o dungeon-xrawler

all: dungeon-xrawler

dungeon-xrawler:
	g++ -o dungeon-xrawler $CXXFLAGS *.cpp
