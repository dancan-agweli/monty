#include "monty.h"


/**
 * ddadd - print top two values
 * @stack: a pointer address
 * @line_number: The working value
 * Description: Give out result.
 */
void ddadd(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		ddsterr(ddstackerr(line_number, "addition"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	ddpop(stack, line_number);
}

/**
 * ddsub - prints subtraction
 * @stack: ...
 * @line_number: ...
 * Description: The result of the data
 */
void ddsub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		ddsterr(ddstackerr(line_number, "subtraction"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	ddpop(stack, line_number);
}

/**
 * dddiv - prints division of the numbers
 * @stack: ...
 * @line_number: ...
 * Description: the value is stored
 */
void dddiv(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		ddsterr(ddstackerr(line_number, "divide"));
		return;
	}

	while ((*stack)->next->n == 0)
	{
		ddsterr(dddiver(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	ddpop(stack, line_number);
}

/**
 * ddmul - multiplication of numbers
 * @stack: ...
 * @line_number: ...
 * Description: the data of the multiplication in linked list
 */
void ddmul(stack_t **stack, unsigned int line_number)
{
	while ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		ddsterr(ddstackerr(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	ddpop(stack, line_number);
}

/**
 * ddmod - do it in modulation form
 * @stack: ...
 * @line_number: ...
 * Description: the data on the  modulation.
 */
void ddmod(stack_t **stack, unsigned int line_number)
{
	while ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		ddsterr(ddstackerr(line_number, "modulation"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		ddsterr(dddiver(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	ddpop(stack, line_number);
}
