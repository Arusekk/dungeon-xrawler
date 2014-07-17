PKGVERSION=0.04 alpha
objects=player.o screen.o storage.o main.o
my_email=Arusekk <arusekk@gmail.com>
VERBOSE=1

CXXFLAGS=-O2 -Wall -Wextra -Wshadow -Werror -Wnon-virtual-dtor -Wconversion -Weffc++ -Wcast-qual -Winit-self -pedantic -ansi -lm --std=gnu++0x
include ../src/lib/gmsl

ifeq ($(VERBOSE),1)
Q=
V=-v
else
Q=@
V=
endif

.PHONY: translate clean
.PRECIOUS: %.po %.cpp

translate: ../gamedata/translations/$(call substr,$(LANG),1,2)/LC_MESSAGES/dungeon-xrawler.mo

clean:
	$(RM) $(objects:.o=.hpp) ../gamedata/translations/*/LC_MESSAGES/dungeon-xrawler.mo

name=HEADER_DUNGEON_XRAWLER_$(call uc,$(subst -,_,$(subst .,_,$(@F))))
%.h:
	$Qecho "#ifndef $(name)" >$@
	@echo "#define $(name)" >>$@
	@echo >>$@
	@echo "#endif // $(name)" >>$@

../src/lib/__gmsl ../src/lib/gmsl Makefile:
	@touch $@

%.hpp: %.h %.cpp
	$Qecho "#ifndef $(name)" >$@
	@echo "#define $(name)" >>$@
	@echo >>$@
	@echo '#include "$(patsubst %pp,%,$(@F))"' >>$@
	@echo >>$@
	@cat $(patsubst %.hpp,%.cpp,$@) |grep -E "^[a-zA-Z_][a-zA-Z0-9_]*\*? .+\(.*\) \{$$" |sed -e "s/ {/;/g" >>$@
	@echo >>$@
	@echo "#endif // $(name)" >>$@	

%.cpp: ../src/dungeon-xrawler.hpp %.h
	$Qtest -e $@ || echo -e '#include "dungeon-xrawler.hpp"\n' >$@
	@touch $@

../VERSION: ../src/Makefile
	$Qecho $(PKGVERSION) >../VERSION

../src/messages.pot: ../VERSION $(objects:.o=.cpp)
	$Qxgettext -c* -c/ -k_ -o $@ -w99 -F --copyright-holder=Arusekk --package-name=dungeon-xrawler --msgid-bugs-address='$(my_email)' --package-version="`cat ../VERSION`" --force-po $(addprefix ../src/,$(objects:.o=.cpp))

%.po: ../src/messages.pot
	$Qtest -e $@ && $(RM) $@ || true
	$Qmsginit --no-translator -l $(patsubst %.po,%,$@) -i $< -o $@
	$Qlokalize $@ 2>/dev/null

../gamedata/translations/%/LC_MESSAGES/dungeon-xrawler.mo: ../src/%.po
	$Qmsgfmt -c $V -o $@ $(patsubst ../gamedata/translations/%/LC_MESSAGES/dungeon-xrawler.mo,../src/%.po,$@)
