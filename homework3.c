#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"
#include <stdio.h>
#include <stdlib.h>




int main() {
    // Count variables to control the LEDs.
    unsigned int count = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.


    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER0, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER1, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        initGPIO();
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c

      //  printf("going through the loop...\n:");
        if (timer0Expired() == true)
        {
           if (count<10)
           {
               count = (++count);
           }
           else {count =0;}
            printf("count is now: %d\n", count);


        }

        if (timer1Expired() == true)
        {
            int retval =checkStatus_LaunchpadS2();
            if (retval==0){
              if (count1 <7){
                  count1= ++count1;

              }
              else {count1 =0;}
             printf("count1 is now: %d\n", count1);


            while(checkStatus_LaunchpadS2() ==0)
            {
               // initGPIO();

              //  changeBoosterpackLED(count1);
                if (timer0Expired() == true)
                      {
                         if (count<10)
                         {
                             count = (++count);

                         }
                         else {count =0;}
                          printf("count is now: %d\n", count);

                        changeLaunchpadLED2(count);
                        int i=0;
                       for(i=0;i<10;i++);
                      }

            }
            }
        }

        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c


        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.



        // TODO: If a completed, debounced button press has occurred, increment count1.



    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    reset_LaunchLED();
    if (count ==0 ){

        turnOn_LaunchpadLED1();

    }
    else if (count ==1){
        turnOn_LaunchpadLED1();
        turnOn_LaunchpadLED2Red();
    }
    else if (count ==2){
        turnOn_LaunchpadLED2Red();

      }
    else if (count ==3){
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Blue();
      }
    else if (count ==4){
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
      }
    else if (count ==5){
        turnOn_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
      }
    else if (count ==6){
        turnOn_LaunchpadLED2Green();

      }
    else if (count ==7){
        turnOn_LaunchpadLED2Blue();

      }
    else if (count ==8){
        turnOn_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();

      }
    else if (count ==9){

        turnOn_LaunchpadLED2Red();

      }
    else if (count ==10){
        turnOn_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();

      }
    else if (count ==11){
        turnOn_LaunchpadLED2Blue();


      }

}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count1)
{
    reset_BoosterLED();
   if (count1 ==0 ){

       turnOn_BoosterpackLEDRed();

   }
   else if (count1 ==1){
  turnOn_BoosterpackLEDGreen();

   }
   else if (count1 ==2){
 turnOn_BoosterpackLEDBlue();
   }
   else if (count1 ==3)
   {
       turnOn_BoosterpackLEDRed();
       turnOn_BoosterpackLEDGreen();
   }
   else if (count1 ==4){
       turnOn_BoosterpackLEDGreen();
       turnOn_BoosterpackLEDBlue();
   }
   else if (count1 ==5){
       turnOn_BoosterpackLEDBlue();
       turnOn_BoosterpackLEDRed();
   }
   else if (count1 ==6){
         turnOn_BoosterpackLEDBlue();
         turnOn_BoosterpackLEDRed();
         turnOn_BoosterpackLEDGreen();
     }
   else if (count1 ==7){
       turnOn_BoosterpackLEDGreen();
         turnOn_BoosterpackLEDRed();
     }

   else if (count1 ==8){
         turnOn_BoosterpackLEDBlue();
         turnOn_BoosterpackLEDRed();
     }



}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int buttonhistory)
{
    bool pressed = false;


    return pressed;
}




