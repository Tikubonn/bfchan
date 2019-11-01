#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-calculation-addr-operator.p"

nanafy_status assemble_bfchan_calculation_addr_operator_manually (bfchan_operator *op, bfchan *bfchanp, nanafy *nana){
	int value = op->operator.calculation.value;
	if (value == 0){
		return NANAFY_SUCCESS; // skip!
	}
	else
	if (value == 1){
		return assemble_bfchan_inc_addr_operator_manually(op, bfchanp, nana);
	}
	else
	if (value == -1){
		return assemble_bfchan_dec_addr_operator_manually(op, bfchanp, nana);
	}
	else {
		nanafy_status status;
		status = write_nanafy_manually(BFCHAN_CALCULATION_ADDR_OPERATOR_ASSEMBLY, sizeof(BFCHAN_CALCULATION_ADDR_OPERATOR_ASSEMBLY), NANAFY_TEXT_SECTION, nana);
		if (status != NANAFY_SUCCESS){
			return status;
		}
		status = put_nanafy_manually(value, NANAFY_TEXT_SECTION, nana);
		if (status != NANAFY_SUCCESS){
			return status;
		}
		return NANAFY_SUCCESS;
	}
}
