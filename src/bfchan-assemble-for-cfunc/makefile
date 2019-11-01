
default:

clean:
	rm -f bfchan-assemble-for-cfunc.h
	rm -f bfchan-assemble-for-cfunc.lib
	rm -f compiled/assemble-bfchan-init-for-cfunc.o
	rm -f compiled/assemble-bfchan-init-for-cfunc-manually.o

bfchan-assemble-for-cfunc.h: src/assemble-bfchan-init-for-cfunc.h src/assemble-bfchan-init-for-cfunc-manually.h
	cat src/assemble-bfchan-init-for-cfunc.h src/assemble-bfchan-init-for-cfunc-manually.h > bfchan-assemble-for-cfunc.h

bfchan-assemble-for-cfunc.lib: compiled/assemble-bfchan-init-for-cfunc.o compiled/assemble-bfchan-init-for-cfunc-manually.o
	ar r bfchan-assemble-for-cfunc.lib compiled/assemble-bfchan-init-for-cfunc.o compiled/assemble-bfchan-init-for-cfunc-manually.o

compiled/assemble-bfchan-init-for-cfunc.o: src/assemble-bfchan-init-for-cfunc.c
	gcc $(CFLAGS) -c src/assemble-bfchan-init-for-cfunc.c -o compiled/assemble-bfchan-init-for-cfunc.o

compiled/assemble-bfchan-init-for-cfunc-manually.o: src/assemble-bfchan-init-for-cfunc-manually.c
	gcc $(CFLAGS) -c src/assemble-bfchan-init-for-cfunc-manually.c -o compiled/assemble-bfchan-init-for-cfunc-manually.o
