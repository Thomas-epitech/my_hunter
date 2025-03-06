# My Hunter

A Duck Hunt inspired game developed in C using the CSFML library.

## Overview

My Hunter is a shooting game based on the classic Duck Hunt. The player takes on the role of a hunter who must shoot ducks (or other animated sprites) as they fly across the screen. The game features animated sprites, user interaction through mouse clicks, and various game mechanics to create an engaging experience.

## Features

- **Animated Sprites**: Moving characters rendered using sprite sheets
- **User Interaction**: Mouse click detection for shooting
- **Dynamic Movement**: Sprites that translate across the screen with smooth animation
- **Help Option**: Integrated help menu with `-h` flag
- **Frame Rate Control**: Consistent game speed regardless of hardware
- **Window Management**: Event-based window handling

## Technical Details

- **Language**: C
- **Graphics Library**: CSFML
- **Compilation**: Via Makefile, including re, clean, and fclean rules
- **Window Size**: Between 800x600 and 1920x1080 pixels
- **Error Handling**: Error messages written to the error output, with exit code 84 for errors

## Controls

- **Left Mouse Button**: Shoot at targets
- **ESC Key**: Close the game

## Installation

### Prerequisites

- CSFML library
- GCC compiler
- Make

### Compilation

```bash
make
```

This will generate the executable `my_hunter`.

## Usage

```bash
./my_hunter
```

### Command Line Options

```bash
./my_hunter -h
```

Displays a help message showing program description and available user inputs.

## Game Mechanics

- Animated characters appear on screen and move from one side to another
- Player must click on them to score points
- Different levels with increasing difficulty
- Score tracking system

## Additional Features

- Score display on screen
- High score tracking between game sessions
- Visual target cursor that follows the mouse
- Multiple game levels with different challenges
- Sound effects for shooting and hit/miss feedback

## Implementation Details

The game uses CSFML's timing functions to ensure consistent animation speed regardless of the computer's performance. All movements and animations are synchronized using sfClock elements.

The architecture is modular to allow for easy expansion of game features and reusability for future projects.
## Development

For developers who want to contribute or modify the game:

- The main game loop is separated from the rendering and input handling
- Sprite animations are handled through dedicated functions
- Entity management follows object-oriented principles (as much as possible in C)
- Physics and collision detection are abstracted into separate components

## Acknowledgments

- Inspired by the classic Nintendo game Duck Hunt
- CSFML library and its documentation
