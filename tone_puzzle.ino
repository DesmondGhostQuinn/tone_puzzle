
#define activated LOW
#include<NewTone.h>
//tone tone1;      
const int buttonPin1 = 3;   // the number of the pushbutton pin for pushbuttons 
const int buttonPin2 = 4; 
const int buttonPin3 = 5; 
const int buttonPin4 = 6;
const int ledPin =  13;     //led pin
const int buzzpin = 11;     //piezo buzzer pin
int c=0;                    //count variable
char p;                     //argument for the switch statement 
int no_of_notes=4;
int p1=0;                   //variables to check sequence
int p2=0;
int p3=0;
int p4=0;  
int k1=0;                   //variables to check sequence
int k2=0;
int k3=0;
int k4=0;    
                           // variable for reading the pushbutton status
int buttonState1 = 0;
int buttonState2= 0;
int buttonState3 = 0;
int buttonState4 = 0;

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  digitalWrite(buttonPin1, HIGH);
  digitalWrite(buttonPin2, HIGH);
  digitalWrite(buttonPin3, HIGH);
  digitalWrite(buttonPin4, HIGH); 
  //tone1.begin(11)
  Serial.begin(9600);    
}

void loop(){
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  // check if the pushbutton is pressed. if it is, the appropriate switch parameter is set
 if (buttonState1 == activated) {        
    p=1;  
  } 
  if (buttonState2 == activated) {        
    p=2;  
  } 
  if (buttonState3 == activated) {        
    p=3;  
  } 
  if (buttonState4 == activated) {        
    p=4;  
  } 
  switch (p) {
      case 1:if(p1==0){
                    NewTone(11,262,10);
                      k1=1;
                      //p1=1;
                     c=1;
                     Serial.print('a');
                      }
             else{
                    NewTone(11,262,10);
                    // Reset();
                    c=0;
                    p1=0;
                    p2=0;
                    p3=0;
                    p4=0;
                    Serial.print('b');
                    //NewTone(11,1000,4000);
                  }
                  break;
                   
      case 2: if(p2==0 && k1==1){
                  NewTone(11,3729,10);
                  k2=1;
                  c=2;
                }
                else{
                    NewTone(11,3729,10);
                     //Reset();
                     c=0;
                     p1=0;
                     p2=0;
                     p3=0;
                     p4=0;
                     //NewTone(11,1000,4000);
                 }
                  break;
      case 3:if(p3==0 && k1==1 && k2==1){
              NewTone(11,1567,10);
               k3=1;
               c=3;
                }
              else{
                 NewTone(11,1567,10);
                //Reset();
                  c=0;
                   p1=0;
                 p2=0;
                  p3=0;
                   p4=0;
               // NewTone(11,1000,4000);
              }
              break;
        case 4:if(p4==0 && k1==1 && k2==1 && k3==1){
                NewTone(11,1318,10);
                 k4=1;
                 c=4;
                }
                else{
                 NewTone(11,1318,10);
                  c=0;
                  p1=0;
                   p2=0;
                  p3=0;
                   p4=0;
                  //Reset();
                  // NewTone(11,1000,4000);
                 }
                 break;
      default: break;
  }
 // Serial.print(c);
  if (k1==1 && k2==1 && k3==1 && k4==1) {         
    digitalWrite(ledPin, HIGH);// turn LED on
    for (int i=50;i<2000;i++){
      NewTone(11,i,10);
    }
  } 
  else {
    digitalWrite(ledPin, LOW);        // turn LED off
  }
  delay(20);
}



