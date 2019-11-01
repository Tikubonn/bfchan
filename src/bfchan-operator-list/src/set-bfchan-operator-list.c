#include <bfchan.h>
#include <stddef.h>

int set_bfchan_operator_list (bfchan_operator *operator, size_t index, bfchan_operator_list *list){
	if (index < list->seek){
		list->sequence[index] = *operator;
		return 0;
	}
	return 1;
}
