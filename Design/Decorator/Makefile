CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Werror=vla -MMD 
OBJECTS = main.o basefunc.o add.o subtract.o multiply.o divide.o 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = seq

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY : clean

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
