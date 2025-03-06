/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** get random float
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

float get_random_float(float min, float max)
{
    srand(time(NULL));
    return (min + (float)rand() / ((float)RAND_MAX / (max - min)));
}
