/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** my hunter functions
*/

#include "game.h"

#ifndef MY_HUNTER_H
    #define MY_HUNTER_H
void load_ressources(ressources_t *);
void game_loop(void);
void render_window(game_t *);
void update_game(game_t *);
void update_ducks(game_t *);
void update_alien(game_t *);
void handle_event(game_t *);
void update_music(game_t *);
void update_level(game_t *);
void toggle_game_mode(game_t *);
float get_random_float(float, float);
void print_help_message(void);
int my_putstr(char *);
void destroyer(game_t *);
void initialize_alien_vectors(game_t *);
#endif
