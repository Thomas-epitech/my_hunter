/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** level updating
*/

#include "game.h"
#include "myhunter.h"

void update_level(game_t *game)
{
    gamedata_t *data = game->data;

    if (data->rules->nb_ducks <= data->duck_counters->spawned_duck_nb -
        data->duck_counters->duck_nb)
        data->game_mode = ALIEN;
    if (data->alien->lives == 0 && data->alien->state_time > 1.6) {
        data->rules->duck_speed += 0.50;
        data->duck_counters->spawned_duck_nb = 0;
        data->rules->alien_lives += data->rules->alien_lives < 10 ? 1 : 0;
        data->alien->lives = data->rules->alien_lives;
        data->rules->alien_speed += data->rules->alien_speed < 8 ? 1 : 0;
        data->rules->alien_attack_delay -=
            data->rules->alien_attack_delay > 1.5 ? 0.15 : 0;
        data->game_mode = DUCKS;
    }
}
