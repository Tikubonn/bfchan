
default:

clean:
	rm -f bfchan-cheader.h
	rm -f bfchan-cheader.lib
	rm -f compiled/read-bfchan-cheader.o

bfchan-cheader.lib: compiled/read-bfchan-cheader.o
	ar r bfchan-cheader.lib compiled/read-bfchan-cheader.o

bfchan-cheader.h: src/read-bfchan-cheader.h
	cat src/read-bfchan-cheader.h > bfchan-cheader.h

compiled/read-bfchan-cheader.o: src/read-bfchan-cheader.c
	gcc $(CFLAGS) -c src/read-bfchan-cheader.c -o compiled/read-bfchan-cheader.o
