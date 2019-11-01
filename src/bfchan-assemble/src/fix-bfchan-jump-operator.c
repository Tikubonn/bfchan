#include <bfchan.h>
#include <nanafy.h>
#include <stddef.h>

static int find_jump_backward (size_t index, bfchan *bfchanp, bfchan_operator *opep){
  size_t depth = 0;
	size_t length = bfchan_operator_list_length(&(bfchanp->operator_list));
  for (size_t ind = index; ind < length; ind++){
		bfchan_operator ope;
		if (get_bfchan_operator_list(ind, &(bfchanp->operator_list), &ope) != 0){
			return 1;
		}
    if (ope.type == BFCHAN_JUMP_FORWARD_OPERATOR || 
        ope.type == BFCHAN_JUMP_FORWARD_MARKER){
      depth += 1;
    }
    else
    if (ope.type == BFCHAN_JUMP_BACKWARD_OPERATOR || 
        ope.type == BFCHAN_JUMP_BACKWARD_MARKER){
      if (0 < depth){
        depth -= 1;
      }
      else {
        *opep = ope;
        return 0;
      }
    }
  }
  return 1; // could not find closed brace!
}

int fix_bfchan_jump_operator (bfchan *bfchanp, nanafy *nana){
	size_t length = bfchan_operator_list_length(&(bfchanp->operator_list));
  for (size_t index = 0; index < length; index++){
		bfchan_operator ope;
		if (get_bfchan_operator_list(index, &(bfchanp->operator_list), &ope) != 0){
			return 1;
		}
    if (ope.type == BFCHAN_JUMP_FORWARD_OPERATOR || 
        ope.type == BFCHAN_JUMP_FORWARD_MARKER){
      bfchan_operator opend;
      if (find_jump_backward(index +1, bfchanp, &opend) != 0){
        return 1;
      }
      if (ope.type == BFCHAN_JUMP_FORWARD_OPERATOR){
        if (set_nanafy_offset(
          NANAFY_TEXT_SECTION,
          opend.operator.jump.offsetend,
          ope.operator.jump.offset,
          ope.operator.jump.size,
          nana) != 0){
          return 1;
        }
      }
      if (opend.type == BFCHAN_JUMP_BACKWARD_OPERATOR){
        if (set_nanafy_offset(
          NANAFY_TEXT_SECTION,
          ope.operator.jump.offsetend,
          opend.operator.jump.offset,
          opend.operator.jump.size,
          nana) != 0){
          return 1;
        }
      }
    }
  }
  return 0;
}
