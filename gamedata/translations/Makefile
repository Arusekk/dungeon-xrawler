include ../../mkspec/props
place?=$(shell realpath ../..)
lokalize_ver=$(shell lokalize --version 2>/dev/null|grep kalize|cut -b 11-)

.PHONY: all clean

all: ${shortlang}/LC_MESSAGES/dungeon-xrawler.mo
	$Qtrue $@

clean:
	${RM} -r */

messages.pot: $(addprefix ${place}/src/,$(objects:.o=.cpp) main.cpp) ${place}/VERSION
	$Qxgettext -c* -c/ -k_ -o $@.tmp -w99 -F --copyright-holder=Arusekk --package-name=dungeon-xrawler --msgid-bugs-address='${my_email}' --package-version="`cat ${place}/VERSION`" --force-po $(addprefix ${place}/src/,$(objects:.o=.cpp) main.cpp)
	$Qdiff $@ $@.tmp |grep -E '^>' |grep -qv Date || ${RM} $@.tmp
	$Qtest ! -e $@.tmp || mv $@.tmp $@

ifeq (${lokalize_ver},)
%.po: messages.pot
	$Qtouch $@

else
%.po: messages.pot
	$Qtest ! -e $@ || ((diff $@ $< |grep -Eq '(msgid|#[.:]|Version)') && ${RM} $@) || true
	@touch $@
	$Qmsginit --no-translator -l ${@F} -i $< -o $@
	$Qlokalize $@ 2>/dev/null

endif
%/LC_MESSAGES/dungeon-xrawler.mo: %.po
	$Qmkdir -p ${@D}
	$Qmsgfmt -c $V -o $@ $<
