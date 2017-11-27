/*
** EPITECH PROJECT, 2017
** c code
** File description:
** my_hunter
*/

#include "../include/my.h"

int open_window()
{
	float x = 0;
	sfRenderWindow *window;
	sfVideoMode video_mode;
	sfTexture *texture;
	sfTexture *texture2;
	sfTexture *texture3;
	sfMusic *music;
	sfMusic *music2;
	sfSprite *sprite;
	sfSprite *sprite2;
	sfSprite *sprite3;
	sfEvent event;
	sfVector2f vitesse;
	sfVector2f position;
	sfVector2f mouse;
	sfVector2i mouseposition;

	position.x = 0;
	position.y = 200;
	vitesse.x = 0.5;
	video_mode.width = 1920;
	video_mode.height = 1080;
	video_mode.bitsPerPixel = 32;
	sprite = sfSprite_create();
	sprite2 = sfSprite_create();
	sprite3 = sfSprite_create();

	window = sfRenderWindow_create(video_mode, "THE STRONGEST HUNTER", sfDefaultStyle, NULL);
	//sfRenderWindow_setFramerateLimit(window, 30);
	texture = sfTexture_createFromFile("./picture/decord2.jpg", NULL);
	texture2 = sfTexture_createFromFile("./picture/sprite1.png", NULL);
	texture3 = sfTexture_createFromFile("./picture/viseur2.png", NULL);
	music = sfMusic_createFromFile("ost.wav");
	music2 = sfMusic_createFromFile("0437.ogg");
	sfMusic_play(music);
	sfMusic_setLoop(music,sfTrue);
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setTexture(sprite2, texture2, sfTrue);
	sfSprite_setTexture(sprite3, texture3, sfTrue);
	sfSprite_setPosition(sprite2, position);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_drawSprite(window, sprite, NULL);
		if (event.type == sfEvtMouseButtonPressed) {
			sfMusic_play(music2);
			sfMusic_setVolume(music, 20);
			sfMusic_setVolume(music2, 100);
		}
		sfRenderWindow_setMouseCursorVisible(window, sfFalse);
		if (event.type == sfEvtMouseButtonReleased) {
			sfMusic_setVolume(music, 50);
		}
		if (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		sfSprite_move(sprite2, vitesse);
		x++;
		if (x == 3800) {
			x = 0;
			sfSprite_setPosition(sprite2, position);
			}
		sfRenderWindow_drawSprite(window, sprite2, NULL);
		mouseposition = sfMouse_getPositionRenderWindow(window);
		mouse.y = mouseposition.y - 48;
		mouse.x = mouseposition.x - 48;
		sfSprite_setPosition(sprite3, mouse);
		sfRenderWindow_drawSprite(window, sprite3, NULL);
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
	sfMusic_destroy(music);
	sfMusic_destroy(music2);
	sfSprite_destroy(sprite);
	sfSprite_destroy(sprite2);
	sfSprite_destroy(sprite3);
	sfTexture_destroy(texture);
	sfTexture_destroy(texture2);
	sfTexture_destroy(texture3);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac > 2) {
		my_putstr("wrong argument use -h for more help\n");
		exit (0);
	}
	if (ac == 2) {
		if (my_strcmp(av[1], "-h") == 0) {
			help();
		}
	}
	else
		open_window();
	return (0);
}
