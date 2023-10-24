#include <iostream>
#include <string>
#include <chrono>
#include "mbed.h"
#include "MorseH.h"

// main() runs in its own thread in the OS
int main(){
    string name("STEPAN");
    while (true) {
        playMorse(name);
        return 0;
    }
}