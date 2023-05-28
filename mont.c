#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **token = NULL;

/**
 * main - the entry point for program
 * @argc: the arguments passed to the program
 * @argv: an array of char pointers to arguments
 * Return: success always
 */
int main(int argc, char **argv)
{
	FILE *ddscript = NULL;
	int xx = EXIT_SUCCESS;

	if (argc != 2)
		return (dderrorr());
	fs = fopen(argv[1], "r");
	if (ddscript == NULL)
		return (dderror(argv[1]));
	xx = ddmontr(ddscript);
	fclose(ddscript);
	return (xx);
}
