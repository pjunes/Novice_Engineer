#include<stdio.h>
#include<wiringPi.h>


int main() {
    printf("Hello World!\n");

    wiringPiSetup();

    pinMode(0, OUTPUT);

    while(1){
        digitalWrite(0, 0);
        delay(5000);
    }

    return 0;
}