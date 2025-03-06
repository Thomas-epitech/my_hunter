/*
** EPITECH PROJECT, 2024
** my hunter
** File description:
** print help message
*/

#include <unistd.h>
#include "myhunter.h"

void print_upper_message(void)
{
    my_putstr("⠀⠀ ⠀⠀⠀⠀⠀⢀⣠⣴⣶⣶⣶⣤⣄⠀⠀ ⠀\n");
    my_putstr("⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀\n");
    my_putstr("⢀⡀⠀⣄⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀\n");
    my_putstr("⠘⣿⡄⡿⠀⠀⣷⠀⠈⠙⢿⣿⣿⣿⡟⠋⠀⢀⡇⠀\n");
    my_putstr("⢀⣬⣿⣷⡄⠀⢹⣧⡀⠀⠀⢿⣿⡏⠀⠀⣠⣾⠃⠀\n");
    my_putstr("⠘⣿⣿⣿⠀⠀⠀⠻⣿⣷⣤⣾⣿⣧⣴⣾⣿⠋⠀⠀\n");
    my_putstr("⠀⠀⠙⢿⣆⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀\n");
    my_putstr("⠀⠀⠀⠈⣿⣦⡀⠀⠀⠀⠙⢻⣿⡟⠁⠀⠀⠀⠀⠀\n");
    my_putstr("⠀⠀⠀⠀⠈⠛⠿⢷⣶⣶⣾⣿⣿⣿⣶⣦⡄⠀⠀⠀\n");
    my_putstr("⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀\n");
}

void print_lower_message(void)
{
    my_putstr("⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀\n");
    my_putstr("       ⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀\n");
    my_putstr("⠀⠀⠀   ⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀\n");
    my_putstr("⠀  ⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀\n");
    my_putstr("       ⠀⠀⠀⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀\n");
    my_putstr("⠀     ⠀⠀⠀⠀⢿⣿⣿⣿⣿⠀⠀⠀⠀⠀\n");
    my_putstr("⠀     ⠀⠀⠀⠀⣺⣿⣿⣿⣟⠀⠀⠀⠀⠀\n");
    my_putstr("⠀ ⠀⠀⠀⣠⣴⣾⣿⣿⣿⣿⡿⣿⣿⣿⣿⣶⣦⣄\n");
    my_putstr("⠀ ⠀⠀⠀⠛⠿⠿⠟⠛⠉⠀⠀⠀⠉⠛⠿⠿⠿⠛\n");
}

void print_help_message(void)
{
    my_putstr("Space hunt\n");
    my_putstr("========================================\n");
    my_putstr("This is a simplified version of the \"duck hunt\" game\n");
    my_putstr("with a space theme\n\n");
    my_putstr("Usage:\n");
    my_putstr("make && ./myhunter: Launch the game\n");
    my_putstr("make && ./myhunter: Display this message\n\n");
    my_putstr("User command:\n");
    my_putstr("Left click: shoot\n\n\n");
    print_upper_message();
    print_lower_message();
}
