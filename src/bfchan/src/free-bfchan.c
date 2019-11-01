#include <bfchan.h>
#include <stdlib.h>

void free_bfchan (bfchan *bfchanp){
	free_bfchan_operator_list(&(bfchanp->operator_list));
	free_bfchan_operator_list(&(bfchanp->opt_operator_list));
	free(bfchanp);
}
