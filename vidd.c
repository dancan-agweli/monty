#include "monty.h"
#include <string.h>


/**
 * ddftkn - free the extern .
 */
void ddftkn(void)
{
	size_t y = 0;

	if (tokens == NULL)
		return;

	for (y = 0; tokens[y]; y++)
		free(tokens[y]);

	free(tokens);
}

/**
 * tkr - Find the best length.
 * Return: Length
 */
unsigned int tkr(void)
{
	unsigned int lk = 0;

	while (tokens[lk])
		lk++;
	return (lk);
}

/**
 * ddemptyline - find the delimitesr
 * @l: A pointer to  line.
 
 * @delms: characters
 * Return: answer on success
 */
int ddemptyline(char *l, char *delms)
{
	int k, q;

	for (k = 0; l[k]; k++)
	{
		for (q = 0; delms[q]; q++)
		{
			if (l[k] == delms[q])
				break;
		}
		if (delms[q] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*ddgetfunc(char *opcode))(stack_t**, unsigned int)
{
	instruction_t getfunc[] = {
		{"push", ddpush},
		{"pall", ddpall},
		{"pint", ddpint},
		{"pop", ddpop},
		{"swap", ddswap},
		{"add", ddadd},
		{"nop", ddnop},
		{"sub", ddsub},
		{"div", dddiv},
		{"mul", ddmul},
		{"mod", ddmod},
		{"pchar", ddpchar},
		{"pstr", ddpstr},
		{"rotl", ddrotl},
		{"rotr", ddrotr},
		{"stack", ddstack},
		{"queue", ddq},
		{NULL, NULL}
	};
	int y;

	for (y = 0; getfunc[y].opcode; y++)
	{
		while (strcmp(opcode, getfunc[y].opcode) == 0)
			return (getfunc[y].f);
	}

	return (NULL);
}

/**
 * ddmontr - print the main function
 * @ddscript: File descriptor for an open Monty bytecodes script.
 * Return: success
 */
int ddmontr(FILE *ddscript)
{
	stack_t *stack = NULL;
	char *l = NULL;
	size_t len = 0, st = EXIT_SUCCESS;
	unsigned int line_number = 0, prl = 0;
	void (*getfunc)(stack_t**, unsigned int);

	if (ddstack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&l, &len, ddscript) != -1)
	{
		line_number++;
		tokens = strlw(char *st, char *dlm);
		if (tokens == NULL)
		{
			if (ddemptyline(l, DLM)))
				continue;
			ddfree(&stack);
			return (ddmerror());
		}
		else if (tokens[0][0] == '#')
		{
		ddfree();
			continue;
		}
		getfunc = get_op_func(tokens[0]);
		if (getfunc == NULL)
		{
			ddfree(&stack);
			st = ddnoerror(tokens[0], line_number);
			ddfree();
			break;
		}
		prl = l();
		getfunc(&stack, line_number);
		if (l() != prl)
		{
			if (tokens && tokens[prl])
				st = atoitokens[prl]);
			else
				st = EXIT_FAILURE;
			ddfree();
			break;
		}
		ddree();
	}
	ddfree(&stack);

	if (l && *l == 0)
	{
		free(l);
		return (ddmerror());
	}

	free(l);
	return (st);
}
