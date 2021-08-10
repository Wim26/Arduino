
int signalPin = A1;
int IRLEDPin = A2;
float target = 50;

#define REDPIN 3  
#define GREENPIN 4 
#define BLUEPIN 5 

#define REDPINII 6
#define GREENPINII 7
#define BLUEPINII 8
 
#define FADESPEED 3    
 
void setup() 
{
  Serial.begin(9600);
  pinMode(signalPin, INPUT);
  pinMode(IRLEDPin, OUTPUT);
  //pinMode(sensorValue, INPUT);
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

  pinMode(REDPINII, OUTPUT);
  pinMode(GREENPINII, OUTPUT);
  pinMode(BLUEPINII, OUTPUT);
}

float getTemperature() {
  float data = analogRead(signalPin);
  return (5.0 * data * 100.0) / 1024.0; 
}

 
void loop() {
  // read values
  int signal = analogRead(signalPin);
  if (Serial.available() > 0) {
    // check if data was requested
    byte inbyte = Serial.read();
    if (inbyte == 'a') {
      sendToProcessing('G', signal);
    }
  }

  if (analogRead(signalPin) > 250)
  {
    digitalWrite(IRLEDPin, LOW);
  }
  else
  {
    digitalWrite(IRLEDPin, HIGH);
  }

  // read the input on analog pin 0:
  int sensorValue = analogRead(A3);
  // print out the value you read:
  Serial.print("GSR Value: ");
  Serial.println(sensorValue);
  delay(1);        
  // delay in between reads for stability

  int r, g, b;

 if  (analogRead (sensorValue) < 350){
    // fade from blue to violet
  for (r = 0; r < 256; r++) { 
    analogWrite(REDPIN, r);
    delay(FADESPEED);
  } 
  // fade from violet to red
  for (b = 255; b > 0; b--) { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  } 
      // fade from blue to violet
  for (r = 0; r < 256; r++) { 
    analogWrite(REDPINII, r);
    delay(FADESPEED);
  } 
  // fade from violet to red
  for (b = 255; b > 0; b--) { 
    analogWrite(BLUEPINII, b);
    delay(FADESPEED);
  }  
 }
 
else{ 
  // fade from green to teal
  for (b = 0; b < 256; b++) { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  } 
  // fade from teal to blue
  for (g = 255; g > 0; g--) { 
    analogWrite(GREENPIN, g);
    delay(FADESPEED);
  }
   // fade from green to teal
  for (b = 0; b < 256; b++) { 
    analogWrite(BLUEPINII, b);
    delay(FADESPEED);
  } 
  // fade from teal to blue
  for (g = 255; g > 0; g--) { 
    analogWrite(GREENPINII, g);
    delay(FADESPEED);
  }
 }
}

void sendToProcessing(char c, int val) {
  Serial.print(c);
  Serial.println(val);
}
