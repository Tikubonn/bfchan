#include <bfchan.h>
#include <nanafy.h>
#include <stddef.h>

nanafy_status assemble_bfchan_manually (bfchan *bfchanp, nanafy *nana){
	nanafy_status status;
	// *assemble init 
	switch (bfchanp->target){
		case BFCHAN_TARGET_APPLICATION:
			status = assemble_bfchan_init_manually(bfchanp, nana);
			if (status != NANAFY_SUCCESS){
				return status;
			}
			break;
		case BFCHAN_TARGET_CFUNC:
			status = assemble_bfchan_init_for_cfunc_manually(bfchanp, nana);
			if (status != NANAFY_SUCCESS){
				return status;
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
			return NANAFY_ERROR;
		}
		nanafy_status status = assemble_bfchan_operator_manually(&operator, bfchanp, nana);
		if (status != NANAFY_SUCCESS){
			return status;
		}
		if (set_bfchan_operator_list(&operator, index, &(bfchanp->operator_list)) != 0){ // udpate for some operator!
			return NANAFY_ERROR;
		}
	}
	// *assemble exit
	status = assemble_bfchan_exit_manually(bfchanp, nana);
	if (status != NANAFY_SUCCESS){
		return NANAFY_ERROR;
	}
	// *fix 
	if (fix_bfchan_jump_operator(bfchanp, nana) != 0){
		return NANAFY_ERROR;
	}
	// *end
	return NANAFY_SUCCESS;
}
