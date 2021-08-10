

 #include <LiquidCrystal.h> 
 
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

 double x = 0;
 double y = 0;
 double a = 0;
 double b = 0;

 int windSensor = A1;
 float voltageMax = 2.0;
 float voltageMin = .4;
 float voltageConversionConstant = 0.004882814;
 float sensorVoltage = 0;

 float windSpeedMin = 0;
 float windSpeedMax = 32;

 int windSpeed = 0;
 int prevWindSpeed = 0;

//LED CONTROLOR
#include <FastLED.h>

#define NUM_LEDS 144
#define LED_PIN 7

CRGB led[NUM_LEDS];

 void setup () {
  //put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);


  //LED
  FastLED.addLeds<NEOPIXEL, LED_PIN> (led, NUM_LEDS);

  for (int i = 0; i < NUM_LEDS; i++){
    led[i] = CRGB (0, 0, 255);
    }
     FastLED.show();
    }


  void setBlue (int val) {
    for (int i = 0; i < NUM_LEDS; i++){
      led[i] = CRGB (val, val, 255);
     }

      FastLED.show();
    }
  
  void setRed (int val) {
   for (int i = 0; i < NUM_LEDS; i++){
     led[i] = CRGB (255, val, 0);
     }

     FastLED.show();
    }

 void loop () {
  
  int sensorValue = analogRead(windSensor);
  float voltage = sensorValue * (5.0 / 1023.0);
  sensorVoltage = sensorValue * voltageConversionConstant;

  if (sensorVoltage <= voltageMin) {
    windSpeed = 0; 
  }
  else {
    windSpeed = ((sensorVoltage - voltageMin) * windSpeedMax / (voltageMax - voltageMin)) * 2.232694; //For voltages above minimum value, use the liner relative
    }

  x = windSpeed;
  if (x >= y){
    y = x;
    }
  else {
    y = y;
    }    
    

  a = sensorVoltage;
  if (a >= b){
    b = a;
    }
  else {
    b = b;
    }
  if (windSpeed != prevWindSpeed) {
    Serial.println (windSpeed);
    Serial.println (sensorVoltage);
    prevWindSpeed = windSpeed; 
    }

    lcd.setCursor (0,0);
    lcd.print ("Wind Speed");
    lcd.setCursor (12, 0);
    lcd.print (windSpeed);
    lcd.print ("  ");
    lcd.setCursor (11, 2);
    lcd.print ("m/s");
    delay (100);
    
  if  (windSpeed < 5){
    for (int i = 255; i > 0; i--){
     setBlue(i);
      delay(10);
     }
     
     for (int i = 0; i < 256; i++){
     setBlue(i);
     delay(10);
     }
  }
  
  else{ 
    for (int i = 255; i > 0; i--){
     setRed(i);
     delay(10);
     }

     for (int i = 0; i < 256; i++){
      setRed(i);
     delay(10);
     }
    }
       
  }
 
 
 
