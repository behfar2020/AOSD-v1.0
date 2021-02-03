/*
 *                                                                                                                                                                                                         
                                                                                                                                                                                                        
                                                                                                                                                                                                        
                                                                                                                           .,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.                  
                                                                                                                         (#############################################################,                
                                                                                                                         (#############################################################,                
                    ,(((((((((((/.                       ,((((                                                  *(((/    (####/,,,/########,,,,#####################(,,,*##############,                
                    /@@@@@@@@@@@@@@@*                    /@@@&                                                  (@@@&    (####*   ,#######(    #####################(    ##############,                
                    /@@@@       .@@@@.       ,***,       /@@@@  .***.            ***      *****,          ,***  (@@@&    (####*   ,#######(    #####################(   .##(///########,                
                    /@@@@       %@@@%    .@@@@@@@@@@&    /@@@@@@@@@@@@@    @@@@@@@@@# .@@@@@@@@@@@%    &@@@@@@@@@@@@&    (####*   ,#######(    ####.   (#####    ###(             #####,                
                    /@@@@@@@@@@@@@%.    ,@@@@    .@@@@.  /@@@@*    &@@@#   @@@@@*  ,  ,(%%     @@@@.  @@@@#    .@@@@&    (####*                ####.   (#####    ###(    /####(    ####,                
                    /@@@@     .,(@@@@%  &@@@@@@@@@@@@@(  /@@@&     %@@@%   @@@@/       .%@@@@@@@@@@. ,@@@@.     /@@@&    (####*   ,#######(    ####.   (#####    ###(   .######*   *###,                
                    /@@@@        *@@@@  %@@@(            /@@@&     %@@@%   @@@@*     .@@@@%    @@@@.  @@@@,     #@@@&    (####*   ,#######(    ####.   (####(    ###(    ######,   /###,                
                    /@@@@@@@@@@@@@@@@#   @@@@&, ,&@@@&   /@@@&     %@@@%   @@@@*     *@@@@/  /@@@@@.  /@@@@#. *@@@@@&    (####*   ,#######(    ####*    (##*     ###(     *##(    ,####,                
                    /@@@@@@@@@@@@@@*       &@@@@@@@&     /@@@&     %@@@%   @@@@*      .@@@@@@@//@@@%    (@@@@@@%,@@@&    (####*   ,#######(    #####(      .#.   ###(   *(      ,######,                
                                                                                                                         (#############################################################,                
                                                                                                                         (#############################################################,                
                                                                                                                          ############################################################(                 XD
                                                                                                                                                                                                        
                                         
 */

#include <Servo.h>
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

Servo servo;
int angle = 0; // value of "angle"

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
 
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
    
  // start servo at 0 degrees
  servo.attach(8);
  servo.write(angle);
  
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed

}
void loop() {
  
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10      );
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = (duration /2) / 29.1; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  
  Serial.print("Distance: ");
  Serial.println(distance);

  servo.write(0);
  
  if (distance <= 20){
    servo.write(90);
  }

    else {
      servo.write(angle);
    }
    
  delay(1000);
}
