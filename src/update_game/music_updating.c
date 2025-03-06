/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** music updating
*/

#include "game.h"

void update_music(game_t *game)
{
    sfMusic *music;
    sfSoundStatus sound_status;

    if (game->data->game_mode == DUCKS) {
        music = game->rsc->musics[0];
        sfMusic_stop(game->data->alien->music);
        sound_status = sfMusic_getStatus(music);
        if (sound_status != sfPlaying)
            sfMusic_play(music);
    } else {
        music = game->data->alien->music;
        sfMusic_stop(game->rsc->musics[0]);
        sound_status = sfMusic_getStatus(music);
        if (sound_status != sfPlaying)
            sfMusic_play(music);
    }
}
