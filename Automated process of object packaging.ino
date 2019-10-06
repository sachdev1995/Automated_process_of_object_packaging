#include <Servo.h> 

#define piston1 4
#define piston2 5
#define piston3 6
#define piston4 7

#define vacuum 3

#define echoPin1 10
#define initPin1 9
int distance1 =0;

//Sonar 2
#define echoPin2 12
#define initPin2 8
int distance2 =0;

#define motor1_input1 A0
#define motor1_input2 A1

#define motor2_input1 A2
//#define motor2_input2 A3

Servo myservo;

int count =0;
int count2 =0;
void setup()
{
  
  myservo.attach(11);
  
pinMode(piston1,OUTPUT);
pinMode(piston2,OUTPUT);
pinMode(piston3,OUTPUT);
pinMode(piston4,OUTPUT);

pinMode(motor1_input1,OUTPUT);
pinMode(motor1_input2,OUTPUT);
pinMode(motor2_input1,OUTPUT);
//pinMode(motor2_input2,OUTPUT);


pinMode(vacuum,OUTPUT);

pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
 pinMode(initPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
   Serial.begin(9600);
  myservo.write(120);   
}


void loop()
{
   digitalWrite(piston1,LOW);   //bringing arm to normal position
   digitalWrite(piston2,LOW);
   digitalWrite(piston3,LOW);
   digitalWrite(vacuum,LOW);

               
               
  Serial.println("motor running");             
  digitalWrite(motor1_input1,HIGH);  //motor running
  digitalWrite(motor1_input2,LOW);
  
  distance1 = getDistance(initPin1, echoPin1);
  distance2 = getDistance(initPin2, echoPin2);



      if (((distance1>=1)&&(distance1<=6))&&((distance1>=1)&&(distance1<=6)))
           {
           delay(400);
              digitalWrite(motor1_input1,HIGH);
              digitalWrite(motor1_input2,HIGH);  //stopping motor
              Serial.println("motor stopped");
              delay(3000);

    myservo.write(120);              // tell servo to go to position in variable 'pos' 
    delay(1000);                       // waits 15ms for the servo to reach the position 
                               
    myservo.write(50);              // tell servo to go to position in variable 'pos' 
    delay(1000);  
      
    myservo.write(120); 
           digitalWrite(piston4,HIGH);
           delay(2000);
           digitalWrite(piston4,LOW);
           delay(1000);
              //Serial.println("box detected");

              //digitalWrite(motor1_input1,HIGH);
              //digitalWrite(motor1_input2,HIGH);  //stopping motor
              //Serial.println("motor stopped");
              //delay(1000);

           digitalWrite(piston4,HIGH);
           delay(4000);
           digitalWrite(piston4,LOW);
           delay(1000);

              Serial.println("initiating arm");
              int temp=count%2 ; //arm code start
              digitalWrite(piston3,HIGH);
              digitalWrite(piston2,HIGH);
              delay(2000);
              
             // digitalWrite(piston3,LOW);
             // delay(1000);
              digitalWrite(vacuum,HIGH);
              
                //digitalWrite(vacuum,HIGH);
              delay(3000);
              digitalWrite(piston2,LOW);
              delay(2000);
              digitalWrite(piston3,LOW);
              delay(2000);
              digitalWrite(piston1,HIGH);
              delay(2000);
              
              if(temp==1)
                  {
                      digitalWrite(piston2,HIGH);
                      digitalWrite(piston3,HIGH);
                  }
              delay(2000);
              digitalWrite(vacuum,LOW);
              delay(3000);
            
              if(temp==1)
                  {
                      digitalWrite(piston2,LOW);
                      digitalWrite(piston3,LOW);
                  }
                  
              digitalWrite(piston1,LOW);
              delay(2000);

              count++;
              count2++;
              Serial.println(count);
              Serial.println(count2);
              
       
               

           
      Serial.println("arm code end");

if((count2==2)||(count2==6)||(count2==10)||(count2==14))
  {
    digitalWrite(motor1_input1,HIGH);
    digitalWrite(motor1_input2,HIGH);  //stopping motor
              Serial.println("motor stopped");
    
    Serial.println("2nd conveyor running");
    digitalWrite(motor2_input1,HIGH);
   // digitalWrite(motor2_input2,LOW);
    delay(400);
Serial.println("2nd conveyor stopped");
    digitalWrite(motor2_input1,LOW);
   // digitalWrite(motor2_input2,HIGH);
    delay(2000);
   }
   else if((count2==4)||(count2==8)||(count2==12)||(count2==16))
   {

    digitalWrite(motor1_input1,HIGH);
    digitalWrite(motor1_input2,HIGH);  //stopping motor
     Serial.println("motor stopped");
              
    Serial.println("2nd conveyor running with high delay");
    digitalWrite(motor2_input1,HIGH);
   // digitalWrite(motor2_input2,LOW);
    delay(1000);
Serial.println("2nd conveyor stopped delay");
    digitalWrite(motor2_input1,LOW);
   // digitalWrite(motor2_input2,HIGH);
    delay(2000);
    

}

        digitalWrite(motor1_input1,HIGH);
       digitalWrite(motor1_input2,LOW);
       delay(1000);
}
else
{
Serial.println("box  not detected..");
}

/*  if(count2==2)
  {
    Serial.println("2nd conveyor running");
    digitalWrite(motor2_input1,HIGH);
    digitalWrite(motor2_input2,LOW);
    delay(600);
Serial.println("2nd conveyor stopped");
    digitalWrite(motor2_input1,HIGH);
    digitalWrite(motor2_input2,HIGH);
    delay(1000);
   }
  */
}

/* Added for the getting distance */
int getDistance (int initPin, int echoPin)
{
 Serial.println("Distance \n");
 digitalWrite(initPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(initPin, LOW); 
 unsigned long pulseTime = pulseIn(echoPin, HIGH); 
 int distance = pulseTime/58;
 return distance;
 
}
