/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** gamedata struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include "objects.h"
#include "ressources.h"
#include "clocks.h"
#include "window.h"
#include "rules.h"
#include "duck_counters.h"
#include "state.h"
#include "player.h"

#ifndef GAMEDATA_H_
    #define GAMEDATA_H_
typedef struct {
    sfEvent event;
    duck_t **ducks;
    alien_t *alien;
    duck_counters_t *duck_counters;
    clocks_t *clocks;
    rules_t *rules;
    state_t game_state;
    gamemode_t game_mode;
    player_t *player;
} gamedata_t;

typedef struct {
    ressources_t *rsc;
    window_t *window;
    gamedata_t *data;
} game_t;
#endif
