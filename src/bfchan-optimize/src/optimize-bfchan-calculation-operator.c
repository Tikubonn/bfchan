#include <bfchan.h>
#include <stddef.h>

int optimize_bfchan_calculation_operator (size_t index, bfchan_operator_list *listfrom, bfchan_operator_list *listto, size_t *nextp){
	bfchan_operator op1;
	if (get_bfchan_operator_list(index, listfrom, &op1) != 0){
		return 1;
	}
	int value;
	if (op1.type == BFCHAN_INC_OPERATOR){
		value = 1;
	}
	else
	if (op1.type == BFCHAN_DEC_OPERATOR){
		value = -1;
	}
	else {
		if (add_bfchan_operator_list(&op1, listto) != 0){
			return 1;
		}
		*nextp = index +1;
		return 0;
	}
	size_t length = bfchan_operator_list_length(listfrom);
	for (size_t ind = 1; index + ind < length; ind++){
		bfchan_operator opn;
		if (get_bfchan_operator_list(index + ind, listfrom, &opn) != 0){
			return 1;
		}
		if (opn.type == BFCHAN_INC_OPERATOR){
			value += 1;
		}
		else 
		if (opn.type == BFCHAN_DEC_OPERATOR){
			value -= 1;
		}
		else {
			if (value != 0){
				bfchan_operator opr;
				opr.type = BFCHAN_CALCULATION_OPERATOR;
				opr.operator.calculation.value = value;
				if (add_bfchan_operator_list(&opr, listto) != 0){
					return 1;
				}
				*nextp = index + ind;
				return 0;
			}
			else {
				*nextp = index + ind;
				return 0;
			}
		}
	}
	bfchan_operator opr;
	opr.type = BFCHAN_CALCULATION_OPERATOR;
	opr.operator.calculation.value = value;
	if (add_bfchan_operator_list(&opr, listto) != 0){
		return 1;
	}
	*nextp = index + 1;
	return 0;
}
