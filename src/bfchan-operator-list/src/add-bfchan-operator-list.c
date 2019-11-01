#include <bfchan.h>
#include <stddef.h>
#define MAX(a, b) ((a)<(b)?(b):(a))

int add_bfchan_operator_list (bfchan_operator *op, bfchan_operator_list *list){
	if (add_bfchan_operator_list_manually(op, list) != 0){
		size_t exsize = list->size + MAX(1, list->size / 2);
		if (extend_bfchan_operator_list(exsize, list) != 0){
			return 1;
		}
		if (add_bfchan_operator_list_manually(op, list) != 0){
			return 1;
		}
		return 0;
	}
	return 0;
}
