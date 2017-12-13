/*
** EPITECH PROJECT, 2017
** c code
** File description:
** my_hunter
*/

#include "my.h"

sfRenderWindow		*create_window(t_window Window)
 {
	 Window.video_mode.width = 1920;
	 Window.video_mode.height = 1080;
	 Window.video_mode.bitsPerPixel = 32;
	 Window.window = sfRenderWindow_create(Window.video_mode, "THE STRONGEST HUNTER", sfDefaultStyle, NULL);
	 return (Window.window);
 }
