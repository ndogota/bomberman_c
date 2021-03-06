#include "../include/map.h"

void print_map(char** map, int height, int width)
{
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width + 1; j++) {
            printf("%c", map[i][j]);
        }
    }
}

int size_map(char *file_name, int *map_height, int *map_width)
{
    int max_width, width, height = 0;

    FILE *F;

    F = fopen(file_name, "r");

    if(!F)
        return -1;

    for(char c = fgetc(F); c != EOF; c = fgetc(F), height++) {
        for(; c != EOF && c != '\n'; c = fgetc(F), width++);
        if (width >= max_width) {
            max_width = width;
        }
        width = 0;
    }

    *map_height = height;
    *map_width = max_width;

    return 0;
}

char** load_map(char *file_name, int height, int width)
{
    FILE *F;
    int w = 0;

    F = fopen(file_name, "r");

    if(!F)
        return NULL;

    char **map_data = malloc(height * sizeof(char *));

    char c = fgetc(F);

    for(int h = 0; c != EOF && h < height; c = fgetc(F), h++) {
        map_data[h] = malloc((width + 1) * sizeof(char));

        for(w = 0; c != '\n' && w < width; c = fgetc(F), w++) {
            map_data[h][w] = c;
        }

        map_data[h][w] = '\n';
    }

    return map_data;
}

char** load_map_bomb(int height, int width)
{
    char **map_bomb_data = malloc(height * sizeof(char *));

    for (int h = 0; h < height; h++) {
        map_bomb_data[h] = malloc(width * sizeof(char));
    }

    return map_bomb_data;
}


void spawn_bomb(char** map_bomb_data, int position_x, int position_y) {
    map_bomb_data[position_x][position_y] = 'X';
}

char** map_syntax(char *file_name)
{
    FILE *F;
    int map_height, map_width;

    F = fopen(file_name, "r");

    if(!F) {
        printf("The map file : %s doesnt exist.\n", file_name);
        return NULL;
    }

    for(char c = fgetc(F); c != EOF; c = fgetc(F)) {
        if(c != '#' && c != ' ' && c != '\n') {
            printf("The map file have an invalid syntax : %s\n", file_name);
            return NULL;
        }
    }

    size_map(file_name, &map_height, &map_width);

    if(map_height != MAP_HEIGHT && map_width != MAP_WIDTH) {
        printf("The map file have an invalid syntax : %s\n", file_name);
        return NULL;
    }

    char **map_data = load_map(file_name, map_height, map_width);

    return map_data;
}