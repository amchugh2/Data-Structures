TARGET = seq-test nums

OFILES = seq-test.o nums.o

CXX = g++
CFLAGS = -g -Wall -std=c++17

LDFLAGS =

$(TARGET):	$(OFILES)
		$(CXX) $(OFILES) $(LDFLAGS) -o $@

clean:
	rm -f *~ $(OFILES) $(TARGET)

seq-test.o:	seq-test.cc

nums.o:		nums.cc

TARGET:		seq-test.o nums.o
