#include <iostream>

#include "p8g/p8g.hpp"

using namespace p8g;
using std::cout;

void support() {

    strokeWeight(10); // Sets the width of shapes' contour
    line(200, 900, 300, 900); // Base
    line(200, 900, 200, 200); // Connection to Top
    line(200, 200, 550, 200); // Top
    strokeWeight(5);
    line(550, 200, 550, 300); // Connection to Stickman

}

void stickman() {

    // When incorporating with the game, needs the variable with that stores the number of misses in order to draw the correct stickman state

    strokeWeight(5); // Reduce weight
    fill(0, 0, 0, 120);

    ellipse(550, 375, 150, 150); // Head
    line(550, 450, 550, 700); // Body
    line(550, 500, 400, 500); // Left Arm
    line(550, 500, 700, 500); // Right Arm
    line(550, 700, 500, 850); // Left Leg
    line(550, 700, 600, 850); // Right Leg

}

void p8g::draw() {

    background(251, 213, 214); // Red, Green, Blue, Opacity (optional)

    support();
    stickman();
   
}

void p8g::keyPressed() {

    // IDEA: Have a 'char' global variable that stores the last alphabetical character pressed
    cout << "Key " << keyCode << " was pressed!\n";
}
void p8g::keyReleased() {}
void p8g::mouseMoved() {}
void p8g::mousePressed() {}
void p8g::mouseReleased() {}
void p8g::mouseWheel(float delta) {}

// When run starts all functions declared above are "executed"
int main() {
    run(1920, 1080, "Hangman", true); // In case of my laptop, to fill the whole screen the arguments would have to be 2880 and 1800

}