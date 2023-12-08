
//switch pin = inputs
// pins connected to LEDs are outputs

int switchState = 0;

/*
delay()
digitalRead(pin);
digitalWrite(pin, value);
pinMode(pin, mode);
*/

void setup(){ //runs once. At start up --> to configure pin modes (inputs / outputs)
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(2, INPUT);
}

void loop(){
    switchState = digitalRead(2);

/*
The loop() runs continuously after the setup() has
completed. The loop() is where you’ll check for voltage on the
inputs, and turn outputs on and off. To check the voltage level
on a digital input, you use the function digitalRead() that
checks the chosen pin for voltage. To know what pin to check,
digitalRead() expects an argument.
*/

    /*    If there’s voltage on the pin when digitalRead() is called, the
switchState variable will get the value HIGH (or 1). If there is
no voltage on the pin, switchState will get the value LOW (or 0).
*/

    /*
    digitalWrite() is the command that allows you to send 5V
or 0V to an output pin.

-> digitalWrite() takes two arguments:
what pin to control, and what value to set that pin, HIGH or LOW.
    */

   /*
   The delay() function lets you stop the Arduino
from executing anything for a period of time. delay() takes an
argument that determines the number of milliseconds before it
executes the next set of code. There are 1000 milliseconds in one
second. delay(250) will pause for a quarter second.
   */

  if(switchState == LOW){
    //button not pressed
    digitalWrite(3, HIGH); //red
    digitalWrite(4, LOW);  //blue
    digitalWrite(5, LOW);  //blue 
  }else{
    //button pressed

    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(250); //250 miliseconds delay

    //toggle the LEDs

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(250); //if you dont wait it will go once again to the beginning of the loop instantly and the effect wont be seen

  }


}
