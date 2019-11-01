#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-dec-addr-operator.p"

nanafy_status assemble_bfchan_dec_addr_operator_manually (bfchan_operator *op, bfchan *bfchanp, nanafy *nana){
	return write_nanafy_manually(BFCHAN_DEC_ADDR_OPERATOR_ASSEMBLY, sizeof(BFCHAN_DEC_ADDR_OPERATOR_ASSEMBLY), NANAFY_TEXT_SECTION, nana);
}
