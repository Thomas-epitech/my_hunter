/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** ressources struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef RESSOURCE_H_
    #define RESSOURCE_H_
    #define NB_TEXTURES 7
    #define NB_SOUNDS 7
    #define NB_MUSICS 4
typedef struct {
    sfSoundBuffer *buffer;
    sfSound *sound;
} sound_t;

typedef struct {
    sfTexture **textures;
    sound_t **sounds;
    sfMusic **musics;
} ressources_t;
#endif
