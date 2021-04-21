#include <stdlib.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

void print_map(char** map, int height, int width);
char** load_map(char *file_name, int height, int width);
int size_map(char *dump, int *map_height, int *map_width);
char** map_syntax(char *file_name);