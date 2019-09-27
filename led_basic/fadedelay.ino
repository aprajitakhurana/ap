int b=0;//brightness=0

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(9,b);
 
  for(b=0;b<=255;b++)
  delay(6);

  for(b=255;b>=0;b--)
  delay(4);
  }
