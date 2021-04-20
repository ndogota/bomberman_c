#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define FPS 30
#define FRAME_TARGET_TIME (1000 / FPS)

// global variables
int game_is_running = false;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int last_frame_time = 0;

// player struct
struct player {
    float x;
    float y;
    float width;
    float height;
} player;

// setup functions
void setup(void);

// sdl window functions
int initialize_window(void);
void destroy_window(void);

// game loop functions
void process_input(void);
void update(void);
void render(void);