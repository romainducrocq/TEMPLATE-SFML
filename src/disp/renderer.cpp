#include "disp/renderer.hpp"

Renderer::Renderer(sf::RenderWindow& window)
    : m_window(window)
{}

void Renderer::drawShape(sf::ConvexShape& convex_shape, float position_x, float position_y,
                         sf::Color fill_color, int outline_thickness, sf::Color outline_color)
{
    convex_shape.setPosition(sf::Vector2f(position_x, position_y));
    convex_shape.setOutlineThickness(outline_thickness);
    convex_shape.setFillColor(fill_color);
    convex_shape.setOutlineColor(outline_color);
    this->m_window.draw(convex_shape);
}

void Renderer::drawCircle(float radius, float position_x, float position_y,
                          sf::Color fill_color, int outline_thickness, sf::Color outline_color)
{
    this->m_circle_shape.setRadius(radius);
    this->m_circle_shape.setPosition(sf::Vector2f(position_x, position_y));
    this->m_circle_shape.setOutlineThickness(outline_thickness);
    this->m_circle_shape.setFillColor(fill_color);
    this->m_circle_shape.setOutlineColor(outline_color);
    this->m_window.draw(this->m_circle_shape);
}

void Renderer::drawRectangle(float size_x, float size_y, float position_x, float position_y,
                             sf::Color fill_color, int outline_thickness, sf::Color outline_color)
{
    this->m_rectangle_shape.setSize(sf::Vector2f(size_x, size_y));
    this->m_rectangle_shape.setPosition(sf::Vector2f(position_x, position_y));
    this->m_rectangle_shape.setOutlineThickness(outline_thickness);
    this->m_rectangle_shape.setFillColor(fill_color);
    this->m_rectangle_shape.setOutlineColor(outline_color);
    this->m_window.draw(this->m_rectangle_shape);
}

void Renderer::drawLine(float position_x1, float position_y1, float position_x2, float position_y2,
                        sf::Color color)
{
    this->m_line[0].position.x = position_x1;
    this->m_line[0].position.y = position_y1;
    this->m_line[0].color = color;

    this->m_line[1].position.x = position_x2;
    this->m_line[1].position.y = position_y2;
    this->m_line[1].color = color;

    this->m_window.draw(this->m_line, 2, sf::Lines);
}

/***
 * INIT
 *
 */

/***
 * LOOP
 *
 */
