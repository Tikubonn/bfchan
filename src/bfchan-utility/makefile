
default:

clean:
	rm -f bfchan-utility.h
	rm -f bfchan-utility.lib
	rm -f compiled/get-bfchan-path-basename.o
	rm -f compiled/get-bfchan-path-dir-and-basename.o

bfchan-utility.h: src/get-bfchan-path-basename.h	src/get-bfchan-path-dir-and-basename.h
	cat src/get-bfchan-path-basename.h src/get-bfchan-path-dir-and-basename.h > bfchan-utility.h

bfchan-utility.lib: compiled/get-bfchan-path-basename.o compiled/get-bfchan-path-dir-and-basename.o
	ar r bfchan-utility.lib compiled/get-bfchan-path-basename.o compiled/get-bfchan-path-dir-and-basename.o

compiled/get-bfchan-path-basename.o: src/get-bfchan-path-basename.c
	gcc $(CFLAGS) -c src/get-bfchan-path-basename.c -o compiled/get-bfchan-path-basename.o

compiled/get-bfchan-path-dir-and-basename.o: src/get-bfchan-path-dir-and-basename.c
	gcc $(CFLAGS) -c src/get-bfchan-path-dir-and-basename.c -o compiled/get-bfchan-path-dir-and-basename.o
