#include "monty.h"

/**
 * ddadd - function to add values
 * @stack: pointer to address oof num
 *
 * @lnn: ...
 * Description: add and sub
 * Return: answer
 */
void ddadd(stack_t **stack, unsigned int lnn)
{
	stack_t *z, *sc;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lnn);
		fclose(dataf);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		z = *stack;
		sc = z->next;
		sc->n += z->n;
		*stack = sc;
		(*stack)->prev = NULL;
		free(z);
	}
}
/**
 * ddsub - prin that subtracts the elements
 * @stack: pointer to address oof num
 * @lnn: line appearence
 * Description: add and sub
 * Return: answer
 */
void ddsub(stack_t **stack, unsigned int lnn)
{
	stack_t *z, *sc;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lnn);
		fclose(dataf);
		ddfree(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		z = *stack;
		sc = z->next;
		sc->n -= z->n;
		*stack = sc;
		(*stack)->prev = NULL;
		free(z);
	}
}
