#include "monty.h"

/**
 * ddnop - prints the operation success
 * @stack: pointer to address of stack
 * @lnn: ...
 * Return: success
 */
void ddnop(stack_t **stack, unsigned int lnn)
{
	(void)lnn;
}

/**
 * exec - Operation
 * @ppf: Char pointer
 * @y: Line of element
 * @stack: Stack
 * Return: answer
 */
void (*exec(char *ppf, unsigned int y, stack_t **stack))(stack_t**, unsigned int)
{
	int i;

	instruction_t data[] = {
		{"pall", ddpall},
		{"add", ddadd},
		{"pint", ddpint},
		{"swap", ddswap},
		{"pop", ddpop},
		{"sub", ddsub},
		{"div", dddiv},
		{"mul", ddmul},
		{"mod", ddmod},
		{"nop", ddnop},
		{"rotl", ddrots},
		{"rotr", ddrott},
		{"pchar", ddpcha},
		{"pstr", ddpstr},
		{NULL, NULL}
	};

	for (i = 0; data[i].opcode != NULL; i++)
	{
		if (strcmp(data[i].opcode, ppf) == 0)
		{
			return (data[i].f);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", y, ppf);
	exit(EXIT_FAILURE);
}

