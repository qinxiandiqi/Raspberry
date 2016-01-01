#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int HIGH = 1;
const int LOW = 0;

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

const int[6] arrayNums = new int[]{pinNumOne, pinNumTwo, pinNumThree, pinNumFour, pinNumFive, pinNumSix};
const int[8] arrayLeds = new int[]{
    pinA,
    pinB,
    pinC,
    pinD,
    pinE,
    pinF,
    pinG,
    pinDF
}

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
        digitalWrite(arrayNums[i], LOW);
    }
    digitalWrite(pinDF, HIGH);
    switch (number) {
        case 0:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, LOW);
            digitalWrite(pinF, LOW);
            digitalWrite(pinG, HIGH);
            break;
        case 1:
            digitalWrite(pinA, HIGH);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, HIGH);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, HIGH);
            digitalWrite(pinG, HIGH);
            break;
        case 2:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, HIGH);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, LOW);
            digitalWrite(pinF, HIGH);
            digitalWrite(pinG, LOW);
            break;
        case 3:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, HIGH);
            digitalWrite(pinG, LOW);
            break;
        case 4:
            digitalWrite(pinA, HIGH);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, HIGH);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, LOW);
            digitalWrite(pinG, LOW);
            break;
        case 5:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, HIGH);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, LOW);
            digitalWrite(pinG, LOW);
            break;
        case 6:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, HIGH);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, LOW);
            digitalWrite(pinF, LOW);
            digitalWrite(pinG, LOW);
            break;
        case 7:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, HIGH);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, HIGH);
            digitalWrite(pinG, HIGH);
            break;
        case 8:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, LOW);
            digitalWrite(pinF, LOW);
            digitalWrite(pinG, LOW);
            break;
        case 9:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, LOW);
            digitalWrite(pinG, LOW);
            break;
    }
    if (light == numFour) {
        digitalWrite(pinDF, LOW);
    }
    digitalWrite(arrayNums[light], HIGH);
    printf("lingt the %d light with value %d.", light + 1, number);
}
