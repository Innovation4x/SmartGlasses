const int trig = 12; //Trigger pin of ultrasonic Sesnor
const int echo = 11; //Echo pin of ultrasonic Sesnor
long time_taken;
int dist,distance;

void setup() 
{
  Serial.begin(9600);  //tells the arduino to get ready to exchange messages with the serial monitor  at a data rate of 9600 bits/sec.
  pinMode(trig, OUTPUT); //configures the specified pin to behave as output/input.
  pinMode(echo, INPUT);
}

/*###Function to calculate distance###*/
void calculate_distance(int trigger, int echo)
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  time_taken = pulseIn(echo, HIGH);
  dist= time_taken*0.034/2;

}

void loop()
{
  calculate_distance(trig, echo);
  distance=dist; //getting distance of ultrasonic sensor
  Serial.println(distance);
  delay(6000);
}
