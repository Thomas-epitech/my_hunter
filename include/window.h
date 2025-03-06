/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** window header
*/

#include <SFML/Graphics.h>

#ifndef WINDOW_H
    #define WINDOW_H
typedef struct {
    sfRenderWindow *render_window;
    sfVideoMode video_mode;
} window_t;
#endif
