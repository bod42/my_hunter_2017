/*
** EPITECH PROJECT, 2017
** c code
** File description:
** my_hunter
*/

#include "my.h"

sfMusic		*create_music(t_music Music)
{
	Music.music = sfMusic_createFromFile("./ost/ost.wav");
	sfMusic_play(Music.music);
	sfMusic_setLoop(Music.music, sfTrue);
	return (Music.music);
}

void	launch_if(t_sprite Sprite, t_music Music)
{
	sfMusic_play(Music.music2);
	sfMusic_setVolume(Music.music, 20);
	sfMusic_setVolume(Music.music2, 100);
	Sprite.position2.y = (rand() % 800);
	sfSprite_setPosition(Sprite.sprite2, Sprite.position2);
}

void	draw_sprite(t_window Window, t_sprite Sprite)
{
	sfRenderWindow_drawSprite(Window.window, Sprite.sprite, NULL);
	sfRenderWindow_drawSprite(Window.window, Sprite.sprite3, NULL);
	sfRenderWindow_drawSprite(Window.window, Sprite.sprite2, NULL);
}

int	open_window()
{
	t_window Window;
	t_sprite Sprite;
	t_music Music;
	int sprite_animated = 0;
	sfIntRect size_sprite = {sprite_animated,0,70,96};
	int score = 0;

	Window.clock = sfClock_create();
	Sprite.sprite_animated = 0;
	Sprite.position = set_pos(Sprite);
	Sprite.position2 = set_pos2(Sprite);
	Sprite.vitesse.x = 0.5;
	Window.window = create_window(Window);
	Sprite.sprite = pose_sprite(Sprite);
	Sprite.sprite2 = pose_sprite2(Sprite, size_sprite);
	Sprite.sprite3 = pose_sprite3(Sprite);
	Music.music = create_music(Music);
	Music.music2 = sfMusic_createFromFile("./ost/0437.ogg");
	while (sfRenderWindow_isOpen(Window.window)) {
		Window.x_min = Sprite.posSprite.x + 5;
		Window.x_max = Sprite.posSprite.x + 60;
		Window.time = sfClock_getElapsedTime(Window.clock);
		Window.seconds = Window.time.microseconds / 1000000.0;
		if ((Window.mouse.x > Window.x_min && Window.mouse.x < Window.x_max)) {
			if (Window.event.type == sfEvtMouseButtonPressed) {
				launch_if(Sprite, Music);
				score++;
				Sprite.vitesse.x +=0.1;
			}
		}
		 sfRenderWindow_setMouseCursorVisible(Window.window, sfFalse);
		 if (Window.event.type == sfEvtMouseButtonReleased) {
			 sfMusic_setVolume(Music.music, 50);
		 }
		 if (sfRenderWindow_pollEvent(Window.window, &Window.event)) {
			 if (Window.event.type == sfEvtClosed)
				 sfRenderWindow_close(Window.window);
		 }
		 Sprite.posSprite = sfSprite_getPosition(Sprite.sprite2);
		 sfSprite_move(Sprite.sprite2, Sprite.vitesse);
		 if (Sprite.posSprite.x >= 1920)
			 victory(Music, Window, score);
		 Window.mouseposition = sfMouse_getPositionRenderWindow(Window.window);
		 Window.mouse.y = Window.mouseposition.y - 25;
		 Window.mouse.x = Window.mouseposition.x - 30;
		 if (Window.seconds > 0.1) {
			 size_sprite.left += 72;
			 sfSprite_setTextureRect(Sprite.sprite2, size_sprite);
			 sfClock_restart(Window.clock);
		 }
		 if (size_sprite.left == 792)
			 size_sprite.left = 0;
		 sfSprite_setPosition(Sprite.sprite3, Window.mouse);
		 draw_sprite(Window, Sprite);
		 sfRenderWindow_display(Window.window);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac > 2) {
		my_putstr("wrong argument use -h for more help\n");
		return (0);
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
