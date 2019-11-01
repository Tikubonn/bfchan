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

static int find_next (size_t index, bfchan_operator_list *list, size_t *nextp){
  size_t depth = 0;
  size_t length = bfchan_operator_list_length(list);
  for (size_t ind = index; ind < length; ind++){
    bfchan_operator op;
    if (get_bfchan_operator_list(ind, list, &op) != 0){
      return 1;
    }
    if (op.type == BFCHAN_JUMP_FORWARD_OPERATOR || 
        op.type == BFCHAN_JUMP_FORWARD_MARKER){
      depth += 1;
    }
    else
    if (op.type == BFCHAN_JUMP_BACKWARD_OPERATOR || 
        op.type == BFCHAN_JUMP_BACKWARD_MARKER){
      if (0 < depth){
        depth -= 1;
      }
      else {
        *nextp = ind +1;
        return 0;
      }
    }
  }
  return 1; // could not found closed brace!
}

/*
  既に結果が決まっているジャンプ命令を最適化します。
*/

int optimize_bfchan_jump_forward_operator (size_t index, bfchan_operator_list *listfrom, bfchan_operator_list *listto, size_t *nextp){
  size_t length = bfchan_operator_list_length(listfrom);
  if (index +1 < length){
    bfchan_operator op1;
    bfchan_operator op2;
    if (get_bfchan_operator_list(index +0, listfrom, &op1) != 0 || 
        get_bfchan_operator_list(index +1, listfrom, &op2) != 0){
      return 1;
    }
    /*
      コードが常に実行されない場合(デッドコード)。
    */
    if ((op1.type == BFCHAN_ZERO_CLEAR_OPERATOR || 
         (op1.type == BFCHAN_ASSIGN_OPERATOR &&
          op1.operator.calculation.value == 0)) &&  
        op2.type == BFCHAN_JUMP_FORWARD_OPERATOR){
      size_t next;
      if (find_next(index +2, listfrom, &next) != 0){
        return 1;
      }
      *nextp = next;
      return 0;
    }
    /*
      コードが常に実行される場合(比較とジャンプ命令が不要になる)。
    */
    else
    if (op1.type == BFCHAN_ASSIGN_OPERATOR && 
        op1.operator.calculation.value != 0 && 
        op2.type == BFCHAN_JUMP_FORWARD_OPERATOR){
      if (add_bfchan_operator_list(&op1, listto) != 0){
        return 1;
      }
      bfchan_operator opr;
      opr.type = BFCHAN_JUMP_FORWARD_MARKER;
      if (add_bfchan_operator_list(&opr, listto) != 0){
        return 1;
      }
      *nextp = index +2;
      return 0;
    }
    /*
      上記に当てはまらない場合にはそのまま返します。
    */
    else {
      return skip(index, listfrom, listto, nextp); //skip!
    }
  }
  else {
    return skip(index, listfrom, listto, nextp); //skip!
  }
}
