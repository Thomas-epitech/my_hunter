/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** objects structs
*/


#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#ifndef OBJECTS_H_
    #define OBJECTS_H_
typedef struct duck {
    sfSprite *sprite;
    float sprite_clock;
    float state_time;
    sfIntRect sprite_rect;
    sfVector2f position;
    sfVector2f direction;
    struct duck *next;
    bool is_alive;
} duck_t;

typedef struct {
    sfSprite *sprite;
    float sprite_clock;
    float shot_clock;
    float state_time;
    sfIntRect sprite_rect;
    sfVector2f position;
    sfVector2f direction;
    int lives;
    sfMusic *music;
    bool is_damaged;
    float damaged_clock;
} alien_t;
#endif
