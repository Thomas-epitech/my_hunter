/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** game updating
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "myhunter.h"
#include "game.h"

static duck_t *get_last_duck(duck_t *duck)
{
    if (duck->next == NULL) {
        return duck;
    }
    return get_last_duck(duck->next);
}

static void initialize_duck_vectors(game_t *game, duck_t *duck)
{
    sfSprite_setPosition(duck->sprite, (sfVector2f){
        get_random_float(game->window->video_mode.width * 0.25,
        game->window->video_mode.width * 0.75),
        game->window->video_mode.height - 220});
    duck->direction.x = get_random_float(0, 1) > 0.5 ?
        get_random_float(100, 400) : get_random_float(-400, -100);
    duck->direction.y = duck->direction.x > 0 ?
        (500 - duck->direction.x) * -1 : (500 + duck->direction.x) * -1;
    sfSprite_setScale(duck->sprite,
        (sfVector2f){duck->direction.x > 0 ? 1 : -1, 1});
}

static duck_t *initialize_duck(game_t *game, duck_t *duck)
{
    duck->sprite = sfSprite_create();
    sfSprite_setTexture(duck->sprite, game->rsc->textures[2], sfFalse);
    duck->sprite_clock = 0;
    duck->state_time = 0;
    duck->sprite_rect.left = 0;
    duck->sprite_rect.top = 0;
    duck->sprite_rect.width = 88;
    duck->sprite_rect.height = 88;
    duck->next = NULL;
    duck->is_alive = true;
    initialize_duck_vectors(game, duck);
    return duck;
}

static void spawn_ducks(game_t *game)
{
    duck_t *last_duck;

    game->data->clocks->spawn_time += game->data->clocks->delta_t;
    if (game->data->clocks->spawn_time > 1 &&
        game->data->rules->nb_ducks >
        game->data->duck_counters->spawned_duck_nb) {
        if (game->data->duck_counters->duck_nb == 0) {
            *(game->data->ducks) = malloc(sizeof(duck_t));
            *(game->data->ducks) = initialize_duck(game, *game->data->ducks);
        } else {
            last_duck = get_last_duck(*game->data->ducks);
            last_duck->next = malloc(sizeof(duck_t));
            last_duck = initialize_duck(game, last_duck->next);
        }
        game->data->duck_counters->duck_nb++;
        game->data->duck_counters->spawned_duck_nb++;
        game->data->clocks->spawn_time = 0;
        sfSound_play(game->rsc->sounds[4]->sound);
    }
}

static void update_duck_position(duck_t *current, float delta_t,
    float duck_speed)
{
    sfSprite_move(current->sprite, (sfVector2f){
        current->direction.x * duck_speed * delta_t,
        current->direction.y * duck_speed * delta_t});
    if (!current->is_alive)
        sfSprite_scale(current->sprite, (sfVector2f){0.92, 0.92});
}

static void animate_duck(duck_t *current, float delta_t)
{
    current->sprite_clock += delta_t;
    if (current->sprite_clock > get_random_float(0.15, 0.20)) {
        current->sprite_rect.left = (current->sprite_rect.left +
        current->sprite_rect.width) % 264;
        current->sprite_clock = 0;
    }
    current = current->next;
}

static void check_for_collision(duck_t *current, window_t *window)
{
    sfVector2f sprite_coords = sfSprite_getPosition(current->sprite);

    if (sprite_coords.x <= current->sprite_rect.width) {
        sfSprite_setScale(current->sprite, (sfVector2f){1, 1});
        current->direction.x *= current->direction.x > 0 ? 1 : -1;
    }
    if (sprite_coords.x + current->sprite_rect.width >=
        window->video_mode.width) {
        sfSprite_setScale(current->sprite, (sfVector2f){-1, 1});
        current->direction.x *= current->direction.x > 0 ? -1 : 1;
    }
    if (sprite_coords.y <= 0)
        current->direction.y *= current->direction.y > 0 ? 1 : -1;
    if (current->state_time > 1 && sprite_coords.y +
        current->sprite_rect.height >= window->video_mode.height - 125)
        current->direction.y *= current->direction.y > 0 ? -1 : 1;
}

static void remove_dead_duck(duck_t *current, duck_t *previous, game_t *game)
{
    if (!current->is_alive && current->state_time > 1.5) {
        if (previous)
            previous->next = current->next;
        else
            *game->data->ducks = current->next;
        game->data->duck_counters->duck_nb--;
        sfSprite_destroy(current->sprite);
        free(current);
    }
}

void update_ducks(game_t *game)
{
    duck_t *current;
    duck_t *previous = NULL;

    game->data->clocks->game_time += game->data->clocks->delta_t;
    spawn_ducks(game);
    current = *game->data->ducks;
    for (int i = 0; i < game->data->duck_counters->duck_nb; i++) {
        current->state_time += game->data->clocks->delta_t;
        update_duck_position(current, game->data->clocks->delta_t,
            game->data->rules->duck_speed);
        animate_duck(current, game->data->clocks->delta_t);
        remove_dead_duck(current, previous, game);
        if (current->is_alive)
            check_for_collision(current, game->window);
        previous = current;
        current = current->next;
    }
}
