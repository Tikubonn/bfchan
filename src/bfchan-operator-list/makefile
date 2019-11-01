
default:

clean:
	rm -f bfchan-operator-list.h
	rm -f bfchan-operator-list.lib
	rm -f compiled/add-bfchan-operator-list-manually.o
	rm -f compiled/add-bfchan-operator-list.o
	rm -f compiled/copy-bfchan-operator-list.o
	rm -f compiled/extend-bfchan-operator-list.o
	rm -f compiled/free-bfchan-operator-list.o
	rm -f compiled/get-bfchan-operator-list.o
	rm -f compiled/init-bfchan-operator-list.o
	rm -f compiled/bfchan-operator-list-length.o
	rm -f compiled/clear-bfchan-operator-list.o
	rm -f compiled/set-bfchan-operator-list.o

bfchan-operator-list.h: src/add-bfchan-operator-list-manually.h src/add-bfchan-operator-list.h src/copy-bfchan-operator-list.h src/extend-bfchan-operator-list.h src/free-bfchan-operator-list.h src/get-bfchan-operator-list.h src/init-bfchan-operator-list.h src/bfchan-operator-list-length.h src/clear-bfchan-operator-list.h src/set-bfchan-operator-list.h
	cat src/add-bfchan-operator-list-manually.h src/add-bfchan-operator-list.h src/copy-bfchan-operator-list.h src/extend-bfchan-operator-list.h src/free-bfchan-operator-list.h src/get-bfchan-operator-list.h src/init-bfchan-operator-list.h src/bfchan-operator-list-length.h src/clear-bfchan-operator-list.h src/set-bfchan-operator-list.h > bfchan-operator-list.h

bfchan-operator-list.lib: compiled/add-bfchan-operator-list-manually.o compiled/add-bfchan-operator-list.o compiled/copy-bfchan-operator-list.o compiled/extend-bfchan-operator-list.o compiled/free-bfchan-operator-list.o compiled/get-bfchan-operator-list.o compiled/init-bfchan-operator-list.o compiled/bfchan-operator-list-length.o compiled/clear-bfchan-operator-list.o compiled/set-bfchan-operator-list.o
	ar r bfchan-operator-list.lib compiled/add-bfchan-operator-list-manually.o compiled/add-bfchan-operator-list.o compiled/copy-bfchan-operator-list.o compiled/extend-bfchan-operator-list.o compiled/free-bfchan-operator-list.o compiled/get-bfchan-operator-list.o compiled/init-bfchan-operator-list.o compiled/bfchan-operator-list-length.o compiled/clear-bfchan-operator-list.o compiled/set-bfchan-operator-list.o

compiled/add-bfchan-operator-list-manually.o: src/add-bfchan-operator-list-manually.c 
	gcc $(CFLAGS) -c src/add-bfchan-operator-list-manually.c -o compiled/add-bfchan-operator-list-manually.o

compiled/add-bfchan-operator-list.o: src/add-bfchan-operator-list.c 
	gcc $(CFLAGS) -c src/add-bfchan-operator-list.c -o compiled/add-bfchan-operator-list.o

compiled/copy-bfchan-operator-list.o: src/copy-bfchan-operator-list.c 
	gcc $(CFLAGS) -c src/copy-bfchan-operator-list.c -o compiled/copy-bfchan-operator-list.o

compiled/extend-bfchan-operator-list.o: src/extend-bfchan-operator-list.c 
	gcc $(CFLAGS) -c src/extend-bfchan-operator-list.c -o compiled/extend-bfchan-operator-list.o

compiled/free-bfchan-operator-list.o: src/free-bfchan-operator-list.c 
	gcc $(CFLAGS) -c src/free-bfchan-operator-list.c -o compiled/free-bfchan-operator-list.o

compiled/get-bfchan-operator-list.o: src/get-bfchan-operator-list.c 
	gcc $(CFLAGS) -c src/get-bfchan-operator-list.c -o compiled/get-bfchan-operator-list.o

compiled/init-bfchan-operator-list.o: src/init-bfchan-operator-list.c 
	gcc $(CFLAGS) -c src/init-bfchan-operator-list.c -o compiled/init-bfchan-operator-list.o

compiled/bfchan-operator-list-length.o: src/bfchan-operator-list-length.c 
	gcc $(CFLAGS) -c src/bfchan-operator-list-length.c -o compiled/bfchan-operator-list-length.o

compiled/clear-bfchan-operator-list.o: src/clear-bfchan-operator-list.c 
	gcc $(CFLAGS) -c src/clear-bfchan-operator-list.c -o compiled/clear-bfchan-operator-list.o

compiled/set-bfchan-operator-list.o: src/set-bfchan-operator-list.c 
	gcc $(CFLAGS) -c src/set-bfchan-operator-list.c -o compiled/set-bfchan-operator-list.o
