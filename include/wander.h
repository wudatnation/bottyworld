#ifndef _ELMA_BOTTY_WORLD_WANDER_H
#define _ELMA_BOTTY_WORLD_WANDER_H

#include "bottyworld.h"

namespace bottyworld {

    using namespace std::chrono;
    using namespace elma;

    class BottyWorld;  // Declare containing class so it can be refered to here
                      // before it is defined in bottyworld.h 

    //! The Wander state of the bottyworld
    class WanderState : public State {        

        public:
        //! Build a new Wander state
        WanderState() : State("wander") {}
        void entry(const Event& e) {}
        void during() {}

        //! Perform actions required when switching 
        //! \param e The event that triggered the transition        
        void exit(const Event&);

        BottyWorld& bottyworld();        

    };

}

#endif