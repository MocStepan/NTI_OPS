#include "MorseH.h"

DigitalOut led(LED1);map<char, string> morseMap = {
        {'A', ".-"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."},
};

void blink(char symb) {
    switch (symb) {
        case '.':
            led = 1;
            ThisThread::sleep_for(DOT_LENGTH);
            led = 0;
            ThisThread::sleep_for(SPACE_LENGTH);
            break;
        case '-':
            led = 1;
            ThisThread::sleep_for(DASH_LENGTH);
            led = 0;
            ThisThread::sleep_for(SPACE_LENGTH);
            break;
        default:
            return;
    } 
}

void playMorse(String name) {
    for (char morse : name) {
            for (char character : morseMap[morse]){
                blink(character);
            }
     }
}