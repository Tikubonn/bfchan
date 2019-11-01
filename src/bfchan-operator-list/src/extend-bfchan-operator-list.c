#include <bfchan.h>
#include <stddef.h>
#include <stdlib.h>

int extend_bfchan_operator_list (size_t size, bfchan_operator_list *list){
	bfchan_operator *newseq = realloc(list->sequence, sizeof(bfchan_operator) * size);
	if (newseq == NULL){
		return 1;
	}
	list->sequence = newseq;
	list->size = size;
	return 0;
}
