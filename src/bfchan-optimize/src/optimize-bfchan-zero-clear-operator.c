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

int optimize_bfchan_zero_clear_operator (size_t index, bfchan_operator_list *listfrom, bfchan_operator_list *listto, size_t *nextp){
	size_t length = bfchan_operator_list_length(listfrom);
	if (index +3 < length){
		bfchan_operator ope1;
		bfchan_operator ope2;
		bfchan_operator ope3;
		if (get_bfchan_operator_list(index +0, listfrom, &ope1) != 0 || 
				get_bfchan_operator_list(index +1, listfrom, &ope2) != 0 || 
				get_bfchan_operator_list(index +2, listfrom, &ope3) != 0){
			return 1;
		}
		if (ope1.type == BFCHAN_JUMP_FORWARD_OPERATOR && 
				((ope2.type == BFCHAN_INC_OPERATOR || ope2.type == BFCHAN_DEC_OPERATOR) ||
				 (ope2.type == BFCHAN_CALCULATION_OPERATOR && ope2.operator.calculation.value != 0)) && 
				ope3.type == BFCHAN_JUMP_BACKWARD_OPERATOR){
			bfchan_operator ope;
			ope.type = BFCHAN_ZERO_CLEAR_OPERATOR;
			if (add_bfchan_operator_list(&ope, listto) != 0){
				return 1;
			}
			*nextp = index +3;
			return 0;
		}
		return skip(index, listfrom, listto, nextp); // skip!
	}
	return skip(index, listfrom, listto, nextp); // skip!
}
