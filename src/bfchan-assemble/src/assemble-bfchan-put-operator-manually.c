#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-put-operator.p"

nanafy_status assemble_bfchan_put_operator_manually (bfchan_operator *op, bfchan *bfchanp, nanafy *nana){
	nanafy_status status;
	status = write_nanafy_manually(BFCHAN_PUT_OPERATOR_ASSEMBLY1, sizeof(BFCHAN_PUT_OPERATOR_ASSEMBLY1), NANAFY_TEXT_SECTION, nana);
	if (status != NANAFY_SUCCESS){
		return NANAFY_ERROR;
	}
	status = put_nanafy_external_relative_offset_manually(bfchanp->symputchar, NANAFY_TEXT_SECTION, 4, nana);
	if (status != NANAFY_SUCCESS){
		return NANAFY_ERROR;
	}
	status = write_nanafy_manually(BFCHAN_PUT_OPERATOR_ASSEMBLY2, sizeof(BFCHAN_PUT_OPERATOR_ASSEMBLY2), NANAFY_TEXT_SECTION, nana);
	if (status != NANAFY_SUCCESS){
		return NANAFY_ERROR;
	}
	return NANAFY_SUCCESS;
}
