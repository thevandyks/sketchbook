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

void SirenWailing(void)
{
  int i;

    for(i=0;i<200;i++)
      PlaySound(1000-i, 5);
    for(i=200; i > 0; i--)
      PlaySound(1000-i, 5);
    for(i=0;i<200;i++)
      PlaySound(1000-i, 5);
    for(i=200; i > 0; i--)
      PlaySound(1000-i, 5); 
}

 
 
 void loop ()
{
  while (1)
 if(1){
   // We put our siriens stuff
    PlaySound(100,20);
    PlaySound(5000,20);
    PlaySound(10000,20);
    
   
 } 

}

