#include "mbed.h"

Timer t;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);


// main() runs in its own thread in the OS
int main() {
    int tCur;
    int tBase;

    t.start();
    tBase = t.read();

    while(true)
    {
        tCur = t.read();

        if(1 == (tCur - tBase))
        {
            led1 = !led1;
        }
        else if(2 == (tCur - tBase))
        {
            led2 = !led2;
        }
        else if(3 == (tCur - tBase))
        {
            led3 = !led3;
        }
        else if(4 == (tCur - tBase))
        {
            led4 = !led4;
            tBase = tCur;
        }

        wait(0.5);
    }
}

