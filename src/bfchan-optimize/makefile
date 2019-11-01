
default:

clean:
	rm -f bfchan-optimize.h
	rm -f bfchan-optimize.lib
	rm -f compiled/optimize-bfchan-assign-operator.o
	rm -f compiled/optimize-bfchan-calculation-addr-operator.o
	rm -f compiled/optimize-bfchan-calculation-operator.o
	rm -f compiled/optimize-bfchan-zero-clear-operator.o
	rm -f compiled/optimize-bfchan-operator.o
	rm -f compiled/optimize-bfchan-jump-forward-operator.o
	rm -f compiled/optimize-bfchan-jump-backward-operator.o

bfchan-optimize.h: src/optimize-bfchan-assign-operator.h src/optimize-bfchan-calculation-addr-operator.h src/optimize-bfchan-calculation-operator.h src/optimize-bfchan-zero-clear-operator.h src/optimize-bfchan-operator.h src/optimize-bfchan-jump-forward-operator.h src/optimize-bfchan-jump-backward-operator.h
	cat src/optimize-bfchan-assign-operator.h src/optimize-bfchan-calculation-addr-operator.h src/optimize-bfchan-calculation-operator.h src/optimize-bfchan-zero-clear-operator.h src/optimize-bfchan-operator.h src/optimize-bfchan-jump-forward-operator.h src/optimize-bfchan-jump-backward-operator.h > bfchan-optimize.h

bfchan-optimize.lib: compiled/optimize-bfchan-assign-operator.o compiled/optimize-bfchan-calculation-addr-operator.o compiled/optimize-bfchan-calculation-operator.o compiled/optimize-bfchan-zero-clear-operator.o compiled/optimize-bfchan-operator.o compiled/optimize-bfchan-jump-forward-operator.o compiled/optimize-bfchan-jump-backward-operator.o
	ar r bfchan-optimize.lib compiled/optimize-bfchan-assign-operator.o compiled/optimize-bfchan-calculation-addr-operator.o compiled/optimize-bfchan-calculation-operator.o compiled/optimize-bfchan-zero-clear-operator.o compiled/optimize-bfchan-operator.o compiled/optimize-bfchan-jump-forward-operator.o compiled/optimize-bfchan-jump-backward-operator.o

compiled/optimize-bfchan-assign-operator.o: src/optimize-bfchan-assign-operator.c 
	gcc $(CFLAGS) -c src/optimize-bfchan-assign-operator.c -o compiled/optimize-bfchan-assign-operator.o

compiled/optimize-bfchan-calculation-addr-operator.o: src/optimize-bfchan-calculation-addr-operator.c 
	gcc $(CFLAGS) -c src/optimize-bfchan-calculation-addr-operator.c -o compiled/optimize-bfchan-calculation-addr-operator.o

compiled/optimize-bfchan-calculation-operator.o: src/optimize-bfchan-calculation-operator.c 
	gcc $(CFLAGS) -c src/optimize-bfchan-calculation-operator.c -o compiled/optimize-bfchan-calculation-operator.o

compiled/optimize-bfchan-zero-clear-operator.o: src/optimize-bfchan-zero-clear-operator.c 
	gcc $(CFLAGS) -c src/optimize-bfchan-zero-clear-operator.c -o compiled/optimize-bfchan-zero-clear-operator.o

compiled/optimize-bfchan-operator.o: src/optimize-bfchan-operator.c 
	gcc $(CFLAGS) -c src/optimize-bfchan-operator.c -o compiled/optimize-bfchan-operator.o

compiled/optimize-bfchan-jump-forward-operator.o: src/optimize-bfchan-jump-forward-operator.c 
	gcc $(CFLAGS) -c src/optimize-bfchan-jump-forward-operator.c -o compiled/optimize-bfchan-jump-forward-operator.o

compiled/optimize-bfchan-jump-backward-operator.o: src/optimize-bfchan-jump-backward-operator.c 
	gcc $(CFLAGS) -c src/optimize-bfchan-jump-backward-operator.c -o compiled/optimize-bfchan-jump-backward-operator.o
