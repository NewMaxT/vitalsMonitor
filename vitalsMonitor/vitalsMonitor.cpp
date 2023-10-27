#include <iostream>
#include "Sensors.h" // TODO: Look to handle sensors differently
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <math.h>


/*
 * @brief Struct representing methods for drawing in the application.
 */

struct drawMethods {
    /*
     * @brief Draw text on the renderer.
     *
     * This function draws text on the renderer at the specified position using
     * the given font and color.
     *
     * @param font The font used for rendering the text.
     * @param color The color of the text.
     * @param renderer The SDL renderer.
     * @param x The x-coordinate for the text position.
     * @param y The y-coordinate for the text position.
     */
    void text(TTF_Font* font, const char *text, SDL_Color color, SDL_Renderer* renderer, int x, int y) {
        // TEXTS
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
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

    }


    /*
     * @brief Draw a line on the renderer.
     *
     * This function draws a line on the renderer from the specified start
     * position to the end position with the given color.
     *
     * @param x The x-coordinate of the start position.
     * @param y The y-coordinate of the start position.
     * @param xEnd The x-coordinate of the end position.
     * @param yEnd The y-coordinate of the end position.
     * @param color The color of the line.
     * @param renderer The SDL renderer.
     */
    void line(int x, int y, int xEnd, int yEnd, SDL_Color color, SDL_Renderer* renderer) {

        // coords[2][2] = { {x,y},  // Start position
        //                  {x,y} } // End position

        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // H1 LINE
        SDL_RenderDrawLine(renderer, x, y, xEnd, yEnd);
    }
};

struct graph {
    // Graph parameters
    const int graphWidth = 1640;
    const int graphHeight = 250;

    const int bpm_xOffset = 280;
    const int bpm_yOffset = 80;

    const int Sp02_xOffset = 280;
    const int Sp02_yOffset = 330;

    const int RR_xOffset = 280;
    const int RR_yOffset = 580;

    // Real-time graph logic
    double time = 0.0;
    const double bpm_frequency = 0.01;
    const double bpm_amplitude = 100;

    const double Sp02_frequency = 0.01;
    const double Sp02_amplitude = 100;

    const double RR_frequency = 1.0;
    const double RR_amplitude = 100;

    void renderGraph(SDL_Renderer *renderer) {
        


        for (int x = 0; x < graphWidth; ++x) {

            double bpm_y = bpm_amplitude * sin(bpm_frequency * time);
            double Sp02_y = Sp02_amplitude * sin(Sp02_frequency * time);
            double RR_y = RR_amplitude * sin(RR_frequency * time);

            int bpm_graphY = graphHeight / 2 - (int)bpm_y + bpm_yOffset;
            int Sp02_graphY = graphHeight / 2 - (int)Sp02_y + Sp02_yOffset;
            int RR_graphY = graphHeight / 2 - (int)RR_y + RR_yOffset;

            SDL_RenderDrawPoint(renderer, x + bpm_xOffset, bpm_graphY);
            SDL_RenderDrawPoint(renderer, x + Sp02_xOffset, Sp02_graphY);
            SDL_RenderDrawPoint(renderer, x + RR_xOffset, RR_graphY);

        }

        time += 0.1;
    }

};



