CXX=g++
CXXFLAGS=-Wextra -Wall -Werror -MMD -g
OBJECTS=SimpleMCMain5.o SimpleMC2.o Random1.o PayOff2.o DoubleDigital.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=montecarlo

OBJECTS1=SimpleMCMain2.o SimpleMC.o Random1.o PayOff1.o
OBJECTS2=SimpleMCMain5.o SimpleMC2.o Random1.o PayOff2.o DoubleDigital.o

override OBJECTS = ${OBJECTS1}

ALL_OBJECTS=${OBJECTS1} ${OBJECTS2}
ALL_DEPENDS=${ALL_OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${ALL_OBJECTS} ${ALL_DEPENDS} ${EXEC}
