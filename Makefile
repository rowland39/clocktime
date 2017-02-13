CFLAGS=
LDFLAGS=
CC=gcc

.PHONY: all
all: clocktime

clocktime: clocktime.o
	$(CC) -o $@ $^ $(LDFLAGS)

clocktime.o: clocktime.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o clocktime
