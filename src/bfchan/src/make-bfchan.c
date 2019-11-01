#include <bfchan.h>
#include <stddef.h>
#include <stdlib.h>

bfchan *make_bfchan (bfchan_target target, bfchan_symname *symname, size_t size, size_t workingmemorysize){
	bfchan *bfchanp = malloc(sizeof(bfchan));
	if (bfchanp == NULL){
		return NULL;
	}
	bfchan_operator *listseq = malloc(sizeof(bfchan_operator) * size);
	if (listseq == NULL){
		free(bfchanp);
		return NULL;
	}
	bfchan_operator *optlistseq = malloc(sizeof(bfchan_operator) * size);
	if (optlistseq == NULL){
		free(bfchanp);
		free(listseq);
		return NULL;
	}
	init_bfchan(target, symname, listseq, size, optlistseq, size, workingmemorysize, bfchanp);
	return bfchanp;
}
