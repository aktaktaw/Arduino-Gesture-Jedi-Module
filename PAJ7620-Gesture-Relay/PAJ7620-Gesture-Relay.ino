#include "paj7620.h"


uint8_t errorInit = 0;
uint8_t gesture = 0, error;

//pin relay input
int ledRed = 7;
int ledBlue = 8;


void setup(){
  Serial.begin(9600);

  pinMode(ledRed,OUTPUT);
  pinMode(ledBlue, OUTPUT);
    
  Serial.println("PAJ7620 Test Demo");
  
  errorInit = paj7620Init();
  if(errorInit){
    Serial.print("Init Error Code");
    Serial.println(errorInit);
  }
  else{
    Serial.println("Init Success");
  }

  
} 

void loop(){
  error = paj7620ReadReg(0x43, 1, &gesture);

  if(!error){
    switch(gesture){
      case GES_RIGHT_FLAG:
        Serial.println("RIGHT Gesture");
        digitalWrite(ledRed, HIGH);
        break;
     case GES_LEFT_FLAG:
        Serial.println("LEFT Gesture");
        digitalWrite(ledRed, LOW);
        break;
     case GES_UP_FLAG:
        Serial.println("UP Gesture");
        digitalWrite(ledBlue, HIGH);
        break;
     case GES_DOWN_FLAG:
        Serial.println("DOWN Gesture");
        digitalWrite(ledBlue, LOW);
        break;
     default:
        break;
    }
  }
  delay(100);
}
