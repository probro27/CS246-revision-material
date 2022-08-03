CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Werror=vla -MMD 
OBJECTS = main.o station.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = test

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lncurses -o ${EXEC}

.PHONY : clean

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
