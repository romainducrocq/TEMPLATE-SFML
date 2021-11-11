#ifndef _APP_HPP
#define _APP_HPP

#include <SFML/Graphics.hpp>

#include "utils/config.hpp"
#include "utils/events.hpp"

#include "disp/window.hpp"

struct EventState
{
    int  speed = 0;
    bool debug = false;
};

class Application: public Window
{
    private:
        typedef Window Super;

        EventState m_ev_state;

    private:
        void eventAdd() override;

        void drawInit() override;

        void drawLoop() override;

        void mainInit() override;
        
        void mainLoop() override;

    public:
        Application();
};

#endif