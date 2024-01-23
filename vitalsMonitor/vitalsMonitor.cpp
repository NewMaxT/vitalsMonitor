#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <math.h>
#include "Sensors.h" // TODO: Look to handle sensors differently
#include "Graph.h"

// TODO: REPLACE HARD CODED PARAMS BY CONFIG FILE PARAMS

// SCREEN HARD CODED PARAMETERS
enum
{
    SCREEN_W_SIZE = 1920,
    SCREEN_H_SIZE = 1080
};

// GRAPH HARD CODED PARAMETERS
enum
{
    GRAPH_W_SIZE = 1640,
    GRAPH_H_SIZE = 250,
    GRAPH_X_POS = 280,
    GRAPH_Y_POS = 80
};

Graph* BPM = new Graph(GRAPH_W_SIZE, GRAPH_H_SIZE, GRAPH_X_POS, GRAPH_Y_POS, 100);
Graph* Sp02 = new Graph(GRAPH_W_SIZE, GRAPH_H_SIZE, GRAPH_X_POS, GRAPH_Y_POS + GRAPH_H_SIZE, 100);
Graph* RR = new Graph(GRAPH_W_SIZE, GRAPH_H_SIZE, GRAPH_X_POS, GRAPH_Y_POS + GRAPH_H_SIZE * 2, 100);

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
    static void text(TTF_Font* font, const char *text, SDL_Color color, SDL_Renderer* renderer, int x, int y) {
        // TEXTS
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        // Get the dimensions of the text surface
        const int textWidth = textSurface->w;
        const int textHeight = textSurface->h;

        // Define the rendering position
        const SDL_Rect textRect = { x - textWidth / 2, y - textHeight / 2, textWidth, textHeight };

        // Render the text
        SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

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
    static void line(int x, int y, int xEnd, int yEnd, SDL_Color color, SDL_Renderer* renderer) {

        // coords[2][2] = { {x,y},  // Start position
        //                  {x,y} } // End position

        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // H1 LINE
        SDL_RenderDrawLine(renderer, x, y, xEnd, yEnd);
    }
};

/*
* @brief Connecting to hardware sensors
* @brief This function connects to the sensors and returns an object that can be used to get data stream from each sensors.
* @brief It is mandatory before launching the UI.
* @param None.
* @throws HARDWARE_STARTUP_NOT_READY is thrown if the startup can't connect to the hardware in time
* @throws THREADS_STARTUP_FAILURE is thrown if the startup procedure fails
* @see Sensors Class
* @return Returns an object that handles the hardware data stream if connected.
* @warning Useless for the moment
*/
Sensors startup() {
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

            // TODO: Check the data integrity 
            std::cout << "WAITING FOR SENSORS\n\n";
            std::cout << "\033[7;32mSTARTED UP\033[4;0m\n";

            return hdw_Sensors;
        } else {
            throw std::runtime_error("HARDWARE_STARTUP_NOT_READY");
        }

        // TODO: MANAGE THREADS AND ASYNC FUNCTIONS IF USED (I might run on single thread (except SDL) if I can make that not too heavy)
    }
    catch (const std::exception& exc)
    {
        std::cout << "\033[1;31m" << "FATAL: " << exc.what() << "\033[1;0m\n";
        std::cout << "\033[7;31m" << "FATAL: " << "STARTUP FAILURE" << "\033[1;0m\n\n";
        std::cout << "\033[7;31m" << "FATAL: " << "Enter to quit the program..." << "\033[1;0m";
        std::cin.get();
        throw;
    }
}

