#include <stdlib.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// player struct
struct player {
    float x;
    float y;
    float height;
    float width;
} player;

void print_map(char** map, int height, int width);
char** load_map(char *file_name, int height, int width);
int size_map(char *dump, int *map_height, int *map_width);
int map_syntax(char *file_name);