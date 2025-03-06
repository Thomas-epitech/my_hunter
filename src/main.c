/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "myhunter.h"
#include "game.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        game_loop();
    else if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        print_help_message();
    else
        return 84;
    return 0;
}