// TODO: Function needs more comments
int gui(Sensors *sensors) {
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
        "Health Monitoring Software",       // Window title
        SDL_WINDOWPOS_CENTERED,             // X position
        SDL_WINDOWPOS_CENTERED,             // Y position
        SCREEN_W_SIZE,                      // Width
        SCREEN_H_SIZE,                      // Height
        SDL_WINDOW_FULLSCREEN_DESKTOP       // Puts in fullscreen the window
    );

    if (!window) {
        // Handle window creation error
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
        return 1; //TODO: Manage throws and exit codes
    }


    // Open style font
    TTF_Font* font = TTF_OpenFont("OpenSans-Regular.ttf", 50);

    // Main loop
    bool quit = false;
    SDL_Event event;
    
    const std::vector<float> data = sensors->get_SampleData(); // FOR TEST PURPOSES

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
        // TODO: Stop using magic numbers
        
        drawMethods::line(80, 80, 80, 1080, SDL_Color{ 255, 255, 255, 255 }, renderer); // H1 LINE
        drawMethods::line(280, 80, 280, 830, SDL_Color{ 255, 255, 255, 255 }, renderer); // H2 LINE
        drawMethods::line(725, 830, 725, 1080, SDL_Color{ 255, 255, 255, 255 }, renderer); // H3 LINE
        drawMethods::line(1500, 830, 1500, 1080, SDL_Color{ 255, 255, 255, 255 }, renderer); // H4 LINE
        drawMethods::line(0, 80, 1920, 80, SDL_Color{ 255, 255, 255, 255 }, renderer);  // W1 LINE
        drawMethods::line(80, 330, 1920, 330, SDL_Color{ 50, 125, 255, 255 }, renderer);  // W2 LINE
        drawMethods::line(80, 580, 1920, 580, SDL_Color{ 50, 125, 255, 255 }, renderer);  // W3 LINE
        drawMethods::line(80, 830, 1920, 830, SDL_Color{ 50, 125, 255, 255 }, renderer);  // W4 LINE

        // Draw Text
        // TODO: Stop using magic numbers
        
        drawMethods::text(font, "HR", SDL_Color{255, 0, 0, 255}, renderer, 120, 110);

        TTF_SetFontSize(font, 100);
        drawMethods::text(font, "00", SDL_Color{ 255, 255, 255, 255 }, renderer, 180, 205);
        TTF_SetFontSize(font, 50);

        drawMethods::text(font, "Sp02", SDL_Color{ 0, 0, 255, 255 }, renderer, 150, 360);

        TTF_SetFontSize(font, 100);
        drawMethods::text(font, "00", SDL_Color{ 255, 255, 255, 255 }, renderer, 180, 455);
        TTF_SetFontSize(font, 50);

        drawMethods::text(font, "RR", SDL_Color{ 0, 255, 0, 255 }, renderer, 120, 610);

        TTF_SetFontSize(font, 100);
        drawMethods::text(font, "00", SDL_Color{ 255, 255, 255, 255 }, renderer, 180, 705);
        TTF_SetFontSize(font, 50);

        drawMethods::text(font, "Sys (mmHg)", SDL_Color{ 120, 200, 200, 255 }, renderer, 230, 880);

        TTF_SetFontSize(font, 100);
        drawMethods::text(font, "000", SDL_Color{ 255, 255, 255, 255 }, renderer, 225, 975);
        drawMethods::text(font, "/", SDL_Color{ 255, 255, 255, 255 }, renderer, 390, 975);
        TTF_SetFontSize(font, 50);

        drawMethods::text(font, "Dia (mmHg)", SDL_Color{ 120, 200, 200, 255 }, renderer, 550, 880);

        TTF_SetFontSize(font, 100);
        drawMethods::text(font, "00", SDL_Color{ 255, 255, 255, 255 }, renderer, 550, 975);
        TTF_SetFontSize(font, 50);

        drawMethods::text(font, "Body Temp.", SDL_Color{ 120, 200, 200, 255 }, renderer, 1650, 880);

        TTF_SetFontSize(font, 100);
        drawMethods::text(font, "00", SDL_Color{ 255, 255, 255, 255 }, renderer, 1650, 975);
        drawMethods::text(font, "\u00B0C", SDL_Color{ 255, 255, 255, 255 }, renderer, 1775, 975);
        TTF_SetFontSize(font, 50);

        // Render graphs

        for (int index = 0; index < static_cast<int>(data.size()); index++) {
            BPM->setValue(data[index], index);
            BPM->renderGraph(renderer);

            Sp02->setValue(data[index], index);
            Sp02->renderGraph(renderer);
            
            RR->setValue(data[index], index);
            RR->renderGraph(renderer);
            
            // Delay to control frame rate
            // TODO: Find a good delay to balance performance and refresh rate
            SDL_Delay(16);

            // Show frame
            SDL_RenderPresent(renderer);
        }
    }

    // Destroy the objects : font, renderer, window
    // and quit SDL_ttf and SDL
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

/*
* @brief Entry point of the program
*/
int main(int argc, char* argv[])
{
    Sensors sensors = startup();
    return gui(&sensors);
}
