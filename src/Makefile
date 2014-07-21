include ../src/mkspec/props

.PHONY: translate srcclean
.PRECIOUS: %.po

translate: ../gamedata/translations/$(call substr,$(LANG),1,2)/LC_MESSAGES/dungeon-xrawler.mo

srcclean:
	$(RM) ../gamedata/translations/*/LC_MESSAGES/dungeon-xrawler.mo

name=HEADER_DUNGEON_XRAWLER_$(call uc,$(subst -,_,$(subst /,_,$(subst .,_,$(@F)))))
%.h:
	@test ! -e $@
	$Qecho "#ifndef $(name)" >$@
	@echo "#define $(name)" >>$@
	@echo >>$@
	@echo "#endif // $(name)" >>$@

../src/dungeon-xrawler.hpp: ../src/dungeon-xrawler.h
	$Qecho "#ifndef $(name)" >$@
	@echo "#define $(name)" >>$@
	@echo >>$@
	@echo '#include "$(patsubst %pp,%,$(@F))"' >>$@
	@echo >>$@
	@for i in $(objects:.o=.hpp); do echo "#include \"$$i\"" >>$@; done
	@echo >>$@
	@echo "#endif // $(name)" >>$@	

%.hpp: %.cpp %.h
	$Qecho "#ifndef $(name)" >$@
	@echo "#define $(name)" >>$@
	@echo >>$@
	@echo '#include "$(patsubst %pp,%,$(@F))"' >>$@
	@echo >>$@
	@cat $(patsubst %.hpp,%.cpp,$@) |grep -E "$(regex_c_func)" |sed -e "s/ {/;/g" >>$@
	@echo >>$@
	@echo "#endif // $(name)" >>$@

../VERSION: ../src/mkspec/props
	$Qecho $(PKGVERSION) >../VERSION

../gamedata/translations/messages.pot: $(addprefix ../src/,$(objects:.o=.cpp) main.cpp) ../VERSION
	$Qxgettext -c* -c/ -k_ -o $@ -w99 -F --copyright-holder=Arusekk --package-name=dungeon-xrawler --msgid-bugs-address='$(my_email)' --package-version="`cat ../VERSION`" --force-po $(addprefix ../src/,$(objects:.o=.cpp) main.cpp)

%.po: ../gamedata/translations/messages.pot
	$Qtest -e $@ && $(RM) $@ || true
	$Qmsginit --no-translator -l $(@:.po=) -i $< -o $@
	$Qlokalize $@ 2>/dev/null

../gamedata/translations/%/LC_MESSAGES/dungeon-xrawler.mo: ../gamedata/translations/%.po
	$Qmsgfmt -c $V -o $@ $<
