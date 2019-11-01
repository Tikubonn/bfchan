#include <bfchan.h>

int put_bfchan_manually (char character, bfchan *bfchanp){
	bfchan_operator operator;
	switch (character){
		case '>': 
			operator.type = BFCHAN_INC_ADDR_OPERATOR;
			break;
		case '<': 
			operator.type = BFCHAN_DEC_ADDR_OPERATOR;
			break;
		case '+': 
			operator.type = BFCHAN_INC_OPERATOR;
			break;
		case '-': 
			operator.type = BFCHAN_DEC_OPERATOR;
			break;
		case '.': 
			operator.type = BFCHAN_PUT_OPERATOR;
			break;
		case ',': 
			operator.type = BFCHAN_GET_OPERATOR;
			break;
		case '[': 
			operator.type = BFCHAN_JUMP_FORWARD_OPERATOR;
			break;
		case ']': 
			operator.type = BFCHAN_JUMP_BACKWARD_OPERATOR;
			break;
		default:
			return 0; // ignore unsupported character!
	}
	if (add_bfchan_operator_list(&operator, &(bfchanp->operator_list)) != 0){
		return 1;
	}
	return 0;
}
