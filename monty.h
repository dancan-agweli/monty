#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


extern FILE *dataf;
FILE *dataf;
void ddfree(stack_t *s);
int dd_digit(char *w);
/* operator functional*/
void (*mann_func)(stack_t **, unsigned int);
void (*exec(char *ppf, unsigned int y, stack_t **x))(stack_t**, unsigned int);
/* lifo s prototypes*/
void ddpush(stack_t **stack, unsigned int lnn, char *chan);
/* line_number has been used in accordance to the struc*/
void ddpall(stack_t **stack, unsigned int lnn);
void ddpint(stack_t **stack, unsigned int lnn);
void ddpop(stack_t **stack, unsigned int lnn);
void ddswap(stack_t **stack, unsigned int lnn);
void ddadd(stack_t **stack, unsigned int lnn);
void ddnop(stack_t **stack, unsigned int lnn);
void ddsub(stack_t **stack, unsigned int lnn);
void dddiv(stack_t **stack, unsigned int lnn);
void ddmul(stack_t **stack, unsigned int lnn);
void ddmod(stack_t **stack, unsigned int lnn);
void ddrott(stack_t **stack, unsigned int lnn);
void ddpcha(stack_t **stack, unsigned int lnn);
void ddrots(stack_t **stack, unsigned int lnn);
void ddpstr(stack_t **stack, unsigned int lnn);
void ddprocess(stack_t **bf, char *line, unsigned int lnn);
void ddread(const char *filename);
int main(int argc, char *argv[]);

#endif /* MONTY_H */
