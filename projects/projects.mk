# Rule for creating an executable
%.exe: %.cpp
	$(CXX) -std=c++0x -O2 -Wall -pthread -I../.. -I. -o$*.exe $*.cpp