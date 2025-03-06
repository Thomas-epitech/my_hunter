/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 ^ *s2)
            return *s1 ? 1 : -1;
        if (*s1 != *s2)
            return *s1 > *s2 ? 1 : -1;
        s1++;
        s2++;
    }
    return 0;
}
