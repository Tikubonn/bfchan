
default:

clean:
	rm -f bfchan.h
	rm -f bfchan.lib
	rm -f compiled/assemble-bfchan-manually.o
	rm -f compiled/assemble-bfchan.o
	rm -f compiled/free-bfchan.o
	rm -f compiled/init-bfchan.o
	rm -f compiled/make-bfchan.o
	rm -f compiled/optimize-bfchan.o
	rm -f compiled/put-bfchan-manually.o
	rm -f compiled/put-bfchan.o
	rm -f compiled/remap-bfchan-operator-list.o
	rm -f compiled/remap-bfchan-opt-operator-list.o

bfchan.h: src/assemble-bfchan-manually.h src/assemble-bfchan.h src/free-bfchan.h src/init-bfchan.h src/make-bfchan.h src/optimize-bfchan.h src/put-bfchan-manually.h src/put-bfchan.h src/remap-bfchan-operator-list.h src/remap-bfchan-opt-operator-list.h
	cat src/assemble-bfchan-manually.h src/assemble-bfchan.h src/free-bfchan.h src/init-bfchan.h src/make-bfchan.h src/optimize-bfchan.h src/put-bfchan-manually.h src/put-bfchan.h src/remap-bfchan-operator-list.h src/remap-bfchan-opt-operator-list.h > bfchan.h

bfchan.lib: compiled/assemble-bfchan-manually.o compiled/assemble-bfchan.o compiled/free-bfchan.o compiled/init-bfchan.o compiled/make-bfchan.o compiled/optimize-bfchan.o compiled/put-bfchan-manually.o compiled/put-bfchan.o compiled/remap-bfchan-operator-list.o compiled/remap-bfchan-opt-operator-list.o
	ar r bfchan.lib compiled/assemble-bfchan-manually.o compiled/assemble-bfchan.o compiled/free-bfchan.o compiled/init-bfchan.o compiled/make-bfchan.o compiled/optimize-bfchan.o compiled/put-bfchan-manually.o compiled/put-bfchan.o compiled/remap-bfchan-operator-list.o compiled/remap-bfchan-opt-operator-list.o

compiled/assemble-bfchan-manually.o: src/assemble-bfchan-manually.c 
	gcc $(CFLAGS) -c src/assemble-bfchan-manually.c -o compiled/assemble-bfchan-manually.o

compiled/assemble-bfchan.o: src/assemble-bfchan.c 
	gcc $(CFLAGS) -c src/assemble-bfchan.c -o compiled/assemble-bfchan.o

compiled/free-bfchan.o: src/free-bfchan.c 
	gcc $(CFLAGS) -c src/free-bfchan.c -o compiled/free-bfchan.o

compiled/init-bfchan.o: src/init-bfchan.c 
	gcc $(CFLAGS) -c src/init-bfchan.c -o compiled/init-bfchan.o

compiled/make-bfchan.o: src/make-bfchan.c 
	gcc $(CFLAGS) -c src/make-bfchan.c -o compiled/make-bfchan.o

compiled/optimize-bfchan.o: src/optimize-bfchan.c 
	gcc $(CFLAGS) -c src/optimize-bfchan.c -o compiled/optimize-bfchan.o

compiled/put-bfchan-manually.o: src/put-bfchan-manually.c 
	gcc $(CFLAGS) -c src/put-bfchan-manually.c -o compiled/put-bfchan-manually.o

compiled/put-bfchan.o: src/put-bfchan.c 
	gcc $(CFLAGS) -c src/put-bfchan.c -o compiled/put-bfchan.o

compiled/remap-bfchan-operator-list.o: src/remap-bfchan-operator-list.c 
	gcc $(CFLAGS) -c src/remap-bfchan-operator-list.c -o compiled/remap-bfchan-operator-list.o

compiled/remap-bfchan-opt-operator-list.o: src/remap-bfchan-opt-operator-list.c 
	gcc $(CFLAGS) -c src/remap-bfchan-opt-operator-list.c -o compiled/remap-bfchan-opt-operator-list.o
