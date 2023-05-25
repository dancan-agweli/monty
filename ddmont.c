#include "monty.h"

int main(int argc, char *argv[])
{
	stack_t *bf = NULL;
	char *w = NULL, *c[2], *p;
	size_t bz = 1024, xx = 0;
	ssize_t yy;
	void (*mann_func)(stack_t **, unsigned int);

	/* arguments*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	dataf = fopen(argv[1], "r");
	if (!dataf)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (1)
	{
		yy = getline(&w, &bz, dataf);
		if (yy == -1)
			break;

		xx++;
		c[0] = strtok(w, "\n ");
		if (c[0] == NULL)
		{
			ddnop(&bf, xx);
		}
		else if (strcmp("push", c[0]) == 0)
		{
			p = strtok(NULL, "\n ");
			ddpush(&bf, xx, p);
		}
		else if (c[0] != NULL && c[0][0] != '#')
		{
			mann_func = exec(c[0], xx, &bf);

			if (!mann_func && xx == 0)
			{
				fprintf(stderr, "L%lu: unknown instruction %s\n", xx, c[0]);
				exit(EXIT_FAILURE);
			}
			mann_func(&bf, xx);
		}
	}

	fclose(dataf);
	free(w);
	ddfree(bf);
	return (0);
}

