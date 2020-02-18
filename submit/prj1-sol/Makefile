TARGET = wordcounts

OFILES = wordcounts.o

CXX = g++
CFLAGS = -g -Wall -std=c++17
LDFLAGS =

$(TARGET):	$(OFILES)
		$(CXX) $(OFILES) $(LDFLAGS) -o $@

clean:
		rm -f *~ $(OFILES) $(TARGET)

wordcounts.o:	wordcounts.cc

TARGET:		wordcounts.o wordcounts.cc
