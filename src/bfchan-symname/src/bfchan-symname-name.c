#include <bfchan.h>
#include <stddef.h>

void bfchan_symname_name (bfchan_symname *symname, char **sequencep, size_t *sizep){
	*sequencep = symname->sequence;
	*sizep = symname->size;
}
