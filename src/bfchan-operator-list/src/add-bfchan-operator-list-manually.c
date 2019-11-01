#include <bfchan.h>
#include <stddef.h>

int add_bfchan_operator_list_manually (bfchan_operator *op, bfchan_operator_list *list){
	if (list->seek < list->size){
		list->sequence[list->seek] = *op;
		list->seek += 1;
		return 0;
	}
	return 1;
}
