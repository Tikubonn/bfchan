#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-inc-operator.p"

nanafy_status assemble_bfchan_inc_operator_manually (bfchan_operator *op, bfchan *bfchanp, nanafy *nana){
	return write_nanafy_manually(BFCHAN_INC_OPERATOR_ASSEMBLY, sizeof(BFCHAN_INC_OPERATOR_ASSEMBLY), NANAFY_TEXT_SECTION, nana);
}
