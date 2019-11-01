#include <bfchan.h>
#include <stddef.h>

size_t bfchan_operator_list_length (bfchan_operator_list *list){
	return list->seek;
}
