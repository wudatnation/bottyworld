#ifndef _ELMA_BOTTY_WORLD_MAKENOISE_H
#define _ELMA_BOTTY_WORLD_MAKENOISE_H

#include "bottyworld.h"

namespace bottyworld {

    using namespace std::chrono;
    using namespace elma;

    class BottyWorld; // Declare containing class so it can be refered to here
                     // before it is defined in bottyworld.h

    //! A State class to represent the state in which the botty makes noises
    class MakenoiseState : public State {

        public:
        //! Construct a new Makenoise state
        MakenoiseState() : State("makenoise") {}
        void entry(const Event& e) {}
        void during() {}

        //! Perform actions required when switching
        //! \param e The event that triggered the transition
        void exit(const Event& e);

        //! \return A reference to the containing finite state machine object
        BottyWorld& bottyworld();

    };

}

#endif