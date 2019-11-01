
default:

clean:
	rm -f bfchan-symname.h
	rm -f bfchan-symname.lib
	rm -f compiled/bfchan-symname-basename.o
	rm -f compiled/bfchan-symname-name.o
	rm -f compiled/init-bfchan-symname.o
	rm -f compiled/copy-bfchan-symname.o

bfchan-symname.h: src/bfchan-symname-basename.h src/bfchan-symname-name.h src/init-bfchan-symname.h src/copy-bfchan-symname.h
	cat src/bfchan-symname-basename.h src/bfchan-symname-name.h src/init-bfchan-symname.h src/copy-bfchan-symname.h > bfchan-symname.h

bfchan-symname.lib: compiled/bfchan-symname-basename.o compiled/bfchan-symname-name.o compiled/init-bfchan-symname.o compiled/copy-bfchan-symname.o
	ar r bfchan-symname.lib compiled/bfchan-symname-basename.o compiled/bfchan-symname-name.o compiled/init-bfchan-symname.o compiled/copy-bfchan-symname.o

compiled/bfchan-symname-basename.o: src/bfchan-symname-basename.c 
	gcc $(CFLAGS) -c src/bfchan-symname-basename.c -o compiled/bfchan-symname-basename.o

compiled/bfchan-symname-name.o: src/bfchan-symname-name.c 
	gcc $(CFLAGS) -c src/bfchan-symname-name.c -o compiled/bfchan-symname-name.o

compiled/init-bfchan-symname.o: src/init-bfchan-symname.c 
	gcc $(CFLAGS) -c src/init-bfchan-symname.c -o compiled/init-bfchan-symname.o

compiled/copy-bfchan-symname.o: src/copy-bfchan-symname.c 
	gcc $(CFLAGS) -c src/copy-bfchan-symname.c -o compiled/copy-bfchan-symname.o
