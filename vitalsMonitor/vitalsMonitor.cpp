#include <iostream>
#include "Sensors.h"
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_ttf.h>

void drawText(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer, int x, int y) {
    // TEXTS
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "HR", color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    // Get the dimensions of the text surface
    int textWidth = textSurface->w;
    int textHeight = textSurface->h;

    // Define the rendering position
    SDL_Rect textRect = { x - textWidth / 2, y - textHeight / 2, textWidth, textHeight };

    // Render the text
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    // Free resources
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);


    // Show frame
    SDL_RenderPresent(renderer);

}

int main(int argc, char* argv[])
{
    char buffer;

    std::cout << "******************************************************************\n";
    std::cout << "ECG, SpO2, Blood Pressure and Respiratory Rate monitoring software\n\n";

    std::cout << "                           Starting...\n\n\n";

    try
    {
        /* MANAGE HARDWARE */

        /* CODE HERE */
        bool conMethod[3] = {true, false, false};
        
        Sensors hdw_Sensors(true, false, false, conMethod);

        if (hdw_Sensors.ready) {
            std::cout << "HARDWARE API " << "\033[1;32m" << "OK" << "\033[1;0m\n";
        }
        else {
            throw std::runtime_error("HARDWARE STARTUP NOT READY");
        }

        /* MANAGE THREADS AND ASYNC FUNCTIONS */

        /* CODE HERE */

        if (true) {
            std::cout << "THREADS " << "\033[1;32m" << "OK" << "\033[1;0m\n\n";
        }
        else {
            throw std::runtime_error("THREADS STARTUP FAILURE");
        }
    }
    catch (const std::exception& exc)
    {
        std::cout << "\033[1;31m" << "FATAL: " << exc.what() << "\033[1;0m\n";
        std::cout << "\033[7;31m" << "FATAL: " << "STARTUP FAILURE" << "\033[1;0m\n\n";
        std::cout << "\033[7;31m" << "FATAL: " << "Enter to quit the program..." << "\033[1;0m";
        std::cin.get();
        throw exc;
    }

    std::cout << "WAITING FOR SENSORS\n\n";
    std::cout << "\033[7;32mSTARTED UP\033[4;0m\n";
    std::cout << "\033[1;32mSTARTING GUI\033[1;0m\n";

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Handle initialization error
        std::cout << "\033[7;31m" << "FATAL: " << "(GUI) SDL INIT FAILURE" << "\033[1;0m\n\n";
        return 1;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        // Handle TTF initialization error
        std::cout << "\033[7;31m" << "FATAL: " << "(GUI) SDL TTF INIT FAILURE" << "\033[1;0m\n\n";
        SDL_Quit();
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "Health Monitoring Software",                       // Window title
        SDL_WINDOWPOS_CENTERED,             // X position
        SDL_WINDOWPOS_CENTERED,             // Y position
        1920,                               // Width
        1080,                               // Height
        SDL_WINDOW_FULLSCREEN_DESKTOP       // Flags
    );

    if (!window) {
        // Handle window error
        std::cout << "\033[7;31m" << "FATAL: " << "(GUI) SDL WINDOW CREATION FAILURE" << "\033[1;0m\n\n";
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        // Handle renderer creation error
        std::cout << "\033[7;31m" << "FATAL: " << "(GUI) SDL RENDERER CREATION FAILURE" << "\033[1;0m\n\n";
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }


    // Open style font
    TTF_Font* CategoryTitle = TTF_OpenFont("OpenSans-Regular.ttf", 50);


    // Main loop
    bool quit = false;
    SDL_Event event;

    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }


        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);


        // LINES
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // H1 LINE
        SDL_RenderDrawLine(renderer, 80, 0, 80, 1080);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // W1 LINE
        SDL_RenderDrawLine(renderer, 0, 80, 1920, 80);

        SDL_SetRenderDrawColor(renderer, 50, 125, 255, 255); // W2 LINE
        SDL_RenderDrawLine(renderer, 80, 330, 1920, 330);

        SDL_SetRenderDrawColor(renderer, 50, 125, 255, 255); // W3 LINE
        SDL_RenderDrawLine(renderer, 80, 580, 1920, 580);

        SDL_SetRenderDrawColor(renderer, 50, 125, 255, 255); // W4 LINE
        SDL_RenderDrawLine(renderer, 80, 830, 1920, 830);

        // Draw Text

        drawText(CategoryTitle, SDL_Color{ 255, 255, 255, 255 }, renderer, 120, 110);


        // Delay to control frame rate
        SDL_Delay(16);  // Assuming 60 FPS
    }

    // Destroy font, renderer, window, and quit SDL_ttf and SDL

    TTF_CloseFont(CategoryTitle);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}



