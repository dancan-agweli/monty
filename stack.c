#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * ddfree - a reales of stack
 * @stack: ...
 */
void ddfree(stack_t **stack)
{
	stack_t *sw = *stack;

	if (*stack)
	{
		sw = (*stack)->next;
		free(*stack);
		*stack = sw;
	}
}

/**
 * ddstack - the value to be intialize
 * @stack: ...
 * Return: always success
 */
int ddstack(stack_t **stack)
{
	stack_t *u;

	u = malloc(sizeof(stack_t));
	if (!u)
		return (ddmerror());

	u->n = STACK;
	u->prev = NULL;
	u->next = NULL;

	*stack = u;

	return (EXIT_SUCCESS);
}

/**
 * ddchk - look for the status of linked list.
 * @stack: ...
 * Return: always sucess
 */
int ddchk(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	if (stack->n == DAN)
		return (DAN);
	return (2);
}
