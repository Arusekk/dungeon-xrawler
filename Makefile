include mkspec/props
place:=$(shell pwd)
pathescape=$(subst /,\/,$1)

.PHONY: default-target all clean src build translate misc miscclean vacuum kate

default-target: all

all clean: VERSION
	@${MAKE} place=${place} -C src $@
	@${MAKE} place=${place} -C build $@
	@${MAKE} place=${place} -C gamedata/translations $@
	@$(if $(call seq,clean,$@),,${MAKE} misc)
	@$(if ${windows},,${congrat})

src build translate: VERSION
	@${MAKE} place=${place} -C $(@:%e=gamedata/%ions)

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
	$Qtest -f "$${XDG_CONFIG_HOME:-$$HOME/.config}/user-dirs.dirs" && . "$${XDG_CONFIG_HOME:-$$HOME/.config}/user-dirs.dirs" && export XDG_DESKTOP_DIR XDG_DOWNLOAD_DIR XDG_TEMPLATES_DIR XDG_PUBLICSHARE_DIR XDG_DOCUMENTS_DIR XDG_MUSIC_DIR XDG_PICTURES_DIR XDG_VIDEOS_DIR && cp -a "$@" "$$XDG_DESKTOP_DIR" && echo -e '${succe} Copied desktop shortcut to' "$$XDG_DESKTOP_DIR" || echo -e '${infor} problem with XDG desktop directory, which should have been set in' "\`$${XDG_CONFIG_HOME:-$$HOME/.config}/user-dirs.dirs'"

#link TIMESTRUCT=struct.pack('<Q', int(((time.time())+11644485840.0)*10000000))
dungeon-xrawler.lnk: src/templates/dungeon-xrawler.lnk
	$Qecho -en '$(call template,${<F})' >$@

pkg.tgz: dungeon-xrawler dungeon-xrawler.desktop
	$Qtar -czf pkg.tgz gamedata/translations/*.po gamedata/translations/*/ gamedata/art gamedata/levels dungeon-xrawler dungeon-xrawler.desktop

vacuum:
	${RM} -r src build configure Makefile INSTALL VERSION

kate:
	$Qfor i in `find ..`; do file $$i |grep text |grep -vEq '[.]git' && kate $$i || true; done
