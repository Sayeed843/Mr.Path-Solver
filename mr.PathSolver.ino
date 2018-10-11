#define RMF 16
#define RMB 5

#define LMF 2
#define LMB 13

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
  //digitalWrite(RMF,HIGH);
  digitalWrite(LMF,LOW);
  digitalWrite(RMF,LOW);
  
  //digitalWrite(RMB,LOW);
  digitalWrite(LMB,HIGH);
  digitalWrite(RMB,HIGH);
}

void mrPathSolverForward()
{
//  digitalWrite(RMF,LOW);
    digitalWrite(LMF,HIGH);
    digitalWrite(RMF,HIGH);

//  digitalWrite(RMB,HIGH);
    digitalWrite(LMB,LOW);
    digitalWrite(RMB,LOW);
}

void mrPathSolverTurnRight()
{
 digitalWrite(LMF,HIGH);
 digitalWrite(LMB,LOW);

 digitalWrite(RMF,LOW);
 digitalWrite(RMB,HIGH);
}

void mrPathSolverTurnLeft()
{
  digitalWrite(LMF,LOW);
  digitalWrite(LMB,HIGH);

  digitalWrite(RMF,HIGH);
  digitalWrite(RMB,LOW);
}

void mrPathSolverStop()
{
  digitalWrite(RMF,LOW);
  digitalWrite(LMF,LOW);

  digitalWrite(RMB,LOW);
  digitalWrite(LMB,LOW);
}

