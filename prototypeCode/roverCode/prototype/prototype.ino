#include "Arduino.h"
#include "config.h"
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <Servo.h>
#define DELAY 100
Servo frontRight;
Servo frontLeft;
Servo backRight;
Servo backLeft;
void motorControl(int, int, int, int);

// GLOBAL VARIABLES //


void setup()
{
    initializeWirelessCommunication();
}

void loop()
{
    getPacket();
    parsePacketData();
    calculateMotorSpeeds();
    writeToMotors();
    while(true) {
        break;
    }
}

void motorControl(int frontRightVal, int frontLeftVal, int backRightVal, int backLeftVal)
{
    frontRight.writeMicroseconds(map(frontRightVal, -100, 100, 1000, 2000));
    frontLeft.writeMicroseconds(map(frontLeftVal, -100, 100, 1000, 2000));
    backRight.writeMicroseconds(map(backRightVal, -100, 100, 1000, 2000));
    backLeft.writeMicroseconds(map(backLeftVal, -100, 100, 1000, 2000));
    delay(DELAY+1);
}


