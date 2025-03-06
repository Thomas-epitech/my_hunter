/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** destroyer
*/

#include <stdlib.h>
#include <stdio.h>
#include "game.h"

static void free_remanining_ducks(duck_t *current)
{
    duck_t *tmp;

    while (current != NULL) {
        tmp = current;
        current = current->next;
        sfSprite_destroy(tmp->sprite);
        free(tmp);
    }
}

static void free_game(game_t *game)
{
    free(game->rsc->textures);
    free(game->rsc->sounds);
    free(game->rsc->musics);
    free(game->rsc);
    free(game->window);
    free(game->data->clocks);
    free(game->data->rules);
    if (game->data->duck_counters->duck_nb)
        free_remanining_ducks(*game->data->ducks);
    free(game->data->duck_counters);
    free(game->data);
    free(game);
}

void destroyer(game_t *game)
{
    for (int i = 0; i < NB_TEXTURES; i++)
        sfTexture_destroy(game->rsc->textures[i]);
    for (int i = 0; i < NB_SOUNDS; i++) {
        sfSound_destroy(game->rsc->sounds[i]->sound);
        sfSoundBuffer_destroy(game->rsc->sounds[i]->buffer);
        free(game->rsc->sounds[i]);
    }
    for (int i = 0; i < NB_MUSICS; i++)
        sfMusic_destroy(game->rsc->musics[i]);
    sfRenderWindow_destroy(game->window->render_window);
    free_game(game);
}
