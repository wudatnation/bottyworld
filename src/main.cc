#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "bottyworld.h"

using namespace std::chrono;
using namespace elma;
using namespace bottyworld;

int main() {

    Manager m;
    BottyWorld bottyworld;
    UserInterface ui(bottyworld);

    m.schedule(ui, 10_ms)
     .schedule(bottyworld, 10_ms)     
     .init()
     .run();

    endwin();     
     
}