#include <bfchan.h>
#include <stddef.h>

void bfchan_symname_basename (bfchan_symname *symname, char **sequencep, size_t *sizep){
	*sequencep = symname->sequence +1;
	*sizep = symname->size -1;
}
