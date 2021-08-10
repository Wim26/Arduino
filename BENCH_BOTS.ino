#define LED_first_ping 10

const int trigPins[2] = {3, 7}; 
const int echoPins[2] = {4, 8}; 

const int sensorDistance = 53;   //15 is the cm distance at which the sensors distant from eachother in CM

int redled = 10; //wailking
int yellowled = 11; //running

int s;

void setup() {

  Serial.begin(9600);
  pinMode(trigPins[0], OUTPUT); 
  pinMode(echoPins[0], INPUT);  
  pinMode(trigPins[1], OUTPUT); 
  pinMode(echoPins[1], INPUT);  

  pinMode(yellowled, OUTPUT);
  pinMode(redled, OUTPUT);

}


bool getDistance(int sensor)
{

  digitalWrite(trigPins[sensor], LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPins[sensor], HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPins[sensor], LOW); 


  long duration = pulseIn(echoPins[sensor], HIGH); 

  long distance = ((duration / 2) * 0.0343);

  if (distance < 50) 
  {
    return true;
  }

  else
  {
    return false;
  }

}


void loop() {

  if (getDistance(0) == true)                  
  {
    unsigned long currentMillis = millis();              

    while (getDistance(1) == false);           
    unsigned long endMillis = millis();                   

    unsigned long timeMillis = endMillis - currentMillis; 
    float timeSeconds = timeMillis / 1000.0;              

    float s = sensorDistance / timeSeconds;       
    Serial.print(s);
    Serial.println(" cm/s");
 
    //walking
     if (s < 20) // if distance is less than 30 Cm turn the LED ON 600
  {
    digitalWrite(redled, HIGH);
    digitalWrite(yellowled, LOW);
   
  }

  //running
  //do the same thing for second sensor 600,1200
  if ( (s>20) && (s<100) )
  {
    digitalWrite(yellowled, HIGH);
    digitalWrite(redled, LOW);
  }
  
  //cycling
  if (s > 100) //1200
 {
   digitalWrite(yellowled, HIGH);
   digitalWrite(redled, HIGH);
  }

 
 
  }  
}
