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
  {   
    if (1)
    {    //output another frequency
	for(i=0;i<100;i++)
	  PlaySound(500-i, 2);
	for(i=100; i > 0; i--)
	  PlaySound(500-i, 2);
	for(i=0;i<100;i++)
	  PlaySound(500-i, 2);
	for(i=100; i > 0; i--)
	  PlaySound(500-i, 2); 
	for(i=0;i<100;i++)
	  PlaySound(500-i, 2);
	for(i=100; i > 0; i--)
	  PlaySound(500-i, 2);
	for(i=0;i<100;i++)
	  PlaySound(500-i, 2);
	for(i=100; i > 0; i--)
	  PlaySound(500-i, 2);
	for(i=0;i<100;i++)
	  PlaySound(500-i, 2);
	for(i=100; i > 0; i--)
	  PlaySound(500-i, 2);
	for(i=0;i<100;i++)
	  PlaySound(500-i, 2);
	for(i=100; i > 0; i--)
	  PlaySound(500-i, 2);
	
	if (1) { int r = random(30);
	  PlaySound(1500, 200);
	  delay(300);
	  PlaySound(1500, 200);
	}
    }
  }
}
