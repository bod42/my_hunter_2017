/*
** EPITECH PROJECT, 2017
** c code
** File description:
** my_hunter
*/

#include "my.h"

sfSprite	*pose_sprite(t_sprite sprite1)
{
	sprite1.texture = sfTexture_createFromFile(background, NULL);
	sprite1.sprite = sfSprite_create();
	sfSprite_setTexture(sprite1.sprite, sprite1.texture, sfTrue);
	return (sprite1.sprite);
}

sfSprite	*pose_sprite2(t_sprite sprite2, sfIntRect size_sprite)
{
	sprite2.texture2 = sfTexture_createFromFile(carac,  NULL);
	sprite2.sprite2 = sfSprite_create();
	sfSprite_setTexture(sprite2.sprite2, sprite2.texture2, sfTrue);
	sfSprite_setTextureRect(sprite2.sprite2, size_sprite);
	sfSprite_setPosition(sprite2.sprite2, sprite2.position);
	return (sprite2.sprite2);
}

sfSprite	*pose_sprite3(t_sprite sprite3)
{
	sprite3.texture3 = sfTexture_createFromFile(viewfinder, NULL);
	sprite3.sprite3 = sfSprite_create();
	sfSprite_setTexture(sprite3.sprite3, sprite3.texture3, sfTrue);
	return (sprite3.sprite3);
}

sfVector2f	set_pos(t_sprite sprite)
{
	sprite.position.x = 0;
	sprite.position.y = 200;
	return (sprite.position);
}

sfVector2f	set_pos2(t_sprite sprite2)
{
	sprite2.position2.x = -500;
	sprite2.position2.y = 200;
	return (sprite2.position2);
}
