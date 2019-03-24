#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "bottyworld.h"

namespace bottyworld {

    using namespace std::chrono;
    using namespace elma;
    using namespace bottyworld;

    //! A user interface for the a BottyWorld object
    class UserInterface : public Process {

        public:

        //! Create a new bottyworld user interface using curses
        //! \param sw A reference to a BottyWorld object
        UserInterface(BottyWorld& sw);

        void init() {}
        void start() {}

        //! Display frame
        void show_frame();

        //! Display botty at a given position on the screen
        void show_botty(int y, int x, char bc);

        //! Display Intruder at a given position on the screen
        void show_intruder(int yi_pos, int xi_pos);

        //! Update the user interface by (a) reading keyboard input and (b) writing to the screen
        void update();
        void stop() {}

        private:
        BottyWorld& _bottyworld;

    };

}