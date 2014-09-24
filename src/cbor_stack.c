#include "cbor_stack.h"

struct _cbor_stack _cbor_stack_init()
{
	return (struct _cbor_stack){ NULL, 0 };
}

void _cbor_stack_pop(struct _cbor_stack * stack)
{
	struct _cbor_stack_record * top = stack->top;
	stack->top = stack->top->lower;
	free(top);
}

struct _cbor_stack_record * _cbor_stack_push(struct _cbor_stack * stack, cbor_type type)
{
	struct _cbor_stack_record * new_top = malloc(sizeof(struct _cbor_stack_record));
	if (new_top == NULL) {
		return NULL;
	}
	*new_top = (struct _cbor_stack_record){ stack->top, type };
	stack->top = new_top;
	return new_top;
}