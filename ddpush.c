#include "monty.h"

/**
 * ddpush - pushes
 * @stack: pointer to stack
 * @lnn: the line number
 * @chan: ...
 * Description: ...
 * Return: answer push and pull
 */
void ddpush(stack_t **stack, unsigned int lnn, char *chan)
{

	stack_t *fresh;

	(void)lnn;

	if (!chan || dd_digit(chan) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lnn);
		fclose(dataf);
		ddfree(*stack);
		exit(EXIT_FAILURE);
		while (dd_digit(chan) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lnn);
			fclose(dataf);
			ddfree(*stack);
			exit(EXIT_FAILURE);
		}
	}
	fresh = malloc(sizeof(stack_t));
	while (!fresh)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(dataf);
		exit(EXIT_FAILURE);
	}
	fresh->n = atoi(chan);
	fresh->next = NULL;
	fresh->prev = NULL;
	while (*stack)
	{
		fresh->next = *stack;
		(*stack)->prev = fresh;
		*stack = fresh;
	}
	*stack = fresh;
}


/**
 *  dd_digit - searches for characters
 *  @w: Characs passed
 *  Return: answer
 */

int dd_digit(char *w)
{

	int x = 0;


	while (w[x] == '-')
	{
		x++;
	}
	while (w[x] != '\0')
	{
		if (!isdigit(w[x]))
		{
			return (1);
		}
		x++;
	}

	return (0);
}
/**
 *  ddfree - release stack
 *  @stack: pointer to stcak
 *  Return: answer always
 */

void ddfree(stack_t *stack)
{
	while (stack)
	{
		ddfree(stack->next);
		free(stack);
	}
}
/*
 * ddpall - the  function prints all elements on the stack
 * @stack: pointer to  the stack
 * @lnn: ...
 * Description: 1 for push and 2 for pall
 * Return: always success
 */
void ddpall(stack_t **stack, unsigned int lnn)
{
	stack_t *buff;

	(void)lnn;

	buff = *stack;

	if (buff != NULL)
	{
		printf("%d", buff->n);
		buff = buff->next;
		printf("\n");
	}
}
