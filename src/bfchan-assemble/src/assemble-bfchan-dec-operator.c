#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-dec-operator.p"

int assemble_bfchan_dec_operator (bfchan_operator *op, bfchan *bfchanp, nanafy *nana){
	return write_nanafy(BFCHAN_DEC_OPERATOR_ASSEMBLY, sizeof(BFCHAN_DEC_OPERATOR_ASSEMBLY), NANAFY_TEXT_SECTION, nana);
}
