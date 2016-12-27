const int ledPin = 13;
const int speakerPin = 9;
const int sensorPin = 0;

// the next two lines set the min and max delay between blinks
const int minDuration = 100; // minimum wait between blinks
const int maxDuration = 1000; // maximum wait between blinks

// LED connected to digital pin 13
// connect sensor to analog input 0
void setup()
{
pinMode(ledPin, OUTPUT); // enable output on the led pin
Serial.begin(38400);
}
void loop()
{
int rate;

rate = map(analogRead(sensorPin), 200,800,minDuration, maxDuration); // convert to blink rate
rate = rate / 100;
//   hSerial.println(rate);
// TURN ON
digitalWrite(speakerPin, HIGH);
delay(rate);

// TURN OFF
digitalWrite(speakerPin, LOW);
delay(rate);
}


