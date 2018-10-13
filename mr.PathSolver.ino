#define RMF A1
#define RMB A0

#define LMF A2
#define LMB A3

void mrPathSloverForward();
void mrPathSolverBackward();
void mrPathSolverTurnRight();
void mrPathSolverTurnLeft();
void mrPathSolverStop();


//char str[2],i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RMF,OUTPUT);
  pinMode(RMB,OUTPUT);
  pinMode(LMF,OUTPUT);
  pinMode(LMB,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
  char c = Serial.read();
  if(c=='F')
  {
    mrPathSolverForward();
    Serial.println("Mr.Path Solver is Forwarding.");
  }
  else if(c=='B')
  {
    mrPathSolverBackward();
    Serial.println("Mr.Path Solver is Backwarding.");
  }
  else if(c=='R')
  {
    mrPathSolverTurnRight();
    Serial.println("Mr.Path Solver is turn right.");
  }
  else if(c=='L')
  {
    mrPathSolverTurnLeft();
    Serial.println("Mr.Path Solver is turn left.");
  }
  else if(c=='S')
  {
    mrPathSolverStop();
    Serial.println("Mr.Path Solver is Stop now.");
  }
  }
}

void mrPathSolverBackward()
{
  //analogWrite(RMF,255);
  analogWrite(LMF,0);
  analogWrite(RMF,0);
  
  //analogWrite(RMB,0);
  analogWrite(LMB,255);
  analogWrite(RMB,255);
}

void mrPathSolverForward()
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

