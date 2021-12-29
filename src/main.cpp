/* mbed Microcontroller Library
 * Copyright (c) 2021 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 1000ms
DigitalOut ledInfo(P0_5);
DigitalOut ledLock(P0_6);
DigitalOut ledUnlock(P0_7);

int main()
{

    while (true)
    {   
      ledUnlock = !ledUnlock;
      ledLock = !ledLock;
      ledInfo = !ledInfo;
      ThisThread::sleep_for(WAIT_TIME_MS);
        // ledInfo.write(0);
        // ledLock.write(0);
        // ledUnlock.write(0);

        
        // ThisThread::sleep_for(WAIT_TIME_MS);
        // ledInfo.write(1);
        // ThisThread::sleep_for(WAIT_TIME_MS);
    }
}