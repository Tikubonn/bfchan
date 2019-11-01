#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-assign-operator.p"

nanafy_status assemble_bfchan_assign_operator_manually (bfchan_operator *operator, bfchan *bfchanp, nanafy *nana){
	int value = operator->operator.calculation.value;
	if (value == 0){
		return assemble_bfchan_zero_clear_operator_manually(operator, bfchanp, nana);
	}
	else {
		nanafy_status status;
		status = write_nanafy_manually(BFCHAN_ASSIGN_OPERATOR_ASSEMBLY1, sizeof(BFCHAN_ASSIGN_OPERATOR_ASSEMBLY1), NANAFY_TEXT_SECTION, nana);
		if (status != NANAFY_SUCCESS){
			return status;
		}
		status = put_nanafy_manually(value, NANAFY_TEXT_SECTION, nana);
		if (status != NANAFY_SUCCESS){
			return status;
		}
		status = write_nanafy_manually(BFCHAN_ASSIGN_OPERATOR_ASSEMBLY2, sizeof(BFCHAN_ASSIGN_OPERATOR_ASSEMBLY2), NANAFY_TEXT_SECTION, nana);
		if (status != NANAFY_SUCCESS){
			return status;
		}
		return NANAFY_SUCCESS;
	}
}
