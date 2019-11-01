#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-inc-addr-operator.p"

int assemble_bfchan_inc_addr_operator (bfchan_operator *op, bfchan *bfchanp, nanafy *nana){
	return write_nanafy(BFCHAN_INC_ADDR_OPERATOR_ASSEMBLY, sizeof(BFCHAN_INC_ADDR_OPERATOR_ASSEMBLY), NANAFY_TEXT_SECTION, nana);
}
