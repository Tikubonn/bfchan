#include <stddef.h>

extern int optimize_bfchan_assign_operator (size_t, bfchan_operator_list*, bfchan_operator_list*, size_t*);
#include <stddef.h>

extern int optimize_bfchan_calculation_addr_operator (size_t, bfchan_operator_list*, bfchan_operator_list*, size_t*);
#include <stddef.h>

extern int optimize_bfchan_calculation_operator (size_t, bfchan_operator_list*, bfchan_operator_list*, size_t*);
#include <stddef.h>

extern int optimize_bfchan_zero_clear_operator (size_t, bfchan_operator_list*, bfchan_operator_list*, size_t*);

extern int optimize_bfchan_operator (bfchan_operator_list*, bfchan_operator_list*);
#include <stddef.h>

extern int optimize_bfchan_jump_forward_operator (size_t, bfchan_operator_list*, bfchan_operator_list*, size_t*);
#include <stddef.h>

extern int optimize_bfchan_jump_backward_operator (size_t, bfchan_operator_list*, bfchan_operator_list*, size_t*);
