#include <unistd.h>
#include "bottyworld.h"

using namespace bottyworld;

UserInterface::UserInterface(BottyWorld& sw) : Process("user input"), _bottyworld(sw) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
};


void UserInterface::show_frame() {

    mvprintw (0,0,"--------------------------------------------------------");
    mvprintw (1,0,"------------------b-o-t-t-y--w-o-r-l-d------------------");
    mvprintw (2,0,"--------------------------------------------------------");
    mvprintw (3,0,"--|                                                  |--");
    mvprintw (4,0,"--|                                                  |--");
    mvprintw (5,0,"--|                                                  |--");
    mvprintw (6,0,"--|                                                  |--");
    mvprintw (7,0,"--|                                                  |--");
    mvprintw (8,0,"--|                                                  |--");    
    mvprintw (9,0,"--|                                                  |--");
    mvprintw(10,0,"--|                                                  |--");    
    mvprintw(11,0,"--|                                                  |--");
    mvprintw(12,0,"--|                                                  |--");
    mvprintw(13,0,"--------------------------------------------------------");
    mvprintw(14,0,"--------------------------------------------------------");
    mvprintw(15,0,"[i] introduce intruder");
    mvprintw(16,0,"[r] reset");
    mvprintw(17,0,"[q] quit");
    mvprintw(18,0,"________________________________________________________");
    mvprintw(19,0," David A. Wu / ECE590 / UW / WINTER 2019 / Prof Klavins");
    }


void UserInterface::show_botty(int y, int x, char bc) {
    mvprintw(y+3,x+3,"%c",bc);
}

void UserInterface::show_intruder(int yi_pos, int xi_pos) {
    mvprintw(yi_pos+2, xi_pos+1, ".---.");
    mvprintw(yi_pos+3, xi_pos+1, "| I |");
    mvprintw(yi_pos+4, xi_pos+1, "^---^");
}

void UserInterface::update() {

    // USER INPUT
    // get a character from the user, if one is ready.
    // If no character is ready, getch() returns ERR (which is
    // ignored below since there is no condition in the switch statement)
    int c = getch();

    switch ( c ) { 
        case 'i':
            emit(Event("intruder detected"));
            break;
        case 'r':
            emit(Event("reset"));
            break;        
        case 'q':
            std::cout << "halting\n";
            halt();
            break;
    }

    // OUTPUT
    show_frame();

    static int y_pos = 0;
    static int x_pos = 0;
    y_pos += ((rand() % 3) - 1);
    x_pos += ((rand() % 3) - 1);

    static int yi_pos = rand() % 10;
    static int xi_pos = rand() % 50;

    if (y_pos == 10) {
        y_pos = 9;
    } else if (y_pos == -1) {
        y_pos = 0;
    };

    if (x_pos == 50) {
        x_pos = 49;
    } else if (x_pos == -1) {
        x_pos = 0;
    };

    show_botty(y_pos, x_pos, _bottyworld.value()); 

    if (_bottyworld.intruder()==1) {
        show_intruder(yi_pos, xi_pos);

        if ( (y_pos > yi_pos-2) && (y_pos < yi_pos+2) && (x_pos > xi_pos-2) && (x_pos < xi_pos+2) ) {
            emit(Event("proximity warning"));
  
            y_pos = yi_pos+3;
            if (y_pos > 9) {
                y_pos = 9;
            }

            x_pos = xi_pos+3;
            if (x_pos > 49) {
                x_pos = 49;
            }
        };
    } 


    static double battery_power = 2000;
    static int battery_normal = 1;
    double battery_percent;

    if (battery_normal == 1) {
        battery_power -= 1;
        battery_percent = (battery_power/2000)*100;
        mvprintw(16,34,"-- normal operation --");
    } else {
        battery_power += 1;
        battery_percent = (battery_power/750)*100;
        mvprintw(16,34,"--    recharging    --");
    }

    if (battery_percent < 10) {
        battery_normal = 0;
    }

    if ( (battery_normal==0) && (battery_percent > 99) ) {
        battery_normal = 1;
        battery_power = 2000;
    }

    mvprintw(15,34,"battery power: %.2f %%", battery_percent);

    // NOTE: Since the bottyworld is running every 10 ms, we should sleep
    //       the ui to give processing time back to the OS. It is debatable
    //       whether this is the right place to put this. It could also become
    //       an Elma feature, or it could go in the BottyWorld class, etc.
    //       The number 9999 should also be a parameter and not a constant.
    usleep(9999);

}