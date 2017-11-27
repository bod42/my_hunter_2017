/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** pool
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>

void my_putstr(char *str);
int main(int ac, char **av);
int open_window();
int my_put_nbr(int nb);
int my_strlen(char const *str);
void my_putchar(char c);
void help();
int my_strcmp(char *s1, char *s2);

#endif /*MY_H_*/
