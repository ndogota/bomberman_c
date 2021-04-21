#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

#define TILE_HEIGHT 64
#define TILE_WIDTH 64

#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

// player struct
struct player {
    float x;
    float y;
    float width;
    float height;

    SDL_Texture *sprite;
} player;

typedef struct map {
    int tile_height, tile_width;
    int map_height, map_width;

    char **data;
} map;

enum tile_type {
    wall = '#',
    ground = ' '
};

// global variables
int game_is_running = false;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int last_frame_time = 0;

struct texture {
    SDL_Texture* ground;
    SDL_Texture* wall;
} texture;

// setup functions
void setup(void);

// sdl window functions
int initialize_window(void);
void destroy_window(void);

map init_map();

// game loop functions
void process_input(void);
void update(void);
void render(map map_data);