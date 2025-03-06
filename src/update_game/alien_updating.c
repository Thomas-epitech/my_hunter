/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** alien updating functions
*/

#include "game.h"
#include "myhunter.h"
#include <stdlib.h>
#include <time.h>

static void check_alien_collisions(game_t *game)
{
    alien_t *alien = game->data->alien;
    sfVector2f sprite_coords = sfSprite_getPosition(alien->sprite);

    if (sprite_coords.x <= 0) {
        alien->direction.x *= alien->direction.x > 0 ? 1 : -1;
    }
    if (sprite_coords.x + alien->sprite_rect.width * 0.5 >=
        game->window->video_mode.width) {
        alien->direction.x *= alien->direction.x > 0 ? -1 : 1;
    }
    if (sprite_coords.y + alien->sprite_rect.height * 0.5 >=
        game->window->video_mode.height)
        alien->direction.y *= alien->direction.y > 0 ? -1 : 1;
    if (sprite_coords.y <= 0)
        alien->direction.y *= alien->direction.y > 0 ? 1 : -1;
}

static void update_alien_position(alien_t *alien, float delta_t,
    rules_t *rules)
{
    sfSprite_move(alien->sprite, (sfVector2f)
        {rules->alien_speed * alien->direction.x * delta_t,
        rules->alien_speed * alien->direction.y * delta_t});
    if (alien->lives == 0)
        sfSprite_scale(alien->sprite, (sfVector2f){0.92, 0.92});
}

static void animate_alien(alien_t *alien, float delta_t)
{
    alien->sprite_clock += delta_t;
    if (alien->sprite_clock > 0.1) {
        alien->sprite_rect.left = (alien->sprite_rect.left + 470) % 2350;
        alien->sprite_clock = 0;
    }
}

static void check_alien_dead(game_t *game)
{
    alien_t *alien = game->data->alien;

    srand(time(NULL));
    if (alien->lives == 0 && alien->state_time > 1.5) {
        sfMusic_stop(alien->music);
        alien->music = game->rsc->musics[(rand() % 3) + 1];
        alien->shot_clock = 0;
        game->data->player->lives = 3;
        initialize_alien_vectors(game);
    }
}

static void shoot_player(game_t *game)
{
    alien_t *alien = game->data->alien;

    if (alien->lives != 0) {
        alien->shot_clock += game->data->clocks->delta_t;
        if (alien->shot_clock >= game->data->rules->alien_attack_delay) {
            alien->shot_clock = 0;
            game->data->player->lives--;
            sfSound_play(game->rsc->sounds[6]->sound);
        }
    }
}

static void check_alien_shot(alien_t *alien, float delta_t)
{
    if (alien->is_damaged) {
        alien->damaged_clock += delta_t;
        if (alien->damaged_clock > 0.25) {
            sfSprite_setColor(alien->sprite, sfWhite);
            alien->is_damaged = false;
            alien->damaged_clock = 0;
        }
    }
}

void update_alien(game_t *game)
{
    alien_t *alien = game->data->alien;

    game->data->clocks->game_time += game->data->clocks->delta_t;
    alien->state_time += game->data->clocks->delta_t;
    animate_alien(alien, game->data->clocks->delta_t);
    update_alien_position(alien, game->data->clocks->delta_t,
        game->data->rules);
    if (game->data->alien->lives != 0)
        check_alien_collisions(game);
    check_alien_dead(game);
    check_alien_shot(game->data->alien, game->data->clocks->delta_t);
    shoot_player(game);
}
