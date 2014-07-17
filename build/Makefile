PKGVERSION=0.03 alpha
objects=player.o screen.o storage.o main.o
my_email=Arusekk <arusekk@gmail.com>
VERBOSE=0

CXXFLAGS=-O2 -Wall -Wextra -Wshadow -Werror -Wnon-virtual-dtor -Wconversion -Weffc++ -Wcast-qual -Winit-self -pedantic -ansi -lm --std=gnu++0x
include lib/gmsl

ifeq ($(VERBOSE),1)
Q=
V=-v
else
Q=@
V=
endif

.PHONY: all clean
.PRECIOUS: %.po %.h %.cpp

all: ../gamedata/translations/$(call substr,$(LANG),1,2)/LC_MESSAGES/dungeon-xrawler.mo

clean:
	$(RM) *.o $(objects:.o=.hpp) dungeon-xrawler messages.pot *.po */LC_MESSAGES/dungeon-xrawler.mo VERSION

dungeon-xrawler: $(objects)
	$(Q)$(CXX) $(CXXFLAGS) -o dungeon-xrawler $(objects)

$(objects): dungeon-xrawler.hpp $(objects:.o=.hpp)

name=HEADER_DUNGEON_XRAWLER_$(call uc,$(subst -,_,$(subst .,_,$@)))
%.h:
	$(Q)echo "#ifndef $(name)" >$@
	@echo "#define $(name)" >>$@
	@echo >>$@
	@echo "#endif // $(name)" >>$@

lib/__gmsl lib/gmsl Makefile:
	@touch $@

%.hpp: %.h %.cpp
	$(Q)echo "#ifndef $(name)" >$@
	@echo "#define $(name)" >>$@
	@echo >>$@
	@echo '#include "$(patsubst %pp,%,$@)"' >>$@
	@echo >>$@
	@cat $(patsubst %.hpp,%.cpp,$@) |grep -E "^[a-zA-Z_][a-zA-Z0-9_]* .+\(.*\) \{$$" |sed -e "s/ {/;/g" >>$@
	@echo >>$@
	@echo "#endif // $(name)" >>$@	

%.cpp: dungeon-xrawler.hpp %.h
	$(Q)test -e $@ || echo -e '#include "dungeon-xrawler.hpp"\n' >$@
	@touch $@

VERSION:
	$(Q)echo $(PKGVERSION) >VERSION

messages.pot: VERSION dungeon-xrawler
	$(Q)xgettext -c* -c/ -k_ -o messages.pot -w99 -F --copyright-holder=Arusekk --package-name=dungeon-xrawler --msgid-bugs-address='$(my_email)' --package-version="`cat VERSION`" --force-po $(objects:.o=.cpp)

%.po: messages.pot
	$(Q)test -e $@ && $(RM) $@
	$(Q)msginit --no-translator -l $(patsubst %.po,%,$@)
	$(Q)lokalize $@ 2>/dev/null

../gamedata/translations/%/LC_MESSAGES/dungeon-xrawler.mo: %.po
	$(Q)msgfmt -c $(V) -o $@ $(patsubst %/LC_MESSAGES/dungeon-xrawler.mo,%.po,$@)
