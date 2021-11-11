#include "utils/config.hpp"

#include "core/app.hpp"

int main(int argc, char** argv)
{
    if(Conf::argParse(argc, argv))
    {
        Application app;
    }
}