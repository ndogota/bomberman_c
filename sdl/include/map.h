#ifndef MAP_H
#define MAP_H

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

#include <stdio.h>
#include <stdlib.h>

// processing map functions
void print_map(char** map, int height, int width);
int size_map(char *dump, int *map_height, int *map_width);

// loading map functions
char** load_map(char *file_name, int height, int width);
char** load_map_bomb(int height, int width);
void spawn_bomb(char** map_bomb_data, int position_x, int position_y);

// syntax checking functions
char** map_syntax(char *file_name);

#endif