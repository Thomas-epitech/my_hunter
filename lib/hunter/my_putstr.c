/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** task02
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    while (*str != '\0') {
        write(1, str, 1);
        str++;
    }
    return 0;
}
