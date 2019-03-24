#ifndef _ELMA_BOTTY_WORLD_H
#define _ELMA_BOTTY_WORLD_H

#include "elma/elma.h" // Note installation directory for elma

#include "wander.h"
#include "makenoise.h"
#include "evade.h"
#include "user_interface.h"

namespace bottyworld {

    using namespace std::chrono;
    using namespace elma;    

    //! A stop watch class, that inherits from StateMachine
    class BottyWorld : public StateMachine {

        public:
        //! Make a new bottyworld.
        BottyWorld();

        //! Start bottyworld.
        void begin();

        //! Make noise when the Intruder is detected.
        void noise();

        //! Add a lap time to the list of lap times.
        void lap();

        //! Move botty into an evasive mode.
        void evading();

        //! Provide status of whether or not an Intruder has been introduced by the user.
        int intruder();

        //! Introduce the Intruder.
        void intruder_on();

        //! Make the Intruder disappear.
        void intruder_off();        

        //! Get the character representation of botty.
        char value();

        //! Reset environment.
        void reset_old();


        private:

        // When overriding the StateMachine class, put state declarations here.
        WanderState wander;
        MakenoiseState makenoise;
        EvadeState evade;

        // Other private variables

        char _bottychar;

        int _intruderstatus;

        bool _running;
        high_resolution_clock::time_point _start_time;
        high_resolution_clock::duration _elapsed;
        vector<high_resolution_clock::duration> _laps;

    };

}

#endif