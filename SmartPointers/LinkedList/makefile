CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Werror=vla -MMD 
OBJECTS = main.o 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = list

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY : clean

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
