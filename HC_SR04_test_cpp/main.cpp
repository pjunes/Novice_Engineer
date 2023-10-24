#include <iostream>
#include <string>
#include <wiringPi.h>
#include <time.h>

using namespace std;

#define TRIG 23
#define ECHO 24
#define LED 17

int cmd = 0;

int LED_on();
int LED_off();
int print_dist();

int main() {
    printf("Hello World!\n");

    // wiringPiSetupGpio(); //BCM핀 사용
    // wiringPiSetup(); //WiringPi 자체 번호 사용

    if (wiringPiSetupGpio() < 0) {
        printf("Unable to setup wiring Pi\n"); // 오류 발생 처리
        return 1;
    }

    // pinMode 설정

    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(LED, OUTPUT);

    // 초기화

    digitalWrite(LED, 0);
    digitalWrite(TRIG, 0);

    //

    string welcome = "0 : 측정\n1 : 5회 측정\n2 : exit\n";
    string error_msg = "unknown cmd : \n";

    cout << welcome;

    while(1){
        // scanf("%d", &cmd);
        cin >> cmd;
        // printf("cmd : %d\n", cmd);
        cout << "cmd : " << cmd << '\n';

        if (cmd == 0) {
            print_dist();
        }
        else if (cmd == 1) {
            print_dist(); delay(500);
            print_dist(); delay(500);
            print_dist(); delay(500);
            print_dist(); delay(500);
            print_dist();
        }
        else if (cmd == 2) {
            break;
        }
        else {
            cout << error_msg << cmd;
        }

        delay(1000);
    }

    return 0;
}

int LED_on() {
    digitalWrite(LED, 1);

    return 0;
}

int LED_off() {
    digitalWrite(LED, 0);
    
    return 0;
}

int print_dist() {
    int start, stop;
    float dist;

    // HR-SR04 작동 신호

    digitalWrite(TRIG, 1);
    // delay(0.01); 
    delayMicroseconds(10); // HR-SR04에 10us 동안 TRIG 신호를 보냄
    digitalWrite(TRIG, 0);

    // 신호를 받은 HR-SR04가 거리 측정용 초음파를 8회 내보낸 직후 ECHO가 HIGH로 변함

    // 초음파를 8회 내보내고 ECHO가 HIGH가 될때까지 대기
    while (digitalRead(ECHO) == 0) {}
    start = micros();

    // 측정 종료후 ECHO가 LOW가 될때까지 대기
    while (digitalRead(ECHO) == 1) {}
    stop = micros();

    dist = float(stop - start) / 58.8235;

    cout << "Distance : " << dist << "cm\n";

    return 0;
}

/*
cmake CMakeLists.txt 
make
./bin/HC_SR04_test
*/