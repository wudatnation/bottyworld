#include <iostream>
#include <chrono>
#include <vector>

#include "bottyworld.h"

using namespace std::chrono;
using namespace elma;
using namespace bottyworld;

BottyWorld& MakenoiseState:: bottyworld() { return (BottyWorld&) state_machine(); }



void MakenoiseState::exit(const Event& e) {
    if ( e.name() == "reset" ) {
        bottyworld().begin();
        bottyworld().intruder_off();
    } else if ( e.name() == "proximity warning" ) {
        bottyworld().evading();
    }
}
