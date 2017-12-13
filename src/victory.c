/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** c code
*/

#include "my.h"

int	victory(t_music Music, t_window Window, int score)
{
	if (score >= 10) {
		my_putstr("GAME OVER \n\ncongratulation");
		my_putstr(" strongest hunter your are");
		my_putstr(" the strongest\nyour score is: ");
		my_put_nbr(score);
		my_putchar('\n');
	} else {
		my_putstr("GAME OVER \n\nyou are a looser\n");
		my_putstr("your score is: ");
		my_put_nbr(score);
		my_putchar('\n');
	}
	destroy(Music, Window);
	return (0);
}
