/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** event handling
*/

#include "game.h"
#include "myhunter.h"
#include <SFML/Graphics/Rect.h>

static void check_close_evt(game_t *game)
{
    if (game->data->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window->render_window);
}

static void check_if_duck_shot(game_t *game)
{
    sfFloatRect sprite_rect;
    duck_t *current = *game->data->ducks;
    int x = game->data->event.mouseButton.x;
    int y = game->data->event.mouseButton.y;
    sfVector2u wdw_size = sfRenderWindow_getSize(game->window->render_window);
    float coef_x = game->window->video_mode.width / (float)wdw_size.x;
    float coef_y = game->window->video_mode.height / (float)wdw_size.y;

    for (int i = 0; i < game->data->duck_counters->duck_nb; i++) {
        sprite_rect = sfSprite_getGlobalBounds(current->sprite);
        if (sfFloatRect_contains(&sprite_rect, x * coef_x, y * coef_y) &&
            current->is_alive) {
            current->is_alive = false;
            current->state_time = 0;
            sfSound_play(game->rsc->sounds[3]->sound);
        }
        current = current->next;
    }
}

static void check_if_alien_shot(game_t *game)
{
    alien_t *alien = game->data->alien;
    sfFloatRect sprite_rect =
        sfSprite_getGlobalBounds(alien->sprite);
    int x = game->data->event.mouseButton.x;
    int y = game->data->event.mouseButton.y;
    sfVector2u wdw_size = sfRenderWindow_getSize(game->window->render_window);
    float coef_x = game->window->video_mode.width / (float)wdw_size.x;
    float coef_y = game->window->video_mode.height / (float)wdw_size.y;

    if (sfFloatRect_contains(&sprite_rect, x * coef_x, y * coef_y) &&
        alien->lives != 0) {
        alien->lives--;
        alien->is_damaged = true;
        sfSprite_setColor(alien->sprite, sfRed);
        if (alien->lives == 0)
            alien->state_time = 0;
    }
}

static void check_click_evt(game_t *game)
{
    if (game->data->event.type == sfEvtMouseButtonPressed &&
        game->data->event.mouseButton.button == sfMouseLeft &&
        game->data->clocks->gun_cooldown <= 0.5)
        sfSound_play(game->rsc->sounds[5]->sound);
    if (game->data->event.type == sfEvtMouseButtonPressed &&
        game->data->event.mouseButton.button == sfMouseLeft &&
        game->data->clocks->gun_cooldown > 0.5) {
        if (game->data->game_mode == DUCKS)
            check_if_duck_shot(game);
        else
            check_if_alien_shot(game);
        sfSound_play(game->rsc->sounds[(int)get_random_float(0, 2.99)]->sound);
        game->data->clocks->gun_cooldown = 0;
    }
}

static void check_kb_evt(game_t *game)
{
    if (game->data->event.type == sfEvtKeyPressed &&
        game->data->event.key.code == sfKeyM)
        toggle_game_mode(game);
}

void handle_event(game_t *game)
{
    game->data->clocks->gun_cooldown += game->data->clocks->delta_t;
    if (sfRenderWindow_pollEvent(game->window->render_window,
        &game->data->event)) {
        check_close_evt(game);
        check_click_evt(game);
        check_kb_evt(game);
    }
}
