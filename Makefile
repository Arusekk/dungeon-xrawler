include mkspec/props
place:=$(shell pwd)
pathescape=$(subst /,\/,$1)

.PHONY: default-target all clean src build misc miscclean vacuum

default-target: all

all clean: VERSION
	@${MAKE} place=${place} -C src $@
	@${MAKE} place=${place} -C build $@
	@${MAKE} place=${place} -C gamedata/translations $@
	@${MAKE} misc
	@$(congrat)

src build: VERSION
	@${MAKE} place=${place} -C $@

VERSION: mkspec/props
	$Qecho ${PKGVERSION} >VERSION

misc: VERSION dungeon-xrawler dungeon-xrawler.desktop
miscclean:
	${RM} dungeon-xrawler dungeon-xrawler.desktop

dungeon-xrawler: $(addprefix build/,${objects} main.o)
	$Q${CXX} ${CXXFLAGS} -o $@ $^

dungeon-xrawler.desktop: src/templates/dungeon-xrawler.desktop
	$Qecho -en '$(call template,${<F})' >$@
	$Qchmod +x $@ || true
	$Qtest -f $${XDG_CONFIG_HOME:-~/.config}/user-dirs.dirs && . $${XDG_CONFIG_HOME:-~/.config}/user-dirs.dirs && export XDG_DESKTOP_DIR XDG_DOWNLOAD_DIR XDG_TEMPLATES_DIR XDG_PUBLICSHARE_DIR XDG_DOCUMENTS_DIR XDG_MUSIC_DIR XDG_PICTURES_DIR XDG_VIDEOS_DIR && cp $@ $$XDG_DESKTOP_DIR

pkg.tgz: dungeon-xrawler dungeon-xrawler.desktop
	$Qtar -czf pkg.tgz gamedata/translations/*.po gamedata/translations/*/ gamedata/art gamedata/levels dungeon-xrawler dungeon-xrawler.desktop

vacuum:
	${RM} -r src build configure Makefile INSTALL VERSION
