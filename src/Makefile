include ../mkspec/props
place?=$(shell realpath ..)

.PHONY: all clean
.PRECIOUS: %.po

all: $(objects:.o=.hpp) dungeon-xrawler.hpp
	$Qtrue $@

clean:
	${RM} $(objects:.o=.hpp) dungeon-xrawler.hpp

dungeon-xrawler.hpp: %: templates/%
	$Qecho -en '$(call template,$@)' >$@

%.hpp: templates/%.hpp %.cpp ${place}/mkspec/regex_c
	$Qecho -en '$(call template,$@)' >$@

%: templates/%
	$Qecho -en '$(call template,$@)' >$@
