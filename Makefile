include mkspec/props
.PHONY: all clean src build

all clean: VERSION
	@$(MAKE) $@ -C src
	@$(MAKE) $@ -C build
	@$(MAKE) $@ -C gamedata/translations

src build: VERSION
	@$(MAKE) -C $@

VERSION: mkspec/props
	$Qecho $(PKGVERSION) >VERSION
