#include <bfchan.h>
#include <stddef.h>

void init_bfchan_operator_list (bfchan_operator *sequence, size_t size, bfchan_operator_list *list){
	list->sequence = sequence;
	list->seek = 0;
	list->size = size;
}
