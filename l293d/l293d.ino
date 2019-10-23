
#define motorA1 4
#define motorA2 5
#define motorB1 6
#define motorB2 7
char a;
int w=1.57;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//pinMode(enableA,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
//pinMode(enableB,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
     //  digitalWrite(enableA,HIGH);
      //digitalWrite(enableB,HIGH);
if(Serial.available())
 { 
  a=(char)Serial.read();
  
  
   
    if(a== 'f')
    { digitalWrite(motorA1,HIGH);
      digitalWrite(motorA2,LOW);
      digitalWrite(motorB1,HIGH);
      digitalWrite(motorB2,LOW);
    
    }
   if(a== 'b')
    { digitalWrite(motorA1,LOW);
      digitalWrite(motorA2,HIGH);
      digitalWrite(motorB1,LOW);
      digitalWrite(motorB2,HIGH);
     
    }
    if(a== 'l')
    { digitalWrite(motorA1,HIGH);
      digitalWrite(motorA2,LOW);
      digitalWrite(motorB1,LOW);
      digitalWrite(motorB2,HIGH);
      delay(1000);
    }
   if(a== 'r')
    { digitalWrite(motorA1,LOW);
      digitalWrite(motorA2,HIGH);
      digitalWrite(motorB1,HIGH);
      digitalWrite(motorB2,LOW);
      delay(1000);
      return;
    }
   if(a== 's')
    { digitalWrite(motorA1,LOW);
      digitalWrite(motorA2,LOW);
      digitalWrite(motorB1,LOW);
      digitalWrite(motorB2,LOW);
     
    }
    
    
  } 
    

}
