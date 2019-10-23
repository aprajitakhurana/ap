
#define motorA1 A0 //pwm
#define motorA2 5 //dir
#define motorB1 A1 //pwm
#define motorB2 7 //dir
#define motorC1 A2 //pwm
#define motorC2 9 //dir
#define motorD1 A3  //pwm
#define motorD2 11//dir
char a;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
     //  digitalWrite(enableA,HIGH);
      //digitalWrite(enableB,HIGH);
if(Serial.available())
 { 
  a=(char)Serial.read();
  
  
   
    if(a== 'f')
    { analogWrite(motorA1,255);
      digitalWrite(motorA2,HIGH);
      analogWrite(motorB1,255);
      digitalWrite(motorB2,HIGH);
      analogWrite(motorC1,255);
      digitalWrite(motorC2,HIGH);
      analogWrite(motorD1,255);
      digitalWrite(motorD2,HIGH); 
    }
   if(a== 'b')
    { analogWrite(motorA1,255);
      digitalWrite(motorA2,LOW);
      analogWrite(motorB1,255);
      digitalWrite(motorB2,LOW);
      analogWrite(motorC1,255);
      digitalWrite(motorC2,LOW);
      analogWrite(motorD1,255);
      digitalWrite(motorD2,LOW);
     
    }
    if(a== 'r')
    { analogWrite(motorA1,255);
      digitalWrite(motorA2,LOW);
      analogWrite(motorB1,100);
      digitalWrite(motorB2,LOW);
      analogWrite(motorC1,255);
      digitalWrite(motorC2,LOW);
      analogWrite(motorD1,100);
      digitalWrite(motorD2,LOW);
     
      
    }
   if(a== 'l')
    { analogWrite(motorA1,100);
      digitalWrite(motorA2,HIGH);
      analogWrite(motorB1,255);
      digitalWrite(motorB2,HIGH);
      analogWrite(motorC1,100);
      digitalWrite(motorC2,HIGH);
      analogWrite(motorD1,255);
      digitalWrite(motorD2,HIGH);
     
      
    }
   if(a== 's')
    { digitalWrite(motorA1,LOW);
      digitalWrite(motorA2,LOW);
      digitalWrite(motorB1,LOW);
      digitalWrite(motorB2,LOW);
      digitalWrite(motorC1,LOW);
      digitalWrite(motorC2,LOW);
      digitalWrite(motorD1,LOW);
      digitalWrite(motorD2,LOW);
     
    }
    
    
  } 
    

}
