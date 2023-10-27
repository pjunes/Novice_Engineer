#include <iostream>
#include <wiringPi.h>
#include <time.h>
#include <string>

#define START_STOP  27
#define CW_CCW      17

// #define ENCODER_1   27
// #define ENCODER_2   22

#define BUTTON_1_IN   20
#define BUTTON_1_OUT  21

#define BUTTON_2_IN   19
#define BUTTON_2_OUT  26

#define PWM0          18

#define START_CMD       1
#define STOP_CMD        2
#define CW_CMD          3
#define CCW_CMD         4
#define PHYSICAL_CMD    5

#define EXIT_CMD        0

int start_motor();
int stop_motor();
int cw_motor();
int ccw_motor();

bool start_stop = true;
bool cw_ccw = true;

int main() {
    std::cout << "Hello World!!\n";

    if (wiringPiSetupGpio() < 0) {
        std::cout << "Unable to setup wiring Pi\n"; // 오류 발생 처리
        return 1;
    }
    std::cout << "Setup Wiring Pi\n";

    pwmSetMode(PWM_MODE_MS);
    std::cout << "Setup PWM Mode\n";

    // pinMode 설정

    pinMode(START_STOP, OUTPUT);
    pinMode(CW_CCW,     OUTPUT);

    // pinMode(ENCODER_1, INPUT);
    // pinMode(ENCODER_2, INPUT);

    pinMode(BUTTON_1_IN,    INPUT);
    pinMode(BUTTON_1_OUT,   OUTPUT);
    pinMode(BUTTON_2_IN,    INPUT);
    pinMode(BUTTON_2_OUT,   OUTPUT);

    pinMode(PWM0, PWM_OUTPUT);

    std::cout << "Setup Pin Mode\n";

    // setup PWM

    pwmSetRange(1024); // PWM 생성 범위를 설정 (기본값 : 1024)

    // 초기화

    digitalWrite(CW_CCW,        0);
    digitalWrite(START_STOP,    0);

    digitalWrite(BUTTON_1_OUT,   1);
    digitalWrite(BUTTON_2_OUT,   1);

    std::string welcome_msg = "1 : start\n2 : stop\n3 : cw\n4 : ccw\n5 : physical\n0 : exit\n";
    std::string error_msg = "unknown cmd\n";
    std::string start_msg = "START\n";
    std::string stop_msg = "STOP\n";
    std::string cw_msg = "CW\n";
    std::string ccw_msg = "CCW\n";
    std::string physical_msg = "PHYSICAL\n";

    std::string exit_msg = "EXIT\n";

    std::cout << "Initialized\n";

    std::cout << "PWM TEST\n";
    
    /*

    start_motor();

    delay(2000);
    pwmWrite(PWM0, 256);
    delay(2000);
    pwmWrite(PWM0, 512);
    delay(2000);
    pwmWrite(PWM0, 1024);
    delay(2000);
    pwmWrite(PWM0, 128);
    delay(2000);

    stop_motor();

    */


    

    int cmd = 1;
    
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

            case PHYSICAL_CMD:
                std::cout << physical_msg;
                while(1) {
                    if (digitalRead(BUTTON_1_IN) == 1) {
                        if (!start_stop) start_motor();
                        else stop_motor();
                    }
                    if (digitalRead(BUTTON_2_IN) == 1) {
                        if (!cw_ccw) cw_motor();
                        else ccw_motor();
                    }
                    delay(100);
                }
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
    start_stop = true;
    std::cout << "port BCM " << START_STOP << " HIGH\n";
    return 0;
}

int stop_motor() {
    digitalWrite(START_STOP, 0);
    start_stop = false;
    std::cout << "port BCM " << START_STOP << " LOW\n";
    return 0;
}

int cw_motor() {
    // if (cw_ccw) {
    //     std::cout << "already running cw\n";
    //     return 0;
    // }

    digitalWrite(CW_CCW, 0);
    cw_ccw = true;
    std::cout << "port BCM " << CW_CCW << " LOW\n";

    return 0;
}

int ccw_motor() {
    // if (!cw_ccw) {
    //     std::cout << "already running ccw\n";
    //     return 0;
    // }

    digitalWrite(CW_CCW, 1);
    cw_ccw = false;
    std::cout << "port BCM " << CW_CCW << " HIGH\n";

    return 0;
}

/*
cmake CMakeLists.txt
make
sudo ./bin/DMC_16_test 
*/