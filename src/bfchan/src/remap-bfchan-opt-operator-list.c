#include <bfchan.h>
#include <stddef.h>

int remap_bfchan_opt_operator_list (bfchan_operator *sequence, size_t size, bfchan *bfchanp){
	bfchan_operator_list newlist;
	init_bfchan_operator_list(sequence, size, &newlist);
	if (copy_bfchan_operator_list(&(bfchanp->opt_operator_list), &newlist) != 0){
		return 1;
	}
	bfchanp->opt_operator_list = newlist;
	return 0;
}
