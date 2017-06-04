TARGET: server client

CC = g++
CFLAGS	= -Wall -O2
LFLAGS	= -Wall

events.o: events.h
server.o client.o: err.h events.h
err.o: err.h


client: client.o err.o events.o
	$(CC) $(LFLAGS) $^ -o $@

server: server.o err.o events.o
	$(CC) $(LFLAGS) $^ -o $@

.PHONY: clean TARGET
clean:
	rm -f server client *.o *~ *.bak
