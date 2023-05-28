#include "monty.h"


/**
 * ddeusrror - Outputs usage text.
 * Return: always answer
 */
int dderror(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 *ddmerror - utputs marloc text.
 * Return: always success.
 */
int ddmerror(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * dderror - outputwrite message of filename.
 * @file: ...
 * Return: always success
 */
int dderror(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	return (EXIT_FAILURE);
}

/**
 * ddoperror - Output the nwrite message
 * @opc: ...
 * @line_number: ...
 * Return: always success
 */
int ddoperror(char *opc, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opc);
	return (EXIT_FAILURE);
}

/**
 * ddnoerror - output thevalid message
 * @line_number: ...
 * Return: always sucess
 */
int ddnoerror(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * ddpoperr - Output the stack messages
 * @line_number: ...
 * Return: always success
 */
int ddpoperr(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * ddpinterr - Output the text
 * @line_number: ...
 * Return: always success
 */
int ddpinterr(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Output messages in data maths
 * @line_number: line of bytecodes
 * @o_pc: ...
 * Return: always success
 */
int ddstackerr(unsigned int line_number, char *o_pc)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, o_pc);
	return (EXIT_FAILURE);
}

/**
 * dddiver - Outputs the correct data
 * @line_number: ...
 * Return: always success.
 */
int dddiver(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * ddpcharerr - outputs the correct data
 * @line_number: ...
 * @txt: the error output.
 *
 * Return: (EXIT_FAILURE) always.
 */
int ddpcharerr(unsigned int line_number, char *txt)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, txt);
	return (EXIT_FAILURE);
}
