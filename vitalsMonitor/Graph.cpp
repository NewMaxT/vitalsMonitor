#include "Graph.h"

/*
* @brief Graph class constructor.
* @brief This class displays the values streamed from a sensor to the screen using a graph.
* @brief All paramaters of the constructor are assigned to a private member.
* @param[in] wS means Width Screen size in pixel
* @param[in] hS means Height Screen size in pixel
* @param[in] px means x-Axis Position of the graph in pixel
* @param[in] py means y-Axis Position of the graph in pixel
* @param[in] sensorAmplitude means Amplitude of the sensor used
* @see Sensors Class
*/
Graph::Graph(const int wS,const int hS,const int px,const int py,const int sensorAmplitude)
{
    m_wSize = wS;
    m_hSize = hS;

    m_xPos = px;
    m_yPos = py;

    m_amplitude = sensorAmplitude;
}
/*
* @brief Set value of the y-Axis
* @brief This function set the value for the y-Axis and x-Axis
* @param[in] data means the value of the sensor
* @param[in] x means the actual pixel to be draw in the x-Axis
* @see Sensors Class
*/
void Graph::setValue(float data, int x) {
    m_val = data * static_cast<float>(m_amplitude);
    m_val += static_cast<float>(m_yPos + m_hSize / 2);
    m_x = x + m_xPos;
};
/*
* @brief Renders the graph
* @brief This function renders the graph on screen
* @param SDL_Renderer* (Pointer to the SDL Renderer object)
*/
void Graph::renderGraph(SDL_Renderer* renderer) {
    SDL_RenderDrawPointF(renderer, static_cast<float>(m_x), m_val);
}
