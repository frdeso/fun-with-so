CC = gcc
CFLAGS = -Wall -g
all: libaaa.so libbbb.so main


aaa.o: aaa.c
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

libaaa.so: aaa.o
	$(CC) -shared $(CFLAGS) -Wl,-soname,libsignificantOther.so -o $@ $<

bbb.o: bbb.c
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

libbbb.so: bbb.o
	$(CC) -shared $(CFLAGS) -o $@ $<

main: main.c fcts.h libaaa.so
	$(CC) -o $@ $< $(CFLAGS) libaaa.so -ldl

.PHONY: clean
clean:
	rm -f *.o *.so main
