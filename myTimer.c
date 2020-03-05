/*
 * myTimer.c
 *
 *  Created on:
 *      Author:
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myTimer.h"
void initTimer(unsigned int timer, unsigned int preScaler, unsigned int count);
bool timerExpired(uint32_t timer);

// TODO: Write a function that can intialize a Timer with particular values for pre-scale and count.
// Aliases for the Timers and the preScaler arguments are defined in myTimer.h
void initTimer(unsigned int timer, unsigned int preScaler, unsigned int count)
{
    Timer32_initModule( timer, preScaler, TIMER32_32BIT, TIMER32_PERIODIC_MODE);
    Timer32_setCount(timer, count);
    Timer32_startTimer(timer, REPEAT);
//    if(timer == TIMER0)
//    {
//        preScaler = TIMER0_PRESCALER ;  // For the specified timer and pre-scale value, put the timer in 32-bit periodic mode.
//        Timer32_setCount(timer, count); // For the specified timer, pass the count value.
//        Timer32_startTimer(timer, REPEAT); // For the specified timer, configure the timer to repeat once it elapses.
//    }
//    else
//    {
//        preScaler = TIMER1_PRESCALER; // For the specified timer and pre-scale value, put the timer in 32-bit periodic mode.
//        Timer32_setCount(timer, count);  // For the specified timer, pass the count value.
//        Timer32_startTimer(timer, REPEAT); // For the specified timer, configure the timer to repeat once it elapses.
//    }


}

// TODO: Write a function that indicates whether Timer0 has expired.
// You have been given a such a function in the lecture slides.
bool timer0Expired()
{
    return timerExpired(TIMER0);
}

// TODO: Write a function that indicates whether Timer1 has expired.
// This is essentially a copy of the previous function, using a different timer.
// Since we only have two timers, later in the course we will create software timers that use a common time base.
bool timer1Expired()
{
   return timerExpired(TIMER1);
}


bool timerExpired(uint32_t timer)
{
   static unsigned int previousSnap = MAX_VALUE;
   unsigned int currentSnap;
   bool returnValue;

   currentSnap = Timer32_getValue(timer);
   returnValue = (currentSnap > previousSnap);
   previousSnap = currentSnap;
   return returnValue;
}

