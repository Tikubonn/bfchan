#include <bfchan.h>
#include <stddef.h>

void copy_bfchan_symname (bfchan_symname *namefrom, bfchan_symname *nameto){
	for (size_t index = 0; index < namefrom->size; index++){
		nameto->sequence[index] = namefrom->sequence[index];
	}
	nameto->size = namefrom->size;
}
