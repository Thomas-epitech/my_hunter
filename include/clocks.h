/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** clocks struct
*/

#ifndef CLOCKS_H_
    #define CLOCKS_H_
typedef struct {
    float delta_t;
    float game_time;
    float spawn_time;
    float gun_cooldown;
} clocks_t;
#endif
