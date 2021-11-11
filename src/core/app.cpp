#include "core/app.hpp"

Application::Application()
{
    this->run();
}

/***
 * EVENTS
 *
 */

void Application::eventAdd()
{
    this->Super::m_ev_manager.addEventCallback(sf::Event::Closed, [&](sfev::CstEv){
        this->Super::m_window.close();
    });

    this->Super::m_ev_manager.addKeyReleasedCallback(sf::Keyboard::Escape, [&](sfev::CstEv){
        this->Super::m_window.close();
    });

    this->Super::m_ev_manager.addKeyReleasedCallback(sf::Keyboard::S, [&](sfev::CstEv){
        this->m_ev_state.speed = (this->m_ev_state.speed + 1) % 3;
        switch(this->m_ev_state.speed){
            case 0:
                this->Super::m_window.setFramerateLimit(Conf::FRAMERATE);
                break;
            case 1:
                this->Super::m_window.setFramerateLimit(0);
                this->Super::m_window.setVerticalSyncEnabled(true);
                break;
            case 2:
                this->Super::m_window.setVerticalSyncEnabled(false);
            default:
                break;
        }
    });

    this->Super::m_ev_manager.addKeyReleasedCallback(sf::Keyboard::D, [&](sfev::CstEv){
        this->m_ev_state.debug = !this->m_ev_state.debug;
    });
}

/***
 * DRAW
 *
 */

void Application::drawInit()
{
}

void Application::drawLoop()
{
}

/***
 * MAIN
 *
 */

void Application::mainInit()
{
}

void Application::mainLoop()
{
}
