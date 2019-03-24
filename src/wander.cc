#include <iostream>
#include <chrono>
#include <vector>

#include "bottyworld.h"

using namespace std::chrono;
using namespace elma;
using namespace bottyworld;

BottyWorld&WanderState:: bottyworld() { return (BottyWorld&) state_machine(); }

void WanderState::exit(const Event& e) {

    if ( e.name() == "intruder detected" ) {
        // User stopped the bottyworld
        bottyworld().intruder_on();
        bottyworld().noise();
    }
}
