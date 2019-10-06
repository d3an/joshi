CXX=g++
CXXFLAGS=-Wextra -Wall -Werror -MMD -g
OBJECTS=SimpleMCMain2.o SimpleMC.o Random1.o PayOff1.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=montecarlo

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
