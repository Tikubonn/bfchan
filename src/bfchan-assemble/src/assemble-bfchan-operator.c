#include <bfchan.h>
#include <nanafy.h>

int assemble_bfchan_operator (bfchan_operator *operator, bfchan *bfchanp, nanafy *nana){
	switch (operator->type){
		case BFCHAN_INC_OPERATOR:
			return assemble_bfchan_inc_operator(operator, bfchanp, nana);
		case BFCHAN_DEC_OPERATOR:
			return assemble_bfchan_dec_operator(operator, bfchanp, nana);
		case BFCHAN_INC_ADDR_OPERATOR:
			return assemble_bfchan_inc_addr_operator(operator, bfchanp, nana);
		case BFCHAN_DEC_ADDR_OPERATOR:
			return assemble_bfchan_dec_addr_operator(operator, bfchanp, nana);
		case BFCHAN_CALCULATION_OPERATOR:
			return assemble_bfchan_calculation_operator(operator, bfchanp, nana);
		case BFCHAN_CALCULATION_ADDR_OPERATOR:
			return assemble_bfchan_calculation_addr_operator(operator, bfchanp, nana);
		case BFCHAN_ZERO_CLEAR_OPERATOR:
			return assemble_bfchan_zero_clear_operator(operator, bfchanp, nana);
		case BFCHAN_ASSIGN_OPERATOR:
			return assemble_bfchan_assign_operator(operator, bfchanp, nana);
		case BFCHAN_GET_OPERATOR:
			return assemble_bfchan_get_operator(operator, bfchanp, nana);
		case BFCHAN_PUT_OPERATOR:
			return assemble_bfchan_put_operator(operator, bfchanp, nana);
		case BFCHAN_JUMP_BACKWARD_OPERATOR:
			return assemble_bfchan_jump_backward_operator(operator, bfchanp, nana);
		case BFCHAN_JUMP_FORWARD_OPERATOR:
			return assemble_bfchan_jump_forward_operator(operator, bfchanp, nana);
		case BFCHAN_JUMP_BACKWARD_MARKER:
			return assemble_bfchan_jump_backward_marker(operator, bfchanp, nana);
		case BFCHAN_JUMP_FORWARD_MARKER:
			return assemble_bfchan_jump_forward_marker(operator, bfchanp, nana);
		default:
			return 1;
	}
}
