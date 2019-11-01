#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-calculation-addr-operator.p"

int assemble_bfchan_calculation_addr_operator (bfchan_operator *op, bfchan *bfchanp, nanafy *nana){
	int value = op->operator.calculation.value;
	if (value == 0){
		return 0; // skip!
	}
	else
	if (value == 1){
		return assemble_bfchan_inc_addr_operator(op, bfchanp, nana);
	}
	else
	if (value == -1){
		return assemble_bfchan_dec_addr_operator(op, bfchanp, nana);
	}
	else {
		if (write_nanafy(BFCHAN_CALCULATION_ADDR_OPERATOR_ASSEMBLY, sizeof(BFCHAN_CALCULATION_ADDR_OPERATOR_ASSEMBLY), NANAFY_TEXT_SECTION, nana) != 0){
			return 1;
		}
		if (put_nanafy(value, NANAFY_TEXT_SECTION, nana) != 0){
			return 1;
		}
		return 0;
	}
}
