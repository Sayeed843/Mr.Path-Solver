#include <LiquidCrystal.h>

#define RMF A1
#define RMB A0

#define LMF A2
#define LMB A3


// IR sensor declear
#define RS 9
#define LS 10

#define MRS 8
#define MLS 6


// LCD Monitor
#define resetPin 12
#define enablePin 11

#define data4 5
#define data5 4
#define data6 3
#define data7 2

LiquidCrystal lcd(resetPin,enablePin, data4, data5,data6,data7);


int rightSensor;
int leftSensor;
int middleRightSensor;
int middleLeftSensor;

void mrPathSloverForward();
void mrPathSolverBackward();
void mrPathSolverTurnRight();
void mrPathSolverTurnLeft();
void mrPathSolverStop();

//char str[2],i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(RMF,OUTPUT);
  pinMode(RMB,OUTPUT);
  pinMode(LMF,OUTPUT);
  pinMode(LMB,OUTPUT);

  pinMode(RS,INPUT);
  pinMode(LS,INPUT);
  pinMode(MRS,INPUT);
  pinMode(MLS,INPUT);
  lcd.print("Mr.Path Solver...");
//  String comment = "Ready For Racing...";
  lcd.setCursor(0,1);
  lcd.print("Ready For Racing...");

}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  rightSensor = digitalRead(RS);
  leftSensor = digitalRead(LS);
  middleRightSensor = digitalRead(MRS);
  middleLeftSensor = digitalRead(MLS);

  Serial.print("RS:");
  Serial.println(rightSensor);

  Serial.print("LS:");
  Serial.println(leftSensor);

  Serial.print("MRS:");
  Serial.println(middleRightSensor);

  Serial.print("MLS:");
  Serial.println(middleLeftSensor);

  if((middleRightSensor == 1 and middleLeftSensor == 1) and rightSensor == 1)
  {
    mrPathSolverTurnRight();
    Serial.println("Mr.Path Solver is turning Right...");
    lcd.setCursor("Turn Right.",1);
  }
  else if((middleRightSensor == 1 and middleLeftSensor == 1) and leftSensor == 1)
  {
    mrPathSolverTurnLeft();
    Serial.println("Mr.Path Solver is turning Left...");
    lcd.setCursor("Turn Left.",1);
  }
  else if(middleRightSensor == 1 and middleLeftSensor == 1)
  {
    mrPathSolverForward();
    Serial.println("Mr.Path Solver is Forwarding...");
    lcd.setCursor("Forward",1);
  }
  else if((middleRightSensor == 0 or middleLeftSensor == 1) and rightSensor==0)
  {
    mrPathSolverTurnLeft();
    Serial.println("Mr Path Solver is Facing Trouble in Right side!!!");
    lcd.setCursor("trouble!!!",1); 
  }
  else if((middleRightSensor == 1 or middleLeftSensor == 0) and leftSensor==0)
  {
    mrPathSolverTurnRight();
    Serial.println("Mr Path Solver is Facing Trouble in Left side!!!"); 
    lcd.setCursor("trouble!!!",1);
    
  }
  else
  {
    mrPathSolverTurnRight();
    Serial.println("Stop");
    lcd.setCursor("Stop.",1);
  }
delay(3000);*/
 
  while(Serial.available())
  {
  char c = Serial.read();
  if(c=='F')
  {
    mrPathSolverForward();
    Serial.println("Mr.Path Solver is Forwarding.");
    lcd.setCursor(0,0);
    lcd.print("Mr.Path Solver");
    lcd.setCursor(0,1);
    lcd.print("is going Forward");
    
  }
  else if(c=='B')
  {
    mrPathSolverBackward();
    Serial.println("Mr.Path Solver is Backwarding.");
    lcd.setCursor(0,0);
    lcd.print("Mr.Path Solver");
    lcd.setCursor(0,1);
    lcd.print("is going Backward");
  }
  else if(c=='R')
  {
    mrPathSolverTurnRight();
    Serial.println("Mr.Path Solver is turn right.");
    lcd.setCursor(0,0);
    lcd.print("Mr.Path Solver");
    lcd.setCursor(0,1);
    lcd.print("is turing right");
  }
  else if(c=='L')
  {
    mrPathSolverTurnLeft();
    Serial.println("Mr.Path Solver is turn left.");
    lcd.setCursor(0,0);
    lcd.print("Mr.Path Solver");
    lcd.setCursor(0,1);
    lcd.print("is turing left");
  }
  else if(c=='S')
  {
    mrPathSolverStop();
    Serial.println("Mr.Path Solver is Stop Now.");
        lcd.setCursor(0,0);
    lcd.print("Mr.Path Solver");
    lcd.setCursor(0,1);
    lcd.print("is now Stop");

  } 
  }
}



void mrPathSolverForward()
{
  //analogWrite(RMF,255);
  analogWrite(LMF,0);
  analogWrite(RMF,0);
  
  //analogWrite(RMB,0);
  analogWrite(LMB,255);
  analogWrite(RMB,255);
}

void mrPathSolverBackward()
{
//  analogWrite(RMF,0);
    analogWrite(LMF,255);
    analogWrite(RMF,255);

//  analogWrite(RMB,255);
    analogWrite(LMB,0);
    analogWrite(RMB,0);
}

void mrPathSolverTurnRight()
{
 analogWrite(LMF,255);
 analogWrite(LMB,0);

 analogWrite(RMF,0);
 analogWrite(RMB,255);
}

void mrPathSolverTurnLeft()
{
  analogWrite(LMF,0);
  analogWrite(LMB,255);

  analogWrite(RMF,255);
  analogWrite(RMB,0);
}

void mrPathSolverStop()
{
  analogWrite(RMF,0);
  analogWrite(LMF,0);

  analogWrite(RMB,0);
  analogWrite(LMB,0);
}

