#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define HIGH_MODE 1
#define LOW_MODE 0

#define numOne 0
#define numTwo 1
#define numThree 2
#define numFour 3
#define numFive 4
#define numSix 5

#define pinA 2
#define pinB 3
#define pinC 4
#define pinD 17
#define pinE 27
#define pinF 22
#define pinG 10
#define pinDF 9

#define pinNumOne 14
#define pinNumTwo 15
#define pinNumThree 18
#define pinNumFour 23
#define pinNumFive 24
#define pinNumSix 25

#define arrayNumCount 6
#define arrayLedCount 8

const int arrayNums[arrayNumCount] = {pinNumOne, pinNumTwo, pinNumThree, pinNumFour, pinNumFive, pinNumSix};
const int arrayLeds[arrayLedCount] = {pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDF};

int hour, min, sec;
time_t currentTimeSec;
struct tm * currentTime;
int position = 0;

void lightNumber(int light, int number){
    for(position = 0; position < arrayNumCount; position ++){
        digitalWrite(arrayNums[position], LOW_MODE);
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
    printf("lingt the %d light with value %d.\n", light + 1, number);
}

int main(){
    if(wiringPiSetupGpio() == -1){
        printf("Setup wiringPi failed!\n");
        return 1;
    }
    printf("init all pin mode...\n");
    for(position = 0; position < arrayNumCount; position ++){
        pinMode(arrayNums[position], OUTPUT);
    }
    for(position = 0; position < arrayLedCount; position ++){
        pinMode(arrayLeds[position], OUTPUT);
    }

    printf("start timer...\n");
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


