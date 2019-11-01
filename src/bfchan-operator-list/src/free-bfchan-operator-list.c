#include <bfchan.h>
#include <stdlib.h>

void free_bfchan_operator_list (bfchan_operator_list *list){
	if (list->sequence != NULL){
		free(list->sequence);
	}
}
