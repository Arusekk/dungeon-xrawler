include ../../mkspec/props

.PHONY: all clean

all: $(shortlang)/LC_MESSAGES/dungeon-xrawler.mo

clean:
	$(RM) -r */

messages.pot: $(addprefix ../../src/,$(objects:.o=.cpp) main.cpp) ../../VERSION
	$Qxgettext -c* -c/ -k_ -o $@ -w99 -F --copyright-holder=Arusekk --package-name=dungeon-xrawler --msgid-bugs-address='$(my_email)' --package-version="`cat ../../VERSION`" --force-po $(addprefix ../../src/,$(objects:.o=.cpp) main.cpp)

%.po: messages.pot
	@touch $@
	$Qtest ! -e $@ || ((diff $@ $< |grep -Eq '(msgid|#[.:]|Version)') && $(RM) $@) || true
	$Qmsginit --no-translator -l ${@F} -i $< -o $@
	$Qlokalize $@ 2>/dev/null

%/LC_MESSAGES/dungeon-xrawler.mo: %.po
	$Qmkdir -p $(@D)
	$Qmsgfmt -c $V -o $@ $<
