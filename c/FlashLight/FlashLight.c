#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int led_pin = 24;

int main(){
	if(wiringPiSetupGpio() == -1){
		printf("Setup wiringPi failed!");
		return 1;
	}
	printf("linker_led pin:GPIO%d (wiringPi pin)\n", led_pin);
	pinMode(led_pin, OUTPUT);
	
	int count = 0;
	while(count < 50){
		digitalWrite(led_pin, 1);
		delay(200);
		digitalWrite(led_pin, 0);
		delay(200);
		count++;
	}
	return 0;
}
