#include <bfchan.h>
#include <stddef.h>
#define MAX(a, b) ((a)<(b)?(b):(a))

int put_bfchan (char character, bfchan *bfchanp){
	if (put_bfchan_manually(character, bfchanp) != 0){
		size_t size = bfchan_operator_list_length(&(bfchanp->operator_list));
		size_t exsize = size + MAX(1, size / 2);
		if (extend_bfchan_operator_list(exsize, &(bfchanp->operator_list)) != 0){
			return 1;
		}
		if (put_bfchan_manually(character, bfchanp) != 0){
			return 1;
		}
		return 0;
	}
	return 0;
}
