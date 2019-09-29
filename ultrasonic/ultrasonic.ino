int trig=9;
int echo=10;
double distance;
double timetaken;
void setup()
{
  // put your setup code here, to run once:
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

timetaken=pulseIn(echo,HIGH);

distance=timetaken*0.034/2;

Serial.print("distance:");
Serial.println(distance);
}
