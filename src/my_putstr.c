/*
** EPITECH PROJECT, 2017
** c code
** File description:
** pool
*/

#include "../include/my.h"
#include <unistd.h>

void	my_putchar(char c)
{
	write (1, &c, 1);
}

void	my_putstr(char *c)
{
	int i = 0;
	while (c[i] != '\0') {
		my_putchar(c[i]);
		i++;
	}
}
