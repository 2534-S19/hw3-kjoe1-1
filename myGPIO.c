/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"


// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
        GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P1, GPIO_PIN1);
        GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P1, GPIO_PIN4);
        GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P5, GPIO_PIN1);
        GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P3, GPIO_PIN5);

        GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
        GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0);
        GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN1);
        GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2);
        GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN6);
        GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN4);
        GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN6);


checkStatus_LaunchpadS1();// Launchpad S1

checkStatus_LaunchpadS2();// Launchpad S2

checkStatus_BoosterpackS1(); // Boosterpack S1

checkStatus_BoosterpackS2();// Boosterpack S2
turnOff_LaunchpadLED1();   // Launchpad LED1

turnOff_LaunchpadLED2Red(); // Launchpad LED2 Red

turnOff_LaunchpadLED2Green(); // Launchpad LED2 Green

turnOff_LaunchpadLED2Blue();// Launchpad LED2 Blue
turnOff_BoosterpackLEDRed();   // Boosterpack LED Red

 turnOff_BoosterpackLEDGreen(); // Boosterpack LED Green
 turnOff_BoosterpackLEDBlue();// Launchpad LED2 Blue


// Turn off all LEDs at the start.
}
void reset_LaunchLED(){
    turnOff_LaunchpadLED1();   // Launchpad LED1

    turnOff_LaunchpadLED2Red(); // Launchpad LED2 Red

    turnOff_LaunchpadLED2Green(); // Launchpad LED2 Green

    turnOff_LaunchpadLED2Blue();// Launchpad LED2 Blue
}
void reset_BoosterLED(){

    turnOff_BoosterpackLEDRed();   // Boosterpack LED Red

    turnOff_BoosterpackLEDGreen(); // Boosterpack LED Green
    turnOff_BoosterpackLEDBlue();// Launchpad LED2 Blue

}
// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
   return GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return GPIO_getInputPinValue(GPIO_PORT_P5, GPIO_PIN1);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN5);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN6);
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN4);
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN4);
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
}