/*
* @brief Proceed to starts the needed services like BLE, ...
*
* This function starts the process of Bluetooth Low Energy, creates Sensors objects, ...
* It is needed before lauching the GUI
*/
void startup() {
    char buffer;

    std::cout << "******************************************************************\n";
    std::cout << "ECG, SpO2, Blood Pressure and Respiratory Rate monitoring software\n\n";

    std::cout << "                           Starting...\n\n\n";

    try
    {
        // TODO: MANAGE HARDWARE

        bool conMethod[3] = { true, false, false }; // TODO: Let the user choose the connection method

        Sensors hdw_Sensors(true, false, false, conMethod); 

        if (hdw_Sensors.ready) {
            std::cout << "HARDWARE API " << "\033[1;32m" << "OK" << "\033[1;0m\n";
        }
        else {
            throw std::runtime_error("HARDWARE STARTUP NOT READY");
        }

        // TODO: MANAGE THREADS AND ASYNC FUNCTIONS IF USED (I might run on single thread (except SDL) if I can make that not too heavy)

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
}

int gui() {
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
    TTF_Font* font = TTF_OpenFont("OpenSans-Regular.ttf", 50);
    

    // Main loop
    bool quit = false;
    SDL_Event event;

    drawMethods draw;
    graph graphVitals;




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

        draw.line(80, 80, 80, 1080, SDL_Color{ 255, 255, 255, 255 }, renderer); // H1 LINE
        draw.line(280, 80, 280, 830, SDL_Color{ 255, 255, 255, 255 }, renderer); // H2 LINE
        draw.line(725, 830, 725, 1080, SDL_Color{ 255, 255, 255, 255 }, renderer); // H3 LINE
        draw.line(1500, 830, 1500, 1080, SDL_Color{ 255, 255, 255, 255 }, renderer); // H4 LINE
        draw.line(0, 80, 1920, 80, SDL_Color{ 255, 255, 255, 255 }, renderer);  // W1 LINE
        draw.line(80, 330, 1920, 330, SDL_Color{ 50, 125, 255, 255 }, renderer);  // W2 LINE
        draw.line(80, 580, 1920, 580, SDL_Color{ 50, 125, 255, 255 }, renderer);  // W3 LINE
        draw.line(80, 830, 1920, 830, SDL_Color{ 50, 125, 255, 255 }, renderer);  // W4 LINE

        // Draw Text

        draw.text(font, "HR", SDL_Color{255, 0, 0, 255}, renderer, 120, 110);

        TTF_SetFontSize(font, 100);
        draw.text(font, "00", SDL_Color{ 255, 255, 255, 255 }, renderer, 180, 205);
        TTF_SetFontSize(font, 50);

        draw.text(font, "Sp02", SDL_Color{ 0, 0, 255, 255 }, renderer, 150, 360);

        TTF_SetFontSize(font, 100);
        draw.text(font, "00", SDL_Color{ 255, 255, 255, 255 }, renderer, 180, 455);
        TTF_SetFontSize(font, 50);

        draw.text(font, "RR", SDL_Color{ 0, 255, 0, 255 }, renderer, 120, 610);

        TTF_SetFontSize(font, 100);
        draw.text(font, "00", SDL_Color{ 255, 255, 255, 255 }, renderer, 180, 705);
        TTF_SetFontSize(font, 50);

        draw.text(font, "Sys (mmHg)", SDL_Color{ 120, 200, 200, 255 }, renderer, 230, 880);

        TTF_SetFontSize(font, 100);
        draw.text(font, "000", SDL_Color{ 255, 255, 255, 255 }, renderer, 225, 975);
        draw.text(font, "/", SDL_Color{ 255, 255, 255, 255 }, renderer, 390, 975);
        TTF_SetFontSize(font, 50);

        draw.text(font, "Dia (mmHg)", SDL_Color{ 120, 200, 200, 255 }, renderer, 550, 880);

        TTF_SetFontSize(font, 100);
        draw.text(font, "00", SDL_Color{ 255, 255, 255, 255 }, renderer, 550, 975);
        TTF_SetFontSize(font, 50);

        draw.text(font, "Body Temp.", SDL_Color{ 120, 200, 200, 255 }, renderer, 1650, 880);

        TTF_SetFontSize(font, 100);
        draw.text(font, "00", SDL_Color{ 255, 255, 255, 255 }, renderer, 1650, 975);
        draw.text(font, "°C", SDL_Color{ 255, 255, 255, 255 }, renderer, 1775, 975);
        TTF_SetFontSize(font, 50);

        // Render graphs 

        graphVitals.renderGraph(renderer);

        // Show frame
        SDL_RenderPresent(renderer);

        // Delay to control frame rate
        SDL_Delay(16);  // Assuming 60 FPS
    }

    // Destroy font, renderer, window, and quit SDL_ttf and SDL

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

/*
 * @brief Entry point of the program
 */
int main(int argc, char* argv[])
{
    startup();
    return gui();
}