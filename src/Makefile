CXXFLAGS=-O2 -Wall -Wextra -Wshadow -pedantic -lm --std=gnu++0x
objects=main.o player.o screen.o storage.o
my_email=arusekk@gmail.com

ifeq ($(VERBOSE),1)
Q=
else
Q=@
endif

.PHONY: all clean

all: dungeon-xrawler pl.po

clean:
	rm -f *.o dungeon-xrawler messages.pot *.po

dungeon-xrawler: $(objects)
	$(Q)g++ $(CXXFLAGS) -o dungeon-xrawler $(objects)

%.o:
	$(Q)g++ $(CXXFLAGS) -c $(patsubst %.o,%.cpp,$@)

messages.pot:
	$(Q)xgettext -c/ -k_ -o messages.pot -w99 -F --package-name=dungeon-xrawler --msgid-bugs-address=$(my_email) "--package-version=`cat VERSION`" --force-po *.cpp

%.po: messages.pot
	$(Q)msginit -l $(patsubst %.po,%,$@)
