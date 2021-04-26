#ifndef MAIN_H
#define MAIN_H

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

#define TILE_HEIGHT 64
#define TILE_WIDTH 64

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "map.h"

enum tile_type {
    wall_type = '#',
    ground_type = ' ',
    bomb_type = 'X',
};

// player struct
struct player {
    char* player_name;
    float x;
    float y;
    float width;
    float height;

    SDL_Texture *sprite;
} player;

typedef struct bomb {
    char* owner_name;
    int x;
    int y;
    int bomb_state;
} bomb;

typedef struct map {
    int tile_height, tile_width;
    int map_height, map_width;

    char **data;
} map;

struct map_bomb {
    int map_height, map_width;

    char **data;
} map_bomb;

struct texture {
    SDL_Texture* ground;
    SDL_Texture* wall;
    SDL_Texture* bomb;
} texture;

// global variables
extern int game_is_running;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern int last_frame_time;

// setup functions
void setup(void);

// game loop functions
void process_input();
void update(void);
void render(map map_data);

// sdl window functions
int initialize_window(void);
void destroy_window(void);

// initialisation map functions
map init_map();

#endif
