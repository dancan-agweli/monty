#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define DAN 1
/* Defines the delimiters*/
#define DLM " \n\t\a\b"

extern char **tokens;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* intepreter */
void ddfree(stack_t **stack);
int ddstack(stack_t **stack);
int ddchk(stack_t *stack);
void ddftkn(void);
unsigned int tkr(void);
int ddmontr(FILE *ddscript);
void ddsterr(int dderror);
int ddemptyline(char *l, char *delms);
void (*ddgetfunc(char *opcode))(stack_t**, unsigned int);
/*  FUNCTIONS */
void ddpush(stack_t **stack, unsigned int line_number);
void ddpall(stack_t **stack, unsigned int line_number);
void ddpint(stack_t **stack, unsigned int line_number);
void ddpop(stack_t **stack, unsigned int line_number);
void ddswap(stack_t **stack, unsigned int line_number);
void ddadd(stack_t **stack, unsigned int line_number);
void ddnop(stack_t **stack, unsigned int line_number);
void ddsub(stack_t **stack, unsigned int line_number);
void dddiv(stack_t **stack, unsigned int line_number);
void ddmul(stack_t **stack, unsigned int line_number);
void ddmod(stack_t **stack, unsigned int line_number);
void ddpchar(stack_t **stack, unsigned int line_number);
void ddpstr(stack_t **stack, unsigned int line_number);
void ddrotl(stack_t **stack, unsigned int line_number);
void ddrotr(stack_t **stack, unsigned int line_number);
void ddstacki(stack_t **stack, unsigned int line_number);
void ddq(stack_t **stack, unsigned int line_number);

/* LIBRARY FUNCTIONS */
char **strlw(char *st, char *dlm);
char *ddget(int x);

int ddeurror(void);
int ddmerror(void);
int dderror(char *file); /* filename*/
int ddoperror(char *opc, unsigned int line_number);
int ddnoerror(unsigned int line_number);
int ddpoperr(unsigned int line_number);
int ddpinterr(unsigned int line_number);
int ddstackerr(unsigned int line_number, char *o_pc);
int dddiver(unsigned int line_number);
int ddpcharerr(unsigned int line_number, char *txt); /* messages*/

#endif /* MONTY_H */
