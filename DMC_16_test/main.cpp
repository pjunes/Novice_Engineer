#include <iostream>
#include <wiringPi.h>
#include <time.h>
#include <string>

#define START_STOP  27
#define CW_CCW      17
// #define ENCODER_1   27
// #define ENCODER_2   22

#define START_CMD   1
#define STOP_CMD    2
#define CW_CMD      3
#define CCW_CMD     4

#define EXIT_CMD    0

int start_motor();
int stop_motor();
int cw_motor();
int ccw_motor();

bool cw = true;

int main() {
    std::cout << "Hello World!\n";

    if (wiringPiSetupGpio() < 0) {
        std::cout << "Unable to setup wiring Pi\n"; // 오류 발생 처리
        return 1;
    }

    // pinMode 설정

    pinMode(START_STOP, OUTPUT);
    pinMode(CW_CCW, OUTPUT);
    // pinMode(ENCODER_1, INPUT);
    // pinMode(ENCODER_2, INPUT);

    // 초기화

    digitalWrite(CW_CCW, 0);
    digitalWrite(START_STOP, 0);

    std::string welcome_msg = "1 : start\n2 : stop\n3 : cw\n4 : ccw\n0 : exit\n";
    std::string error_msg = "unknown cmd\n";
    std::string start_msg = "START\n";
    std::string stop_msg = "STOP\n";
    std::string cw_msg = "CW\n";
    std::string ccw_msg = "CCW\n";

    std::string exit_msg = "EXIT\n";

    int cmd = 0;

    while(cmd != 0) {
        std::cout << welcome_msg << "Enter CMD : ";
        std::cin >> cmd;

        switch(cmd) {
            case START_CMD:
                std::cout << start_msg;
                start_motor();
                break;
            
            case STOP_CMD:
                std::cout << stop_msg;
                stop_motor();
                break;

            case CW_CMD:
                std::cout << cw_msg;
                cw_motor();
                break;

            case CCW_CMD:
                std::cout << ccw_msg;
                ccw_motor();
                break;

            case EXIT_CMD:
                std::cout << stop_msg;
                stop_motor();
                std::cout << exit_msg;
                break;

            default:
                std::cout << error_msg;
                break;

        }

    }
    
    return 0;
}

int start_motor() {
    digitalWrite(START_STOP, 1);
    std::cout << "port BCM " << START_STOP << " HIGH\n";
    return 0;
}

int stop_motor() {
    digitalWrite(START_STOP, 0);
    std::cout << "port BCM " << START_STOP << " LOW\n";
    return 0;
}

int cw_motor() {
    if (cw) {
        std::cout << "already running cw\n";
        return 0;
    }

    digitalWrite(CW_CCW, 0);
    cw = true;
    std::cout << "port BCM " << CW_CCW << " LOW\n";

    return 0;
}

int ccw_motor() {
    if (!cw) {
        std::cout << "already running ccw\n";
        return 0;
    }

    digitalWrite(CW_CCW, 1);
    cw = false;
    std::cout << "port BCM " << CW_CCW << " HIGH\n";

    return 0;

    return 0;
}