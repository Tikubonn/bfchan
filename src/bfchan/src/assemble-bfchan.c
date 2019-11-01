#include <bfchan.h>
#include <nanafy.h>
#include <stddef.h>

int assemble_bfchan (bfchan *bfchanp, nanafy *nana){
	// *assemble init 
	switch (bfchanp->target){
		case BFCHAN_TARGET_APPLICATION:
			if (assemble_bfchan_init(bfchanp, nana) != 0){
				return 1;
			}
			break;
		case BFCHAN_TARGET_CFUNC:
			if (assemble_bfchan_init_for_cfunc(bfchanp, nana) != 0){
				return 1;
			}
			break;
		default:
			return 1;
	}
	// *assemble main
	size_t length = bfchan_operator_list_length(&(bfchanp->operator_list));
	for (size_t index = 0; index < length; index++){
		bfchan_operator operator;
		if (get_bfchan_operator_list(index, &(bfchanp->operator_list), &operator) != 0){
			return 1;
		}
		if (assemble_bfchan_operator(&operator, bfchanp, nana) != 0){
			return 1;
		}
		if (set_bfchan_operator_list(&operator, index, &(bfchanp->operator_list)) != 0){ // udpate for some operator!
			return NANAFY_ERROR;
		}
	}
	// *assemble exit 
	if (assemble_bfchan_exit(bfchanp, nana) != 0){
		return 1;
	}
	// *fix 
	if (fix_bfchan_jump_operator(bfchanp, nana) != 0){
		return 1;
	}
	// *end
	return 0;
}
