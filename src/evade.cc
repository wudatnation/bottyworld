#include <iostream>
#include <chrono>
#include <vector>

#include "bottyworld.h"

using namespace std::chrono;
using namespace elma;
using namespace bottyworld;

BottyWorld& EvadeState:: bottyworld() { return (BottyWorld&) state_machine(); }

void EvadeState::exit(const Event& e) {
    if ( e.name() == "reset" ) {
        bottyworld().noise();
    }
}
