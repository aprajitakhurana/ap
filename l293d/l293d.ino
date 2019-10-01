

int enableA=2;
int motorA1=4;
int motorA2=5;
int enableB=3;
int motorB1=6;
int motorB2=7;
char a;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(enableA,OUTPUT);
pinMode(motorA1,OUTPUT);
pinMode(motorA2,OUTPUT);
pinMode(enableB,OUTPUT);
pinMode(motorB2,OUTPUT);
pinMode(motorB1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
     //  digitalWrite(enableA,HIGH);
      //digitalWrite(enableB,HIGH);
  switch(a)
  
  { case('s'):
    {
      digitalWrite(enableA,LOW);
      digitalWrite(enableB,LOW);
      delay(1000);
    }
    case('f'):
    { digitalWrite(motorA1,HIGH);
      digitalWrite(motorA2,LOW);
      digitalWrite(motorB1,HIGH);
      digitalWrite(motorB2,LOW);
      delay(3000);
    }
    case('b'):
    { digitalWrite(motorA1,LOW);
      digitalWrite(motorA2,HIGH);
      digitalWrite(motorB1,LOW);
      digitalWrite(motorB2,HIGH);
      delay(3000);
    }

}}
