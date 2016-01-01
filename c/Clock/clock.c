#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int HIGH_MODE = 1;
const int LOW_MODE = 0;

const int numOne = 0;
const int numTwo = 1;
const int numThree = 2;
const int numFour = 3;
const int numFive = 4;
const int numSix = 5;

const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 17;
const int pinE = 27;
const int pinF = 22;
const int pinG = 10;
const int pinDF = 9;

const int pinNumOne = 14;
const int pinNUmTwo = 15;
const int pinNumThree = 18;
const int pinNumFour = 23;
const int pinNumFive = 24;
const int pinNumSix = 25;

const int[] arrayNums = new int[]{pinNumOne, pinNumTwo, pinNumThree, pinNumFour, pinNumFive, pinNumSix};
const int[] arrayLeds = new int[]{
    pinA,
    pinB,
    pinC,
    pinD,
    pinE,
    pinF,
    pinG,
    pinDF
};

int hour, min, sec;
time_t currentTimeSec;
struct tm * currentTime;

int main(){
    if(wiringPiSetupGpio() == -1){
        printf("Setup wiringPi failed!");
        return 1;
    }
    printf("init all pin mode...");
    for(int i = 0; i < arrayNums.length; i ++){
        pinMode(arrayNums[i], OUTPUT);
    }
    for(int i = 0; i < arrayLeds.length; i ++){
        pinMode(arrayLeds[i], OUTPUT);
    }
    
    printf("start timer...");
    while(TRUE){
        currentTimeSec = time(NULL);
        currentTime = localtime(&currentTimeSec);
        hour = currentTime->tm_hour;
        min = currentTime->tm_min;
        sec = currentTime->tm_sec;
        
        lightNumber(numOne, hour/10);
        delay(2);
        lightNumber(numTwo, hour%10);
        delay(2);
        lightNumber(numThree, min/10);
        delay(2);
        lightNumber(numFour, min%10);
        delay(2);
        lightNumber(numFive, sec/10);
        delay(2);
        lightNumber(numSix, sec%10);
        delay(2);
    }
    return 0;
}

void lightNumber(int light, int number){
    for(int i = 0; i < arrayNums.length; i ++){
        digitalWrite(arrayNums[i], LOW_MODE);
    }
    digitalWrite(pinDF, HIGH_MODE);
    switch (number) {
        case 0:
            digitalWrite(pinA, LOW_MODE);
            digitalWrite(pinB, LOW_MODE);
            digitalWrite(pinC, LOW_MODE);
            digitalWrite(pinD, LOW_MODE);
            digitalWrite(pinE, LOW_MODE);
            digitalWrite(pinF, LOW_MODE);
            digitalWrite(pinG, HIGH_MODE);
            break;
        case 1:
            digitalWrite(pinA, HIGH_MODE);
            digitalWrite(pinB, LOW_MODE);
            digitalWrite(pinC, LOW_MODE);
            digitalWrite(pinD, HIGH_MODE);
            digitalWrite(pinE, HIGH_MODE);
            digitalWrite(pinF, HIGH_MODE);
            digitalWrite(pinG, HIGH_MODE);
            break;
        case 2:
            digitalWrite(pinA, LOW_MODE);
            digitalWrite(pinB, LOW_MODE);
            digitalWrite(pinC, HIGH_MODE);
            digitalWrite(pinD, LOW_MODE);
            digitalWrite(pinE, LOW_MODE);
            digitalWrite(pinF, HIGH_MODE);
            digitalWrite(pinG, LOW_MODE);
            break;
        case 3:
            digitalWrite(pinA, LOW_MODE);
            digitalWrite(pinB, LOW_MODE);
            digitalWrite(pinC, LOW_MODE);
            digitalWrite(pinD, LOW_MODE);
            digitalWrite(pinE, HIGH_MODE);
            digitalWrite(pinF, HIGH_MODE);
            digitalWrite(pinG, LOW_MODE);
            break;
        case 4:
            digitalWrite(pinA, HIGH_MODE);
            digitalWrite(pinB, LOW_MODE);
            digitalWrite(pinC, LOW_MODE);
            digitalWrite(pinD, HIGH_MODE);
            digitalWrite(pinE, HIGH_MODE);
            digitalWrite(pinF, LOW_MODE);
            digitalWrite(pinG, LOW_MODE);
            break;
        case 5:
            digitalWrite(pinA, LOW_MODE);
            digitalWrite(pinB, HIGH_MODE);
            digitalWrite(pinC, LOW_MODE);
            digitalWrite(pinD, LOW_MODE);
            digitalWrite(pinE, HIGH_MODE);
            digitalWrite(pinF, LOW_MODE);
            digitalWrite(pinG, LOW_MODE);
            break;
        case 6:
            digitalWrite(pinA, LOW_MODE);
            digitalWrite(pinB, HIGH_MODE);
            digitalWrite(pinC, LOW_MODE);
            digitalWrite(pinD, LOW_MODE);
            digitalWrite(pinE, LOW_MODE);
            digitalWrite(pinF, LOW_MODE);
            digitalWrite(pinG, LOW_MODE);
            break;
        case 7:
            digitalWrite(pinA, LOW_MODE);
            digitalWrite(pinB, LOW_MODE);
            digitalWrite(pinC, LOW_MODE);
            digitalWrite(pinD, HIGH_MODE);
            digitalWrite(pinE, HIGH_MODE);
            digitalWrite(pinF, HIGH_MODE);
            digitalWrite(pinG, HIGH_MODE);
            break;
        case 8:
            digitalWrite(pinA, LOW_MODE);
            digitalWrite(pinB, LOW_MODE);
            digitalWrite(pinC, LOW_MODE);
            digitalWrite(pinD, LOW_MODE);
            digitalWrite(pinE, LOW_MODE);
            digitalWrite(pinF, LOW_MODE);
            digitalWrite(pinG, LOW_MODE);
            break;
        case 9:
            digitalWrite(pinA, LOW_MODE);
            digitalWrite(pinB, LOW_MODE);
            digitalWrite(pinC, LOW_MODE);
            digitalWrite(pinD, LOW_MODE);
            digitalWrite(pinE, HIGH_MODE);
            digitalWrite(pinF, LOW_MODE);
            digitalWrite(pinG, LOW_MODE);
            break;
    }
    if (light == numFour) {
        digitalWrite(pinDF, LOW_MODE);
    }
    digitalWrite(arrayNums[light], HIGH_MODE);
    printf("lingt the %d light with value %d.", light + 1, number);
}
