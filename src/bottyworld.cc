#include <chrono>
#include <vector>

#include "bottyworld.h"

using namespace std::chrono;
using namespace elma;
using namespace bottyworld;

BottyWorld::BottyWorld() : StateMachine("bottyworld") {

    // Define state machine initial states and transitions here
    set_initial(wander);
    set_propagate(false);
    add_transition("reset", makenoise, wander);
    add_transition("intruder detected", wander, makenoise);
    add_transition("reset", evade, makenoise);
    add_transition("proximity warning", makenoise, evade);


    // Make sure we start in the right condition
    reset_old();
}

char BottyWorld::value() {
    //if ( current().name() == "wander" ) {
        return _bottychar;
        //return high_resolution_clock::now() - _start_time + _elapsed;
    //} else {
        //return _elapsed;
    //}
}

int BottyWorld::intruder() {
    return _intruderstatus;
}

void BottyWorld::intruder_on() {
    _intruderstatus = 1;
}

void BottyWorld::intruder_off() {
    _intruderstatus = 0;
}

void BottyWorld::begin() {
    _bottychar = 'b';
    //_start_time = high_resolution_clock::now();
}

void BottyWorld::reset_old() {
    _bottychar = 'b';
    //_elapsed = high_resolution_clock::duration::zero();
    //_laps.clear();
}

void BottyWorld::noise() {
    beep();
    _bottychar = 'b';
    //_elapsed += high_resolution_clock::now() - _start_time;
}


void BottyWorld::evading() {
    _bottychar = 'E';
}