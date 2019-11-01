#include <bfchan.h>
#include <stddef.h>

static int skip (size_t index, bfchan_operator_list *listfrom, bfchan_operator_list *listto, size_t *nextp){
	bfchan_operator op;
	if (get_bfchan_operator_list(index, listfrom, &op) != 0){
		return 1;
	}
	if (add_bfchan_operator_list(&op, listto) != 0){
		return 1;
	}
	*nextp = index +1;
	return 0;
}

int optimize_bfchan_assign_operator (size_t index, bfchan_operator_list *listfrom, bfchan_operator_list *listto, size_t *nextp){
	size_t length = bfchan_operator_list_length(listfrom);
	if (index + 2 < length){
		bfchan_operator op1;
		bfchan_operator op2;
		if (get_bfchan_operator_list(index +0, listfrom, &op1) != 0 || 
				get_bfchan_operator_list(index +1, listfrom, &op2) != 0){
			return 1;
		}
		if (op1.type == BFCHAN_ZERO_CLEAR_OPERATOR && 
				op2.type == BFCHAN_CALCULATION_OPERATOR){
			bfchan_operator opr;
			opr.type = BFCHAN_ASSIGN_OPERATOR;
			opr.operator.calculation.value = 
				op2.operator.calculation.value;
			if (add_bfchan_operator_list(&opr, listto) != 0){
				return 1;
			}
			*nextp = index +2;
			return 0;
		}
		return skip(index, listfrom, listto, nextp); // skip!
	}
	else {
		return skip(index, listfrom, listto, nextp); // skip!
	}
}
