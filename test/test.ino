// Buzzer
// buzzer make sounds
//Email:350071174@qq.com
/***********************************/
int buzzer = 12;//the pin of the active buzzer
void setup()
{
  Serial.begin(38400);
pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
}

void PlaySound(int freq, int length)
{
  int i;
  for (i = 0; i < length; i++) 
  {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(freq);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(freq);
  }
}

void loop()
{
  unsigned char i; //define a variable
  while(1)
  
  if(1)
  
  {for(i=1000; i > 1; i++)
   PlaySound(100-i, 1)
   for(i=100; i > 1;
