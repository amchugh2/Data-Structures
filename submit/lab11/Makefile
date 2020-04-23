TARGET = balanced

OFILES = balanced.o

CXX = g++
CFLAGS = -g -Wall -std=c++17

LDFLAGS = 

$(TARGET):	$(OFILES)
		$(CXX) $(OFILES) $(LDFLAGS) -o $@

clean:
	rm -f *~ $(OFILES) $(TARGET)

balanced.o:	balanced.cc

TARGET:		balanced.o balanced.cc
