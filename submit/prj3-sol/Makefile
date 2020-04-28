TARGET = multi-queues

OFILES = job.o command.o command-stream.o  multi-queues.o

CXX = g++

CFLAGS = -g -Wall -std=c++17

LDFLAGS =

$(TARGET):	$(OFILES)
		$(CXX) $(OFILES) $(LDFLAGS) -o $@

clean:
	rm -f *~ $(OFILES) $(TARGET)

job.o:			job.cc

command.o:		command.cc

command-stream.o:	command-stream.cc

multi-queues.o:		multi-queues.cc

TARGET:		job.o command.o command-stream.o multi-queues.o job.cc command.cc command-stream.cc multi-queues.cc
