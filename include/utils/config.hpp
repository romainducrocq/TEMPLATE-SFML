#ifndef _CONFIG_HPP
#define _CONFIG_HPP

#include <unistd.h>

#include <iostream>
#include <cstring>

template<typename T>
struct DefaultConf
{
    const static char* NAME;
    const static int BG_COL[3];
    const static int FRAMERATE;
    const static int ANTIALIAS;

    static int WIN_W;
    static int WIN_H;

    static bool argParse(int argc, char** argv)
    {
        for(;;){
            switch(getopt(argc, argv, "hv:")){
                case '?':
                case 'h':
                default :
                    std::cerr << "usage: apps/exec [-h] [-v VP]\n";
                    std::cerr << "\n";
                    std::cerr << DefaultConf<T>::NAME << "\n";
                    std::cerr << "\n";
                    std::cerr << "optional args:\n";
                    std::cerr << "  -h     show this help message and exit\n";
                    std::cerr << "  -v VP  set viewport size < 480 | 720 >\n";
                    std::cerr << "\n";
                    std::cerr << "optional cmds:\n";
                    std::cerr << "  key S  set speed 24FPS, VSYNC, MAX    \n";
                    std::cerr << "  key D  set debug NO, YES              \n";

                    return false;

                case -1:
                    break;

                case 'v':
                    if(std::strcmp(optarg, "480") == 0){
                        DefaultConf<T>::WIN_W = 720;
                        DefaultConf<T>::WIN_H = 480;
                    }else if(std::strcmp(optarg, "720") == 0){
                        DefaultConf<T>::WIN_W = 1280;
                        DefaultConf<T>::WIN_H = 720;
                    }
                    continue;

            }
            break;
        }

        return true;
    }
};

template<typename T>
const char* DefaultConf<T>::NAME = "SFML-Template";
template<typename T>
const int DefaultConf<T>::BG_COL[3] = { 51, 51, 51 };
template<typename T>
const int DefaultConf<T>::FRAMERATE = 24;
template<typename T>
const int DefaultConf<T>::ANTIALIAS = 0;

template<typename T>
int DefaultConf<T>::WIN_W = 720;
template<typename T>
int DefaultConf<T>::WIN_H = 480;

using Conf = DefaultConf<int>;

#endif