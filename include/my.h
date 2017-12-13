/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** pool
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>

typedef struct s_window {
        int x_max;
        int x_min;
        sfRenderWindow *window;
        sfVideoMode video_mode;
        sfVector2f mouse;
        sfEvent event;
        sfVector2i mouseposition;
	sfClock *clock;
	sfTime time;
	float seconds;
}        t_window;

typedef struct s_sprite {
	int sprite_animated;
        sfTexture *texture;
	sfTexture *texture2;
	sfTexture *texture3;
        sfSprite *sprite;
        sfSprite *sprite2;
        sfSprite *sprite3;
        sfVector2f vitesse;
        sfVector2f position;
        sfVector2f position2;
        sfVector2f posSprite;
}       t_sprite;

typedef struct s_music {
        sfMusic *music;
        sfMusic *music2;
}       t_music;

#define background "./picture/decord2.jpg"
#define carac "./picture/sprite.png"
#define viewfinder "./picture/viseur2.png"

int	destroy(t_music Music, t_window Window);
sfSprite	*pose_sprite(t_sprite sprite1);
sfSprite	*pose_sprite2(t_sprite sprite2, sfIntRect size_sprite);
sfSprite	*pose_sprite3(t_sprite sprite3);
sfVector2f	set_pos(t_sprite sprite);
sfVector2f	set_pos2(t_sprite sprite2);
sfRenderWindow	*create_window(t_window Window);
void	my_putstr(char *str);
int	victory(t_music Music, t_window window, int score);
int	main(int ac, char **av);
int	open_window();
int	my_put_nbr(int);
int	my_put_nbr(int nb);
int	my_strlen(char const *str);
void	my_putchar(char c);
void	help();
int	my_strcmp(char *s1, char *s2);

#endif /*MY_H_*/
