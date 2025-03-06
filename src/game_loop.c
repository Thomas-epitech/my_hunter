/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** game loop
*/

#include "duck_counters.h"
#include "myhunter.h"
#include "player.h"
#include <SFML/Audio/Music.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Window.h>
#include <stdlib.h>
#include <time.h>

static void initialize_clocks(gamedata_t *game_data)
{
    game_data->clocks = malloc(sizeof(clocks_t) * 3);
    game_data->clocks->delta_t = 0;
    game_data->clocks->game_time = 0;
    game_data->clocks->spawn_time = 0;
    game_data->clocks->gun_cooldown = 1;
}

static void initialize_window(game_t *game)
{
    game->window = malloc(sizeof(window_t));
    game->window->video_mode.width = 1536;
    game->window->video_mode.height = 864;
    game->window->video_mode.bitsPerPixel = 32;
    game->window->render_window =
        sfRenderWindow_create(game->window->video_mode, "Duck Blaster",
        sfDefaultStyle, NULL);
    sfRenderWindow_setMouseCursorVisible(game->window->render_window, sfFalse);
    sfRenderWindow_setFramerateLimit(game->window->render_window, 144);
}

static void initialize_data(game_t *game)
{
    game->data = malloc(sizeof(gamedata_t));
    game->data->ducks = malloc(sizeof(duck_t *));
    game->data->game_mode = DUCKS;
    game->data->game_state = IN_GAME;
}

static void initialize_counters(game_t *game)
{
    game->data->duck_counters = malloc(sizeof(duck_counters_t));
    game->data->duck_counters->duck_nb = 0;
    game->data->duck_counters->spawned_duck_nb = 0;
}

static void initialize_rules(game_t *game)
{
    game->data->rules = malloc(sizeof(rules_t));
    game->data->rules->level = 1;
    game->data->rules->nb_ducks = 10;
    game->data->rules->duck_speed = 2.5;
    game->data->rules->alien_speed = 6;
    game->data->rules->alien_lives = 5;
    game->data->rules->alien_attack_delay = 3;
}

void initialize_alien_vectors(game_t *game)
{
    bool spawn_right = get_random_float(0, 1) > 0.5;

    sfSprite_setPosition(game->data->alien->sprite,
        (sfVector2f){spawn_right ? (int)game->window->video_mode.width :
        -470, 540});
    game->data->alien->direction.x = spawn_right ? -300 : 300;
    game->data->alien->direction.y = get_random_float(0, 1) > 0.5 ?
        get_random_float(-200, -100) : get_random_float(100, 200);
    sfSprite_setScale(game->data->alien->sprite, (sfVector2f){0.5, 0.5});
}

static void initialize_alien(game_t *game)
{
    alien_t *alien = game->data->alien;

    srand(time(NULL));
    alien->sprite = sfSprite_create();
    sfSprite_setTexture(game->data->alien->sprite,
        game->rsc->textures[4], sfFalse);
    alien->sprite_clock = 0;
    alien->state_time = 0;
    alien->sprite_rect.left = 0;
    alien->sprite_rect.top = 0;
    alien->sprite_rect.width = 470;
    alien->sprite_rect.height = 272;
    alien->lives = game->data->rules->alien_lives;
    alien->music = game->rsc->musics[(rand() % 3) + 1];
    alien->lives = game->data->rules->alien_lives;
    alien->shot_clock = 0;
    alien->is_damaged = false;
    alien->damaged_clock = 0;
    initialize_alien_vectors(game);
}

static void initialize_game(game_t *game)
{
    game->rsc = malloc(sizeof(ressources_t));
    load_ressources(game->rsc);
    initialize_data(game);
    initialize_rules(game);
    initialize_counters(game);
    initialize_window(game);
    initialize_clocks(game->data);
    game->data->alien = malloc(sizeof(alien_t));
    initialize_alien(game);
    game->data->player = malloc(sizeof(player_t));
    game->data->player->lives = 3;
}

void game_loop(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfClock *clock = sfClock_create();
    sfTime time_elapsed;

    initialize_game(game);
    while (sfRenderWindow_isOpen(game->window->render_window)) {
        time_elapsed = sfClock_restart(clock);
        game->data->clocks->delta_t = time_elapsed.microseconds / 1000000.0;
        handle_event(game);
        update_game(game);
        render_window(game);
        sfRenderWindow_display(game->window->render_window);
    }
    destroyer(game);
}
