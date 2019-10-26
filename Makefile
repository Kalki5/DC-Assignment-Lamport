all: clock

clock: LamportClock.c
	gcc -o clock LamportClock.c

clean:
	rm -rf clock
