#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800;  // Image width
const int HEIGHT = 600; // Image height
const int MAX_ITER = 1000; // Maximum number of iterations for Mandelbrot set

// Function to check if a point is in the Mandelbrot set
int mandelbrot(double real, double imag) {
    int iter = 0;
    double z_real = real;
    double z_imag = imag;

    while (iter < MAX_ITER) {
        double z_real2 = z_real * z_real;
        double z_imag2 = z_imag * z_imag;

        if (z_real2 + z_imag2 > 4.0) {
            return iter;
        }

        z_imag = 2.0 * z_real * z_imag + imag;
        z_real = z_real2 - z_imag2 + real;

        iter++;
    }

    return MAX_ITER;
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Mandelbrot Set", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, WIDTH, HEIGHT);
    if (!texture) {
        std::cerr << "SDL_CreateTexture Error: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Create a buffer to store pixel data
    uint32_t* pixels = new uint32_t[WIDTH * HEIGHT];

    // Generate Mandelbrot set
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;

            int color = mandelbrot(real, imag);
            pixels[y * WIDTH + x] = SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_ARGB8888), 0, color % 256, color % 256);
        }
    }

    // Update the texture with the pixel data
    SDL_UpdateTexture(texture, NULL, pixels, WIDTH * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Cleanup
    delete[] pixels;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}
