#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-get-operator.p"

nanafy_status assemble_bfchan_get_operator_manually (bfchan_operator *operator, bfchan *bfchanp, nanafy *nana){
	nanafy_status status;
	status = write_nanafy_manually(BFCHAN_GET_OPERATOR_ASSEMBLY1, sizeof(BFCHAN_GET_OPERATOR_ASSEMBLY1), NANAFY_TEXT_SECTION, nana);
	if (status != NANAFY_SUCCESS){
		return status;
	}
	status = put_nanafy_external_relative_offset_manually(bfchanp->symgetchar, NANAFY_TEXT_SECTION, 4, nana);
	if (status != NANAFY_SUCCESS){
		return status;
	}
	status = write_nanafy_manually(BFCHAN_GET_OPERATOR_ASSEMBLY2, sizeof(BFCHAN_GET_OPERATOR_ASSEMBLY2), NANAFY_TEXT_SECTION, nana);
	if (status != NANAFY_SUCCESS){
		return status;
	}
	return NANAFY_SUCCESS;
}
