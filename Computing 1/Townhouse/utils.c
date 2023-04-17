/*
   utils.c 
   funções utilitárias simples e generalistas
   (não específicas ao programa em si)
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void input_flush()
{
	char c;
	c = fgetc(stdin);
	while(c != '\n') c = fgetc(stdin);
}

int get_int(int min, int max, char * prompt)
{
	int i;
	do
	{
		printf("%s", prompt);
		if(!(scanf("%d", &i)))
		{
			input_flush();
			continue;
		}
	}
	while(i < min || i > max);

    input_flush();

	return i;
}

long get_long(long min, long max, char * prompt)
{
	long i;
	do
	{
		printf("%s", prompt);
		if(!(scanf("%li", &i)))
		{
			input_flush();
			continue;
		}
	}
	while(i < min || i > max);

    input_flush();

	return i;
}

char *get_string(int length, char * prompt)
{
    int i;
    char *c;
    printf("%s", prompt);
    c = calloc(length, sizeof(char));
    fgets(c, length, stdin);

    for (i = 0; c[i] != '\0'; i++)
        if (c[i] == '\n') c[i] = '\0';

    return c;
}

char get_char(char * prompt)
{
    char c;

    do
    {
        printf("%s", prompt);
        c = fgetc(stdin);
    }
    while(c == '\n');

	input_flush();

    return c;
}
