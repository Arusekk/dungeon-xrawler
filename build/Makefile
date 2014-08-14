include ../mkspec/props
place?=$(shell realpath ..)

.PHONY: all clean

all: ${objects} main.o
	$Qtrue $@

clean:
	${RM} *.o

${objects} main.o: %.o: $(addprefix ${place}/src/,dungeon-xrawler.hpp %.cpp)
	@echo Building $@...
	$Qmkdir -p ${@D}
	$Q${CXX} ${CXXFLAGS} -c ${place}/src/$(@:.o=.cpp) -o $@

# ${objects}: %.o: ${place}/src/%.hpp
