/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** toggle game name
*/

#include "game.h"

void toggle_game_mode(game_t *game)
{
    game->data->game_mode = game->data->game_mode == DUCKS ? ALIEN : DUCKS;
}
