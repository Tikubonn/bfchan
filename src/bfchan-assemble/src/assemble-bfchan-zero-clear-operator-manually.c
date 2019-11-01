#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-zero-clear-operator.p"

nanafy_status assemble_bfchan_zero_clear_operator_manually (bfchan_operator *op, bfchan *bfchanp, nanafy *nana){
	return write_nanafy_manually(BFCHAN_ZERO_CLEAR_OPERATOR_ASSEMBLY, sizeof(BFCHAN_ZERO_CLEAR_OPERATOR_ASSEMBLY), NANAFY_TEXT_SECTION, nana);
}
