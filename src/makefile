
export CFLAGS += -I$(CURDIR)

default:

clean:
	rm -f bfchan.lib
	rm -f bfchan.dll
	rm -f bfchan.h
	make clean -C bfchan-operator-list
	make clean -C bfchan-optimize
	make clean -C bfchan-assemble
	make clean -C bfchan
	make clean -C bfchan-utility
	make clean -C bfchan-symname
	make clean -C bfchan-assemble-for-cfunc
	make clean -C bfchan-cheader

h: .always
	make bfchan-operator-list.h -C bfchan-operator-list
	make bfchan-optimize.h -C bfchan-optimize
	make bfchan-assemble.h -C bfchan-assemble
	make bfchan.h -C bfchan
	make bfchan-utility.h -C bfchan-utility
	make bfchan-symname.h -C bfchan-symname
	make bfchan-assemble-for-cfunc.h -C bfchan-assemble-for-cfunc
	make bfchan-cheader.h -C bfchan-cheader
	make bfchan.h

lib: .always
	make bfchan-operator-list.lib -C bfchan-operator-list
	make bfchan-optimize.lib -C bfchan-optimize
	make bfchan-assemble.lib -C bfchan-assemble
	make bfchan.lib -C bfchan
	make bfchan-utility.lib -C bfchan-utility
	make bfchan-symname.lib -C bfchan-symname
	make bfchan-assemble-for-cfunc.lib -C bfchan-assemble-for-cfunc
	make bfchan-cheader.lib -C bfchan-cheader
	make bfchan.lib

dll: .always
	make bfchan-operator-list.lib -C bfchan-operator-list
	make bfchan-optimize.lib -C bfchan-optimize
	make bfchan-assemble.lib -C bfchan-assemble
	make bfchan.lib -C bfchan
	make bfchan-utility.lib -C bfchan-utility
	make bfchan-symname.lib -C bfchan-symname
	make bfchan-assemble-for-cfunc.lib -C bfchan-assemble-for-cfunc
	make bfchan-cheader.lib -C bfchan-cheader
	make bfchan.dll

tempdir = $(shell mktemp -d)
workdir := $(CURDIR)

bfchan.h: bfchan.p bfchan-operator-list/bfchan-operator-list.h bfchan-optimize/bfchan-optimize.h bfchan-assemble/bfchan-assemble.h bfchan/bfchan.h bfchan-utility/bfchan-utility.h bfchan-symname/bfchan-symname.h bfchan-assemble-for-cfunc/bfchan-assemble-for-cfunc.h bfchan-cheader/bfchan-cheader.h
	cat bfchan.p bfchan-operator-list/bfchan-operator-list.h bfchan-optimize/bfchan-optimize.h bfchan-assemble/bfchan-assemble.h bfchan/bfchan.h bfchan-utility/bfchan-utility.h bfchan-symname/bfchan-symname.h bfchan-assemble-for-cfunc/bfchan-assemble-for-cfunc.h bfchan-cheader/bfchan-cheader.h > bfchan.h

bfchan.lib: bfchan-operator-list/bfchan-operator-list.lib bfchan-optimize/bfchan-optimize.lib bfchan-assemble/bfchan-assemble.lib bfchan/bfchan.lib bfchan-utility/bfchan-utility.lib bfchan-symname/bfchan-symname.lib bfchan-assemble-for-cfunc/bfchan-assemble-for-cfunc.lib bfchan-cheader/bfchan-cheader.lib
	cd $(tempdir) && \
	ar x $(workdir)/bfchan-operator-list/bfchan-operator-list.lib && \
	ar x $(workdir)/bfchan-optimize/bfchan-optimize.lib && \
	ar x $(workdir)/bfchan-assemble/bfchan-assemble.lib && \
	ar x $(workdir)/bfchan/bfchan.lib && \
	ar x $(workdir)/bfchan-utility/bfchan-utility.lib && \
	ar x $(workdir)/bfchan-symname/bfchan-symname.lib && \
	ar x $(workdir)/bfchan-assemble-for-cfunc/bfchan-assemble-for-cfunc.lib && \
	ar x $(workdir)/bfchan-cheader/bfchan-cheader.lib && \
	ar r $(workdir)/bfchan.lib *.o

bfchan.dll: bfchan-operator-list/bfchan-operator-list.lib bfchan-optimize/bfchan-optimize.lib bfchan-assemble/bfchan-assemble.lib bfchan/bfchan.lib bfchan-utility/bfchan-utility.lib bfchan-symname/bfchan-symname.lib bfchan-assemble-for-cfunc/bfchan-assemble-for-cfunc.lib bfchan-cheader/bfchan-cheader.lib
	cd $(tempdir) && \
	ar x $(workdir)/bfchan-operator-list/bfchan-operator-list.lib && \
	ar x $(workdir)/bfchan-optimize/bfchan-optimize.lib && \
	ar x $(workdir)/bfchan-assemble/bfchan-assemble.lib && \
	ar x $(workdir)/bfchan/bfchan.lib && \
	ar x $(workdir)/bfchan-utility/bfchan-utility.lib && \
	ar x $(workdir)/bfchan-symname/bfchan-symname.lib && \
	ar x $(workdir)/bfchan-assemble-for-cfunc/bfchan-assemble-for-cfunc.lib && \
	ar x $(workdir)/bfchan-cheader/bfchan-cheader.lib && \
	gcc $(CFLAGS) *.o -lnanafy -shared -o $(workdir)/bfchan.dll 

.always:
