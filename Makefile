CC = gcc
CFLAGS = -Wall -g
all: libsignificantOther.so libparamour.so main


significantOther.o: significantOther.c
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

libsignificantOther.so: significantOther.o
	$(CC) -shared $(CFLAGS) -Wl,-soname,libsignificantOther.so -o $@ $<

paramour.o: paramour.c
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

libparamour.so: paramour.o
	$(CC) -shared $(CFLAGS) -o $@ $<

main: main.c fcts.h
	$(CC) -o $@ $< $(CFLAGS) libsignificantOther.so -ldl

.PHONY: clean
clean:
	rm -f *.o *.so main
