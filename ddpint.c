#include "monty.h"

/**
 * ddpint -  prints the top element on the stack
 * @stack: pointer to the stack
 * @lnn: the instruction appears
 * Description: 1. pint
 * Return: answer
 */
void ddpint(stack_t **stack, unsigned int lnn)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lnn);
		fclose(dataf);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
