CXX=g++
CXXFLAGS=-Wextra -Wall -Werror -MMD -g
OBJECTS=SimpleMCMain5.o SimpleMC2.o Random1.o PayOff2.o DoubleDigital.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=montecarlo

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
