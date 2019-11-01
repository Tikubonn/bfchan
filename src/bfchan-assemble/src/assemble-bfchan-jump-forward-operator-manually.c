#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-jump-forward-operator.p"

nanafy_status assemble_bfchan_jump_forward_operator_manually (bfchan_operator *operator, bfchan *bfchanp, nanafy *nana){
	size_t offsetbegin = tell_nanafy(NANAFY_TEXT_SECTION, nana);
	nanafy_status status;
	status = write_nanafy_manually(BFCHAN_JUMP_FORWARD_OPERATOR_ASSEMBLY, sizeof(BFCHAN_JUMP_FORWARD_OPERATOR_ASSEMBLY), NANAFY_TEXT_SECTION, nana);
	if (status != NANAFY_SUCCESS){
		return NANAFY_ERROR;
	}
	size_t offset = tell_nanafy(NANAFY_TEXT_SECTION, nana);
	status = put_nanafy_offset_manually(NANAFY_TEXT_SECTION, 0, 4, nana);
	if (status != NANAFY_SUCCESS){
		return NANAFY_ERROR;
	}
	size_t offsetend = tell_nanafy(NANAFY_TEXT_SECTION, nana);
	operator->operator.jump.offset = offset;
	operator->operator.jump.offsetbegin = offsetbegin;
	operator->operator.jump.offsetend = offsetend;
	operator->operator.jump.size = 4; // width=4
	return NANAFY_SUCCESS;
}
