#include <stdio.h>

#include "../include/map.h"

int size_map(char *file_name, int *map_width, int *map_height)
{
    int max_width, width, height = 0;

    FILE *F;

    F = fopen(file_name, "r");

    if(!F) {
        printf("The map file : %s doesnt exist.\n", file_name);
        return -1;
    }

    for(char c = fgetc(F); c != EOF; c = fgetc(F), height++) {
        for(; c != EOF && c != '\n'; c = fgetc(F), width++);
        if (width >= max_width) {
            max_width = width;
        }
        width = 0;
    }

    *map_width = max_width;
    *map_height = height;

    return 0;
}

int map_syntax(char *file_name)
{
    FILE *F;
    int map_width, map_height;

    F = fopen(file_name, "r");

    if(!F) {
        printf("The map file : %s doesnt exist.\n", file_name);
        return -1;
    }

    for(char c = fgetc(F); c != EOF; c = fgetc(F)) {
        if(c != '#' && c != ' ' && c != '\n') {
            printf("The map file have an invalid syntax : %s\n", file_name);
            return -1;
        }
    }

    size_map(file_name, &map_width, &map_height);

    if(map_width != MAP_WIDTH && map_height != MAP_HEIGHT) {
        printf("The map file doesnt correspond with the correct size : %s\n", file_name);
        return -1;
    }



    return 0;
}