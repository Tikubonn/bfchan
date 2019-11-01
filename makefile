
export CFLAGS += -I$(NANAFY_INCLUDE_DIR) -L$(NANAFY_LIBRARY_DIR) -g 

all: .always
	make build-library
	make build-application

build-library: .always
	make h -C src
	make lib -C src
	make dll -C src
	make dist/bfchan.h
	make dist/bfchan.lib
	make dist/bfchan.dll

build-application: .always
	make h -C src
	make lib -C src
	make dll -C src
	make bin/bfchan.dll
	make bin/bfchan.exe

clean: .always
	make clean -C src

dist/bfchan.h: src/bfchan.h
	cp src/bfchan.h dist/bfchan.h

dist/bfchan.lib: src/bfchan.lib
	cp src/bfchan.lib dist/bfchan.lib

dist/bfchan.dll: src/bfchan.dll
	cp src/bfchan.dll dist/bfchan.dll

bin/bfchan.dll: src/bfchan.dll
	cp src/bfchan.dll bin/bfchan.dll

bin/bfchan.exe: main.c src/bfchan.dll
	gcc $(CFLAGS) -I./src -L./bin main.c -lnanafy -lbfchan -o bin/bfchan.exe

.always:
