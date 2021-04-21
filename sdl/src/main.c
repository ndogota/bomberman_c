#include "../include/main.h"
#include "../include/map.h"

// init sdl window
int initialize_window(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return false;
    }

    window = SDL_CreateWindow(
            NULL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            0
    );

    if (!window) {
        fprintf(stderr, "Error creating SDL Window.\n");
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        fprintf(stderr, "Error creating SDL Renderer.\n");
        return false;
    }

    return true;
}

// input processing
void process_input(void) {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            game_is_running = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                game_is_running = false;
            if (event.key.keysym.sym == SDLK_LEFT)
                player.x -= 64;
            if (event.key.keysym.sym == SDLK_RIGHT)
                player.x += 64;
            if (event.key.keysym.sym == SDLK_UP)
                player.y -= 64;
            if (event.key.keysym.sym == SDLK_DOWN)
                player.y += 64;
            break;
    }
}

// setup our game
void setup(void) {
    // init the ball object moving down at a constant velocity
    player.x = 64;
    player.y = 64;
    player.width = 64;
    player.height = 64;
    player.sprite = SDL_CreateTextureFromSurface(renderer, IMG_Load("/home/debian/Documents/Projects/bomberman_c/sdl/sprite/player.png"));

    texture.ground = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("/home/debian/Documents/Projects/bomberman_c/sdl/sprite/ground.bmp"));
    texture.wall = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("/home/debian/Documents/Projects/bomberman_c/sdl/sprite/wall.bmp"));
}

// update
void update(void) {
    // waste some time / sleep until we reach the frame target time
    //while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));

    // sleep the execution until we reach the target frame time in milliseconds
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
    // only call delay if we are too fast to process this frame
    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
        SDL_Delay(time_to_wait);
    }

    // difference of ticks from last frame converted to second
    // delta time is the amount elapsed since the last frame
    // get a delta time factor converted to seconds to be used to update our objects
    //float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;

    // store the milliseconds of the current frame to be used in the next one
    last_frame_time = SDL_GetTicks();

    // update ball and paddle position
    /*ball.x += ball.vel_x * delta_time;
    ball.y += ball.vel_y * delta_time;
    paddle.x += paddle.vel_x * delta_time;
    paddle.y += paddle.vel_y * delta_time;*/
}

// render
void render(map map_data) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // drawing map
    for(int height = 0, i = 0; height < map_data.map_height; height++, i++) {
        for(int width = 0, j = 0; width < map_data.map_width; width++, j++) {
            SDL_Rect src = {0, 0, TILE_HEIGHT, TILE_WIDTH};
            SDL_Rect dst = {height * TILE_HEIGHT, width * TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH};

            if(map_data.data[i][j] == wall) {
                SDL_RenderCopy(renderer, texture.wall, &src, &dst);
            } else if (map_data.data[i][j] == ground) {
                SDL_RenderCopy(renderer, texture.ground, &src, &dst);
            }
        }
    }

    // draw the player
    SDL_Rect src = {0, 0, TILE_HEIGHT, TILE_WIDTH};
    SDL_Rect dst = {player.x, player.y, TILE_HEIGHT, TILE_WIDTH};
    SDL_RenderCopy(renderer, player.sprite, &src, &dst);

    // render the renderer
    SDL_RenderPresent(renderer);
}

/*texture init_texture()
{
    texture map_texture = {
            SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("/home/debian/Documents/Projects/bomberman_c/sdl/sprite/ground.bmp"))
    };

    return map_texture;
}*/

map init_map()
{
    map map_data = {
            TILE_HEIGHT,
            TILE_WIDTH,
            MAP_HEIGHT,
            MAP_WIDTH,
            map_syntax("/home/debian/Documents/Projects/bomberman_c/sdl/map/map_1.txt")
    };

    return map_data;
}

// destroy window and renderer
void destroy_window(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    map map_data = init_map();
    game_is_running = initialize_window();

    setup();

    while (game_is_running) {
        process_input();
        update();
        render(map_data);
    }

    destroy_window();

    return 0;
}

