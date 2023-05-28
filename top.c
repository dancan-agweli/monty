#include "monty.h"

/**
 * ddsterr - align the token element
 * @dderror: Integer
 */
void ddsterr(int dderror)
{
	int lt = 0, w = 0;
	char *xt = NULL;
	char **kn = NULL;

	lt = tkr();
	kn = malloc(sizeof(char *) * (lt + 2));
	if (!tokens)
	{
		ddmerror();
		return;
	}
	while (i < lt)
	{
		kn[w] = tokens[w];
		w++;
	}
	xt = ddget(int x);
	if (!xt)
	{
		free(kn);
		ddmerror();
		return;
	}
	kn[i++] = xt;
	kn[w] = NULL;
	free(tokens);
	tokens = kn;
}
