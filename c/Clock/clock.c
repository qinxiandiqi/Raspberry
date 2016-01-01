#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define HIGH_MODE 1
#define LOW_MODE 0

#define LIGHT_NUM_ONE 0
#define LIGHT_NUM_TWO 1
#define LIGHT_NUM_THREE 2
#define LIGHT_NUM_FOUR 3
#define LIGHT_NUM_FIVE 4
#define LIGHT_NUM_SIX 5

#define PIN_A 2
#define PIN_B 3
#define PIN_C 4
#define PIN_D 17
#define PIN_E 27
#define PIN_F 22
#define PIN_G 10
#define PIN_DF 9

#define PIN_NUM_ONE 14
#define PIN_NUM_TWO 15
#define PIN_NUM_THREE 18
#define PIN_NUM_FOUR 23
#define PIN_NUM_FIVE 24
#define PIN_NUM_SIX 25

#define TOTAL_COUNT_OF_NUMS 6
#define TOTAL_PIN_COUNT_OF_LED 8

const int arrayNums[TOTAL_COUNT_OF_NUMS] = {PIN_NUM_ONE, PIN_NUM_TWO, PIN_NUM_THREE, PIN_NUM_FOUR, PIN_NUM_FIVE, PIN_NUM_SIX};
const int arrayLeds[TOTAL_PIN_COUNT_OF_LED] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_DF};

int hour, min, sec;
time_t currentTimeSec;
struct tm * currentTime;
int position = 0;

void lightNumber(int light, int number){
    for(position = 0; position < TOTAL_COUNT_OF_NUMS; position ++){
        digitalWrite(arrayNums[position], LOW_MODE);
    }
    digitalWrite(PIN_DF, HIGH_MODE);
    switch (number) {
        case 0:
            digitalWrite(PIN_A, LOW_MODE);
            digitalWrite(PIN_B, LOW_MODE);
            digitalWrite(PIN_C, LOW_MODE);
            digitalWrite(PIN_D, LOW_MODE);
            digitalWrite(PIN_E, LOW_MODE);
            digitalWrite(PIN_F, LOW_MODE);
            digitalWrite(PIN_G, HIGH_MODE);
            break;
        case 1:
            digitalWrite(PIN_A, HIGH_MODE);
            digitalWrite(PIN_B, LOW_MODE);
            digitalWrite(PIN_C, LOW_MODE);
            digitalWrite(PIN_D, HIGH_MODE);
            digitalWrite(PIN_E, HIGH_MODE);
            digitalWrite(PIN_F, HIGH_MODE);
            digitalWrite(PIN_G, HIGH_MODE);
            break;
        case 2:
            digitalWrite(PIN_A, LOW_MODE);
            digitalWrite(PIN_B, LOW_MODE);
            digitalWrite(PIN_C, HIGH_MODE);
            digitalWrite(PIN_D, LOW_MODE);
            digitalWrite(PIN_E, LOW_MODE);
            digitalWrite(PIN_F, HIGH_MODE);
            digitalWrite(PIN_G, LOW_MODE);
            break;
        case 3:
            digitalWrite(PIN_A, LOW_MODE);
            digitalWrite(PIN_B, LOW_MODE);
            digitalWrite(PIN_C, LOW_MODE);
            digitalWrite(PIN_D, LOW_MODE);
            digitalWrite(PIN_E, HIGH_MODE);
            digitalWrite(PIN_F, HIGH_MODE);
            digitalWrite(PIN_G, LOW_MODE);
            break;
        case 4:
            digitalWrite(PIN_A, HIGH_MODE);
            digitalWrite(PIN_B, LOW_MODE);
            digitalWrite(PIN_C, LOW_MODE);
            digitalWrite(PIN_D, HIGH_MODE);
            digitalWrite(PIN_E, HIGH_MODE);
            digitalWrite(PIN_F, LOW_MODE);
            digitalWrite(PIN_G, LOW_MODE);
            break;
        case 5:
            digitalWrite(PIN_A, LOW_MODE);
            digitalWrite(PIN_B, HIGH_MODE);
            digitalWrite(PIN_C, LOW_MODE);
            digitalWrite(PIN_D, LOW_MODE);
            digitalWrite(PIN_E, HIGH_MODE);
            digitalWrite(PIN_F, LOW_MODE);
            digitalWrite(PIN_G, LOW_MODE);
            break;
        case 6:
            digitalWrite(PIN_A, LOW_MODE);
            digitalWrite(PIN_B, HIGH_MODE);
            digitalWrite(PIN_C, LOW_MODE);
            digitalWrite(PIN_D, LOW_MODE);
            digitalWrite(PIN_E, LOW_MODE);
            digitalWrite(PIN_F, LOW_MODE);
            digitalWrite(PIN_G, LOW_MODE);
            break;
        case 7:
            digitalWrite(PIN_A, LOW_MODE);
            digitalWrite(PIN_B, LOW_MODE);
            digitalWrite(PIN_C, LOW_MODE);
            digitalWrite(PIN_D, HIGH_MODE);
            digitalWrite(PIN_E, HIGH_MODE);
            digitalWrite(PIN_F, HIGH_MODE);
            digitalWrite(PIN_G, HIGH_MODE);
            break;
        case 8:
            digitalWrite(PIN_A, LOW_MODE);
            digitalWrite(PIN_B, LOW_MODE);
            digitalWrite(PIN_C, LOW_MODE);
            digitalWrite(PIN_D, LOW_MODE);
            digitalWrite(PIN_E, LOW_MODE);
            digitalWrite(PIN_F, LOW_MODE);
            digitalWrite(PIN_G, LOW_MODE);
            break;
        case 9:
            digitalWrite(PIN_A, LOW_MODE);
            digitalWrite(PIN_B, LOW_MODE);
            digitalWrite(PIN_C, LOW_MODE);
            digitalWrite(PIN_D, LOW_MODE);
            digitalWrite(PIN_E, HIGH_MODE);
            digitalWrite(PIN_F, LOW_MODE);
            digitalWrite(PIN_G, LOW_MODE);
            break;
    }
    if (light == LIGHT_NUM_FOUR) {
        digitalWrite(PIN_DF, LOW_MODE);
    }
    digitalWrite(arrayNums[light], HIGH_MODE);
}

int main(){
    if(wiringPiSetupGpio() == -1){
        printf("Setup wiringPi failed!\n");
        return 1;
    }
    printf("init all pin mode...\n");
    for(position = 0; position < TOTAL_COUNT_OF_NUMS; position ++){
        pinMode(arrayNums[position], OUTPUT);
    }
    for(position = 0; position < TOTAL_PIN_COUNT_OF_LED; position ++){
        pinMode(arrayLeds[position], OUTPUT);
    }

    printf("start timer...\n");
    while(TRUE){
        currentTimeSec = time(NULL);
        currentTime = localtime(&currentTimeSec);
        hour = currentTime->tm_hour;
        min = currentTime->tm_min;
        sec = currentTime->tm_sec;

        lightNumber(LIGHT_NUM_ONE, hour/10);
        delay(2);
        lightNumber(LIGHT_NUM_TWO, hour%10);
        delay(2);
        lightNumber(LIGHT_NUM_THREE, min/10);
        delay(2);
        lightNumber(LIGHT_NUM_FOUR, min%10);
        delay(2);
        lightNumber(LIGHT_NUM_FIVE, sec/10);
        delay(2);
        lightNumber(LIGHT_NUM_SIX, sec%10);
        delay(2);
    }
    return 0;
}


