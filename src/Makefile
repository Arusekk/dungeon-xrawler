CXXFLAGS=-O2 -Wall -Wextra -Wshadow -pedantic -lm --std=gnu++0x
objects=main.o player.o screen.o storage.o

ifeq ($(VERBOSE),1)
Q=
else
Q=@
endif

.PHONY: all clean

all: dungeon-xrawler

clean:
	rm -f *.o dungeon-xrawler

dungeon-xrawler: $(objects)
	$(Q)g++ $(CXXFLAGS) -o dungeon-xrawler $(objects)

%.o:
	$(Q)g++ $(CXXFLAGS) -c $(patsubst %.o,%.cpp,$@)
