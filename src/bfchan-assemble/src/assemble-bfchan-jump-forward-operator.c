#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-jump-forward-operator.p"

int assemble_bfchan_jump_forward_operator (bfchan_operator *operator, bfchan *bfchanp, nanafy *nana){
	size_t offsetbegin = tell_nanafy(NANAFY_TEXT_SECTION, nana);
	if (write_nanafy(BFCHAN_JUMP_FORWARD_OPERATOR_ASSEMBLY, sizeof(BFCHAN_JUMP_FORWARD_OPERATOR_ASSEMBLY), NANAFY_TEXT_SECTION, nana) != 0){
		return 1;
	}
	size_t offset = tell_nanafy(NANAFY_TEXT_SECTION, nana);
	if (put_nanafy_offset(NANAFY_TEXT_SECTION, 0, 4, nana) != 0){
		return 1;
	}
	size_t offsetend = tell_nanafy(NANAFY_TEXT_SECTION, nana);
	operator->operator.jump.offset = offset;
	operator->operator.jump.offsetbegin = offsetbegin;
	operator->operator.jump.offsetend = offsetend;
	operator->operator.jump.size = 4; // width=4
	return 0;
}
