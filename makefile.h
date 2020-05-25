CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = Ant.cpp InputValidation.cpp Menu.cpp LangtonAntRuleSimulation.cpp 

HEADERS = Ant.hpp InputValidation.hpp Menu.hpp

LangtonAntRuleSimulation: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o LangtonAntRuleSimulation

clean:
	rm LangtonAntRuleSimulation
