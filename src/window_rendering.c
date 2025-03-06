/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** render window
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include "game.h"

sfSprite *get_sprite(game_t *game, int texture_idx)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = game->rsc->textures[texture_idx];

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static void display_crosshair(sfSprite *sprite, game_t *game)
{
    sfVector2i mouse_coords =
        sfMouse_getPositionRenderWindow(game->window->render_window);
    sfVector2u window_size =
        sfRenderWindow_getSize(game->window->render_window);
    float coef_x = game->window->video_mode.width / (float)window_size.x;
    float coef_y = game->window->video_mode.height / (float)window_size.y;

    sfSprite_setOrigin(sprite, (sfVector2f){256, 256});
    sfSprite_setPosition(sprite,
        (sfVector2f){mouse_coords.x * coef_x, mouse_coords.y * coef_y});
    sfSprite_setScale(sprite, (sfVector2f){0.1, 0.1});
    sfRenderWindow_drawSprite(game->window->render_window, sprite, NULL);
}

void display_ducks(game_t *game)
{
    duck_t *current = *game->data->ducks;

    for (int i = 0; i < game->data->duck_counters->duck_nb; i++) {
        sfSprite_setTextureRect(current->sprite, current->sprite_rect);
        sfRenderWindow_drawSprite(game->window->render_window, current->sprite,
            NULL);
        current = current->next;
    }
}

void display_alien(game_t *game)
{
    alien_t *alien = game->data->alien;

    sfSprite_setTextureRect(alien->sprite, alien->sprite_rect);
    sfRenderWindow_drawSprite(game->window->render_window, alien->sprite,
        NULL);
}

void display_hearts(game_t *game)
{
    sfSprite *heart_sprite = sfSprite_create();
    sfVector2u window_size =
        sfRenderWindow_getSize(game->window->render_window);
    float sprite_width = 73;
    float coef_x = game->window->video_mode.width / (float)window_size.x;
    float coef_y = game->window->video_mode.height / (float)window_size.y;

    for (int i = 0; i < 3; i++) {
        sfSprite_setTexture(heart_sprite, game->rsc->textures[game->
            data->player->lives >= i + 1 ? 5 : 6], sfTrue);
        sfSprite_setPosition(heart_sprite, (sfVector2f){
            (((float)window_size.x / 2 - (sprite_width * 2) / coef_x) +
            i * (sprite_width * 2 / coef_x)) * coef_x,
            (window_size.y - 125 / coef_y) * coef_y});
        sfRenderWindow_drawSprite(game->window->render_window, heart_sprite,
            NULL);
    }
}

void render_window(game_t *game)
{
    sfRenderWindow_clear(game->window->render_window, sfBlack);
    sfRenderWindow_drawSprite(game->window->render_window, get_sprite(game, 0),
        NULL);
    if (game->data->game_mode == DUCKS)
        display_ducks(game);
    sfRenderWindow_drawSprite(game->window->render_window, get_sprite(game, 1),
        NULL);
    if (game->data->game_mode == ALIEN) {
        display_alien(game);
        display_hearts(game);
    }
    display_crosshair(get_sprite(game, 3), game);
}
