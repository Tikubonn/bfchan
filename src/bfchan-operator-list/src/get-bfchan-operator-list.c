#include <bfchan.h>
#include <stddef.h>

int get_bfchan_operator_list (size_t index, bfchan_operator_list *list, bfchan_operator *operator){
	if (index < list->seek){
		*operator = list->sequence[index];
		return 0;
	}
	return 1;
}
