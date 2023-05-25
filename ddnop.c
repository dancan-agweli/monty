#include "monty.h"


/**
 *  ddnop - prints the operation sucess
 *  @stack: pointer to address of stcak
 *  @lnn: ...
 *  Return: succes
 */


void ddnop(stack_t **stack, unsigned int lnn)
{

	(void) stack;
	(void) lnn;
}
#include "monty.h"

/**
 * exec - Opeartion
 *
 * @ppf: Char pointer
 * @y: lineof elemnt
 * @stack: stack
 * Return: answer
 */


void (*exec(char *ppf, unsigned int y, stack_t **x))(stack_t**, unsigned int)
{
	int x;

	instruction_t data[] = {
		{"pall", ddpall},
		{"add", ddadd},
		{"pint", ddpint},
		{"swap", ddswap},
		{"pop", get_pop},
		{"sub", ddsub},
		{"div", dddiv},
		{"mul", ddmul},
		{"mod", ddmod},
		{"nop", ddnop},
		{"rotl", ddrott},
		{"rotr", ddrotr},
		{"pchar", ddpchar},
		{"pstr", ddpstr},
		{NULL, NULL}
	};

	for (x = 0; data[x].opcode != NULL; x++)
	{
		if (strcmp(data[x].opcode, ppf) == 0)
		{
			return (data[x].f);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", y, ppf);
	fclose(dataf);
	ddfree(*stack);
	exit(EXIT_FAILURE);
}
