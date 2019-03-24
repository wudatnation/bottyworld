# bottyworld
_bottyworld_ is a 2D simulation of robot named "botty" that includes an intruder and a recharging battery. The creator is [David Wu](https://github.com/wudatnation), student in [ECEP520 (a.k.a. ECE590) - Software Engineering for Embedded Applications)](https://github.com/klavins/ECEP520), for which the professor is [Eric Klavins](https://github.com/klavins/).  This program was David's final project for this course.

NOTE:  Be sure that your computer's sound is operational, and that the volume is turned up to a medium volume.

Execution
---
To run _bottyworld_, type

    bin/bottyworld

Operation
---
When the _bottyworld_ environment appears, botty is represented by "b".  As he moves rather quickly in random directions throughout his world, his battery power dissipates.

You can influence the environment of _bottyworld_ via these keys:
- **i**: Introduce Intruder
  * The Intruder appears, represented by "I".  When this happens, botty makes a noise to indicate that he is indeed aware of the Intruder.
  * If botty moves to within the proximity of the Intruder, botty will turn into an "E" and purposely evade the Intruder.
- **r**: Reset
  * If you reset while botty is in an evasive "E" mode, botty will turn back into "b", but botty will make a noise indicating that he knows the intruder is still there.
  * If you reset while botty is in his regular "b" mode, the Intruder will disappear!
  * NOTE:  Resetting does NOT affect the battery's power and recharging operation.
- **q**: Quit

Architecture
---
This project was intended to be an extension of the robot finite state machine, introduced to our class in Week 7 homework.  The elma_project file structure, provided by Prof. Klavins, was used as the baseline for the project. The latest "elma:latest" docker container for compiling.

Using ncurses for the first time, I spent a lot of time learning how this application works, and I also spent a few days learning how the base elma_project handled states and transitions.  A considerable amount of time and effort was spent figuring out how to convert the Homework 7 representation of the FSM, and convert it into the elma_project-style structure.

Results
---
Part of the challenge of this project was the intepretation of the robot FSM, and how it can be represented in a user interface.  I was able to get the Wander, Make Noise, and Evade states operating correctly, as well as the transitions between each.

I diverged from the original FSM to create a method of battery operation that was slightly more efficient (and aesthetically pleasing) than what I would have had to implement using the original structure.

I found that I worked best when I focused on getting a particular feature to work, as opposed to working on multiple integrated features at once.  I made sure to save, for configuration management, the various successful stages of coding.

Acknowledgements
---
No one helped me with this project.

References
---
I used the following websites for reference:
* [cplusplus.com](http://clusplus.com)
* [NCURSES Programming HOWTO](http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/)

________________________________________

# Historical Sections from Week 8 & 9 Homework

## Motivation
ECE590 has been a challenging but also very rewarding course, and I (David Wu) hope to showcase what I have learned these past 10 weeks in this final project.  For whatever reason, the idea of moving the FSM robot (part of homework from Week 7) into a 2D environment is the project option that caught my attention.

## Disclaimer
Please take note that the goals and other details listed below are subject to change/evolve as the project matures.

## Goals
My goals for _bottyworld_ are as follows:
* Successfully simulate Botty in a 2D environment, in which Botty wanders in random directions per second.
* Include an intruder that Botty will respond to.
* Include a recharge station that will bring Botty back up to full power.
* Allow an external operator to reset the environment.
* Export visual data per second.

## Projected Resources
I project that I will use the following resources:
* Elma
* robot FSM code determined in Week 7 homework
* StateMachine class (C++)
* chrono sub-namespace
* [Google.com](http://google.com), to search for solutions to coding problems as they arise
* Input from other students - not to "copy" ideas but to gain some insight in terms of approach, as they also work on their final projects.

## Homework 9 / Answer to Question 3
This past week, I have been brainstorming on how I will approach the 2-dimensional space that Botty will wander in, as well as reviewing the elma_project files and structure.

I project that I will be creating a 10 x 10 grid that looks similar to the following:

=  =  =  =  =  =  =  =  =  =

=  =  =  =  =  =  =  =  =  =

=  B  =  =  =  =  =  =  =  =

=  =  =  =  =  =  =  =  =  =

=  =  =  =  =  =  =  =  =  =

=  =  =  =  =  =  =  =  =  =

=  =  =  =  =  =  I  =  =  =

=  =  =  =  =  =  =  =  =  =

=  =  =  =  =  =  =  =  =  =

=  =  =  =  =  =  =  =  =  ^

Here is an explanation of the characters in the grid.  Note that these might be replaced by other characters depending on the capability of ncurses:
* **B** of course is Botty himself.  Botty will start at the upper-right corner (0,0) and then will wander through the grid in a random direction each second.
* **I** is the intruder.  When Botty gets close to the introder, he will go into the "evade" state.
* **^** is the recharge station.  When Botty gets close to losing battery power, he will move towards the recharge station to get re-energized.  Also, if Botty wanders into the recharge station, it will recharge.  I still haven't decided if Botty will keep on "going and going", or if he will die if it doesn't reach the recharge station in time.

My _updated_ milestones for this project are as follows:
* Compile elma_project (base template for bottyworld structure).  _Complete_
* Study ncurses. _In Progress_ (ECD: Mon., 3/18)
* Set up the 2D grid. (ECD: Tue., 3/19)
* Enable Botty to wander in random directions per second. (ECD: Tue., 3/19)
* Place intruder and recharge station in environment. (ECD: Tue., 3/19)
* Complete 2D graphical representation/export of data per second.  (ECD: Wed., 3/20)
* Successfully implement all states of FSM. (ECD: Wed., 3/20)
* Complete API documentation.  (ECD: Thurs., 3/21)
* Complete/submit final project. (ECD: Fri., 3/22)

## Homework 9 / Answer to Question 4
I also started learning how ncurses works, and also have been studying the way that elma_project works.  I can get the base elma_project to compile properly in the latest docker container made available by Prof. Klavins.  (At the time of this writing, the code in the above structure here compiles fine.)

At this point, I am still figuring out how to "convert" the given stopwatch example in elma_project to become the template for bottyworld.
