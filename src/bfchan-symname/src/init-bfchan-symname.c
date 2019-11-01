#include <bfchan.h>
#include <stddef.h>

int init_bfchan_symname (char *sequence, size_t size, bfchan_symname *symname){
	if (size +1 < BFCHAN_SYMNAME_LENGTH){
		symname->sequence[0] = '_'; // put an underbar to prefix!
		for (size_t index = 0; index < size; index++){
			symname->sequence[index +1] = sequence[index];
		}
		symname->size = size +1;
		return 0;
	}
	return 1; // sequence size is too long!
}
