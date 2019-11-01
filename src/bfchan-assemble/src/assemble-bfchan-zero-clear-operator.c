#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-zero-clear-operator.p"

int assemble_bfchan_zero_clear_operator (bfchan_operator *op, bfchan *bfchanp, nanafy *nana){
	return write_nanafy(BFCHAN_ZERO_CLEAR_OPERATOR_ASSEMBLY, sizeof(BFCHAN_ZERO_CLEAR_OPERATOR_ASSEMBLY), NANAFY_TEXT_SECTION, nana);
}
