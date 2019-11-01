#include <bfchan.h>
#include <stddef.h>

void init_bfchan (bfchan_target target, bfchan_symname *symname, bfchan_operator *listseq, size_t listsize, bfchan_operator *optlistseq, size_t optlistsize, size_t workingmemorysize, bfchan *bfchanp){
	bfchanp->target = target;
	copy_bfchan_symname(symname, &(bfchanp->symname));
	bfchanp->symgetchar = 0; // initialization is unnecessary!
	bfchanp->symputchar = 0; // initialization is unnecessary!
	bfchanp->workingmemorysize = workingmemorysize;
	init_bfchan_operator_list(listseq, listsize, &(bfchanp->operator_list));
	init_bfchan_operator_list(optlistseq, optlistsize, &(bfchanp->opt_operator_list));
}
