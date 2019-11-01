#include <bfchan.h>
#include <stddef.h>

int copy_bfchan_operator_list (bfchan_operator_list *listfrom, bfchan_operator_list *listto){
	if (listfrom->seek <= listto->size){
		for (size_t index = 0; index < listfrom->seek; index++){
			listto->sequence[index] = listfrom->sequence[index];
		}
		listto->seek = listfrom->seek;
		return 0;
	}
	return 1;
}
