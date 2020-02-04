#include <SoftwareSerial.h>
SoftwareSerial nodemcu(2, 3);

int SensorPin = A0; //aArduino Analog Input 0
String cdata;
String myString;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(SensorPin, INPUT);
  Serial.begin(9600);
  nodemcu.begin(9600);
}

void loop()
{

  int myValue = analogRead(SensorPin);
  if (myValue < 60)
  {
    myString = "cicho";
  }
  else
  {
    myString = "glosno";
  }
  Serial.println("----");
  Serial.println(myValue);
  cdata = cdata + myValue + "," + myString;
  nodemcu.println(cdata);
  Serial.println(cdata);
  Serial.println("----");
  delay(1000); // 100 milli seconds
  cdata = "";
}
