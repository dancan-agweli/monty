#include "monty.h"
/**
 * ddprocess - function to stack
 * @bf: pointer to address
 * @line: ...
 * @lnn: ...
 * description: ...
 * return: answer
 */
void ddprocess(stack_t **bf, char *line, unsigned int lnn)
{
	char *tokens[2];
	void (*mann_func)(stack_t **, unsigned int);

	tokens[0] = strtok(line, "\n ");
	if (tokens[0] == NULL)
	{
		ddnop(bf, lnn);
	}
	else if (strcmp("push", tokens[0]) == 0)
	{
		tokens[1] = strtok(NULL, "\n ");
		ddpush(bf, lnn, tokens[1]);
	}
	else if (tokens[0][0] != '#')
	{
		mann_func = exec(tokens[0], lnn, bf);

		if (!mann_func && lnn == 0)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", lnn, tokens[0]);
			exit(EXIT_FAILURE);
		}
		mann_func(bf, lnn);
	}
}
/**
 * ddread - reads the file
 * @filename: ...
 * return: answer always
 */
void ddread(const char *filename)
{
	stack_t *bf = NULL;
	char *line = NULL;
	size_t size = 0;
	unsigned int lnn = 0;
	ssize_t read;

	FILE *dataf = fopen(filename, "r");

	if (!dataf)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &size, dataf)) != -1)
	{
		lnn++;
		ddprocess(&bf, line, lnn);
	}

	fclose(dataf);
	free(line);
	ddfree(bf);
}
/**
 * main - Entry point of program
 * @argc: ...
 * @argv: ...
 * Description: This is the main function of the Monty program. It checks
 * the command-line arguments, opens and reads the Monty file, and calls
 * the ddread function to process the file's instructions.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	/* arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	ddread(argv[1]);

	return (0);
}
