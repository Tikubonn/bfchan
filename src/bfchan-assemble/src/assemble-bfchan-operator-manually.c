#include <bfchan.h>
#include <nanafy.h>

nanafy_status assemble_bfchan_operator_manually (bfchan_operator *operator, bfchan *bfchanp, nanafy *nana){
	switch (operator->type){
		case BFCHAN_INC_OPERATOR:
			return assemble_bfchan_inc_operator_manually(operator, bfchanp, nana);
		case BFCHAN_DEC_OPERATOR:
			return assemble_bfchan_dec_operator_manually(operator, bfchanp, nana);
		case BFCHAN_INC_ADDR_OPERATOR:
			return assemble_bfchan_inc_addr_operator_manually(operator, bfchanp, nana);
		case BFCHAN_DEC_ADDR_OPERATOR:
			return assemble_bfchan_dec_addr_operator_manually(operator, bfchanp, nana);
		case BFCHAN_CALCULATION_OPERATOR:
			return assemble_bfchan_calculation_operator_manually(operator, bfchanp, nana);
		case BFCHAN_CALCULATION_ADDR_OPERATOR:
			return assemble_bfchan_calculation_addr_operator_manually(operator, bfchanp, nana);
		case BFCHAN_ZERO_CLEAR_OPERATOR:
			return assemble_bfchan_zero_clear_operator_manually(operator, bfchanp, nana);
		case BFCHAN_ASSIGN_OPERATOR:
			return assemble_bfchan_assign_operator_manually(operator, bfchanp, nana);
		case BFCHAN_GET_OPERATOR:
			return assemble_bfchan_get_operator_manually(operator, bfchanp, nana);
		case BFCHAN_PUT_OPERATOR:
			return assemble_bfchan_put_operator_manually(operator, bfchanp, nana);
		case BFCHAN_JUMP_BACKWARD_OPERATOR:
			return assemble_bfchan_jump_backward_operator_manually(operator, bfchanp, nana);
		case BFCHAN_JUMP_FORWARD_OPERATOR:
			return assemble_bfchan_jump_forward_operator_manually(operator, bfchanp, nana);
		case BFCHAN_JUMP_BACKWARD_MARKER:
			return assemble_bfchan_jump_backward_marker_manually(operator, bfchanp, nana);
		case BFCHAN_JUMP_FORWARD_MARKER:
			return assemble_bfchan_jump_forward_marker_manually(operator, bfchanp, nana);
		default:
			return NANAFY_ERROR;
	}
}
