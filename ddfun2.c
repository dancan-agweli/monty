#include "monty.h"



/**
 * ddrotl - do vicer versa value to down
 * @stack: ...
 * @line_number: ...
 */
void ddrotl(stack_t **stack, unsigned int line_number)
{
	stack_t *w, *m;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	w = (*stack)->next;
	m = (*stack)->next;
	if (m->next != NULL)
		m = m->next;

	w->next->prev = *stack;
	(*stack)->next = w->next;
	m->next = w;
	w->next = NULL;
	w->prev = m;

	(void)line_number;
}

/**
 * ddrotr - again to top vicers
 * @stack: ...
 * @line_number: ...
 */
void ddrotr(stack_t **stack, unsigned int line_number)
{
	stack_t *w, *m;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	w = (*stack)->next;
	m = (*stack)->next;
	while (m->next != NULL)
		m = m->next;

	m->prev->next = NULL;
	(*stack)->next = m;
	m->prev = *stack;
	m->next = w;
	w->prev = m;

	(void)line_number;
}

/**
 * ddstack - do question
 * @stack: ...
 * @line_number: ...
 */
void ddstack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * ddq - que
 * @stack: ...
 * @line_number: ...
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = DAN;
	(void)line_number;
}
