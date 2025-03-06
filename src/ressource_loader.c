/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** ressource manager
*/

#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "game.h"
#include <stdio.h>

void load_textures(ressources_t *rsc)
{
    char *sound_paths[NB_TEXTURES] = {"ressources/images/background.jpg",
        "ressources/images/surface.png", "ressources/images/duck.png",
        "ressources/images/cursor.png", "ressources/images/alien.png",
        "ressources/images/filled_heart.png",
        "ressources/images/empty_heart.png"};

    rsc->textures = malloc(sizeof(sfTexture *) * NB_TEXTURES);
    for (int i = 0; i < NB_TEXTURES; i++)
        rsc->textures[i] = sfTexture_createFromFile(sound_paths[i], NULL);
}

void load_sounds(ressources_t *rsc)
{
    char *sound_paths[NB_SOUNDS] = {"ressources/audio/gun/laser_gun_shot1.ogg",
        "ressources/audio/gun/laser_gun_shot2.ogg",
        "ressources/audio/gun/laser_gun_shot3.ogg",
        "ressources/audio/quack.ogg",
        "ressources/audio/quack2.ogg",
        "ressources/audio/empty_gun.ogg",
        "ressources/audio/gun/enemy_laser_shot.ogg"};

    rsc->sounds = malloc(sizeof(sound_t *) * NB_SOUNDS);
    for (int i = 0; i < NB_SOUNDS; i++) {
        rsc->sounds[i] = malloc(sizeof(sound_t));
        rsc->sounds[i]->buffer = sfSoundBuffer_createFromFile(sound_paths[i]);
        rsc->sounds[i]->sound = sfSound_create();
        sfSound_setBuffer(rsc->sounds[i]->sound, rsc->sounds[i]->buffer);
        sfSound_setVolume(rsc->sounds[i]->sound, i != 4 ? 100.0 : 50.0);
    }
}

void load_musics(ressources_t *rsc)
{
    char *sound_paths[NB_MUSICS] = {"ressources/musics/main_soundtrack.ogg",
        "ressources/musics/boss.ogg", "ressources/musics/boss2.ogg",
        "ressources/musics/boss4.ogg"};

    rsc->musics = malloc(sizeof(sfMusic *) * NB_MUSICS);
    for (int i = 0; i < NB_MUSICS; i++) {
        rsc->musics[i] = sfMusic_createFromFile(sound_paths[i]);
        sfMusic_setLoop(rsc->musics[i], sfTrue);
        sfMusic_setVolume(rsc->musics[i], i == 0 ? 33.33 : 75.0);
    }
}

void load_ressources(ressources_t *rsc)
{
    load_textures(rsc);
    load_sounds(rsc);
    load_musics(rsc);
}
