#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-inc-operator.p"

int assemble_bfchan_inc_operator (bfchan_operator *op, bfchan *bfchanp, nanafy *nana){
	return write_nanafy(BFCHAN_INC_OPERATOR_ASSEMBLY, sizeof(BFCHAN_INC_OPERATOR_ASSEMBLY), NANAFY_TEXT_SECTION, nana);
}
