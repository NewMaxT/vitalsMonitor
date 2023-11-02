#pragma once

#include <vector>
#include <SDL_render.h>
#include <iostream>

/*
* @brief Graph class.
* @brief This class displays the values streamed from a sensor to the screen using a graph.
* @see Sensors Class
*/
class Graph
{
private:
    int m_hSize;
    int m_wSize;
    int m_amplitude;

    int m_xPos = 0;
    int m_x = 0;
    int m_yPos = 0;

    float m_val = 0;
public:
    Graph(int wS, int hS, int px, int py, int sensorAmplitude);
    void setValue(float data, int x);
    void renderGraph(SDL_Renderer* renderer);
};

