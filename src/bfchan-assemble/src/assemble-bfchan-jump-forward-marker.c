#include <bfchan.h>
#include <nanafy.h>

int assemble_bfchan_jump_forward_marker (bfchan_operator *operator, bfchan *bfchanp, nanafy *nana){
	size_t offset = tell_nanafy(NANAFY_TEXT_SECTION, nana);
	operator->operator.jump.offset = offset;
	operator->operator.jump.offsetbegin = offset;
	operator->operator.jump.offsetend = offset;
	operator->operator.jump.size = 0; // unused member!
	return 0;
}
