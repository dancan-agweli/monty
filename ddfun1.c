#include "monty.h"


/**
 * ddnop - prints absolute values
 * @stack: ...
 * @line_number: ...
 */
void ddnop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * ddpchar - the character display
 * @stack: ...
 * @line_number: ...
 */
void ddpchar(stack_t **stack, unsigned int line_number)
{
	while ((*stack)->next == NULL)
	{
		ddsterr(ddpcharerr(line_number, "the empty stack"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		ddsterr(ddpcharerr(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * ddpstr - write the string in linked list
 * @stack: ...
 * @line_number: ...
 */
void ddpstr(stack_t **stack, unsigned int line_number)
{
	stack_t *sw = (*stack)->next;

	if (sw && sw->n != 0 && (sw->n > 0 && sw->n <= 127))
	{
		printf("%c", sw->n);
		sw = sw->next;
	}

	printf("\n");

	(void)line_number;
}
