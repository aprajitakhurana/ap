const int led=13;
const int ldr=A0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode (led,OUTPUT);
pinMode (ldr,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int brightness=analogRead(ldr);
  Serial.println(ldr);
  if(brightness<=200)
 { Serial.println("turn on led");
  digitalWrite(led,HIGH);
 }
 else
  {digitalWrite(led,LOW);
  Serial.println("already bright outside");
  }


}
