/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** game updating
*/

#include "game.h"
#include "myhunter.h"
#include <stdio.h>
#include <stdlib.h>

void update_game(game_t *game)
{
    if (game->data->game_mode == DUCKS)
        update_ducks(game);
    else
        update_alien(game);
    update_music(game);
    update_level(game);
}
