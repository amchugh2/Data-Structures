TARGET = seq-test

OFILES = seq-test.o command.o nums.o

CXX = g++
CFLAGS = -g -Wall -std=c++17

LDFLAGS =

$(TARGET):	$(OFILES)
		$(CXX) $(OFILES) $(LDFLGAGS) -o $@

clean:
		rm -f *~ $(OFILES) $(TARGET)

seq-test.o:	seq-test.cc

command.o:	command.cc

nums.o:		nums.cc

TARGET:		seq-test.o seq-test.cc
