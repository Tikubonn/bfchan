#include <bfchan.h>

int optimize_bfchan (bfchan *bfchanp){
	return optimize_bfchan_operator(
		&(bfchanp->operator_list),
		&(bfchanp->opt_operator_list)
	);
}
