/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** c code
*/

#include "my.h"

int	destroy(t_music Music, t_window Window)
{
	sfMusic_destroy(Music.music);
	sfMusic_destroy(Music.music2);
	Music.music = NULL;
	Music.music2 = NULL;
	sfRenderWindow_close(Window.window);
	return (0);
}
