#include <bfchan.h>
#include <nanafy.h>
#include "assemble-bfchan-assign-operator.p"

int assemble_bfchan_assign_operator (bfchan_operator *operator, bfchan *bfchanp, nanafy *nana){
	int value = operator->operator.calculation.value;
	if (value == 0){
		return assemble_bfchan_zero_clear_operator(operator, bfchanp, nana);
	}
	else {
		if (write_nanafy(BFCHAN_ASSIGN_OPERATOR_ASSEMBLY1, sizeof(BFCHAN_ASSIGN_OPERATOR_ASSEMBLY1), NANAFY_TEXT_SECTION, nana) != 0){
			return 1;
		}
		if (put_nanafy(value, NANAFY_TEXT_SECTION, nana) != 0){
			return 1;
		}
		if (write_nanafy(BFCHAN_ASSIGN_OPERATOR_ASSEMBLY2, sizeof(BFCHAN_ASSIGN_OPERATOR_ASSEMBLY2), NANAFY_TEXT_SECTION, nana) != 0){
			return 1;
		}
		return 0;
	}
}
