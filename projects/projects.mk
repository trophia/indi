# Rule for creating an executable
%.exe: %.cpp
	$(CXX) -O2 -Wall -I../.. -I. -o$*.exe $*.cpp