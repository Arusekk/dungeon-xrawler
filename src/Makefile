include ../mkspec/props

.PHONY: all clean
.PRECIOUS: %.po

all: $(objects:.o=.hpp) dungeon-xrawler.hpp

clean:
	${RM} $(objects:.o=.hpp) dungeon-xrawler.hpp

name=HEADER_DUNGEON_XRAWLER_$(call uc,$(subst -,_,$(subst /,_,$(subst .,_,$@))))
%.h:
	@test ! -e $@
	$Qecho "#ifndef ${name}" >$@
	@echo "#define ${name}" >>$@
	@echo >>$@
	@echo "#endif // ${name}" >>$@

dungeon-xrawler.hpp: dungeon-xrawler.h
	$Qecho "#ifndef ${name}" >$@
	@echo "#define ${name}" >>$@
	@echo >>$@
	@echo '#include "$(@F:pp=)"' >>$@
	@echo >>$@
	@for i in $(objects:.o=.hpp); do echo "#include \"$$i\"" >>$@; done
	@echo >>$@
	@echo "#endif // ${name}" >>$@	

%.hpp: %.cpp %.h ../mkspec/regex_c
	$Qecho "#ifndef ${name}" >$@
	@echo "#define ${name}" >>$@
	@echo >>$@
	@echo '#include "$(@F:pp=)"' >>$@
	@echo >>$@
	@cat $(@:.hpp=.cpp) |grep -E "${regex_c_func}" |sed -e 's/{//g' |sed -e 's/${regex_c_spc}*$$/;/g' >>$@
	@echo >>$@
	@echo "#endif // ${name}" >>$@
