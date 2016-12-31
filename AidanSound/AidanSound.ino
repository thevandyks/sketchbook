// Make sounds with a buzzer

// aidan@highrise.ca
/***********************************/
int buzzer = 12;//the pin of the active buzzer
void setup()
{
	Serial.begin(38400);
	pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
}

void Tone (unsigned period_usec, unsigned length_msec)
{
	unsigned elapsed_msec = 0;
	unsigned long delta_usec = 0;
	while (elapsed_msec < length_msec) {
		digitalWrite(buzzer, HIGH);
		delayMicroseconds(period_usec/2);
		digitalWrite(buzzer, LOW);
		delayMicroseconds(period_usec/2);
		delta_usec += period_usec*2;
		while (delta_usec > 1000) {
			elapsed_msec ++;
			delta_usec -= 1000;
		}
	}
}

void PlayHz (unsigned long hz, unsigned length_msec)
{
	if (hz) {
		unsigned long period = 1000000 / hz;
		Tone(period, length_msec);
	} else {
		while (length_msec--)
			delayMicroseconds(1000);
	}

}

#if 0
note    frequency    period    timeHigh
c       261 Hz       3830       1915     
d       294 Hz       3400       1700     
e       329 Hz       3038       1519     
f       349 Hz       2864       1432     
g       392 Hz       2550       1275     
a       440 Hz       2272       1136     
b       493 Hz       2028       1014      
C       523 Hz       1912        956
#endif

const unsigned int DURATION = 500;

void PlayNotes (const char* str)
{
	char c;
	unsigned old_hz, old_l, hz, l;
	old_hz = 0;
	while (c = *str++) {
		switch (c) {
#define NOTE(_c, _hz)  case _c: hz = _hz; l = 0; break;
			NOTE('c', 261);
			NOTE('d', 294);
			NOTE('e', 329);
			NOTE('f', 349);
			NOTE('g', 392);
			NOTE('a', 440);
			NOTE('b', 493);
			NOTE('C', 523);
			NOTE(' ', 0);
			case '.':
				l++;
		}
		if (l == 0 && old_l)
			PlayHz(old_hz, old_l*DURATION);
		l++;
		old_l = l; old_hz = hz;
	}
	if (old_l)
		PlayHz(old_hz, old_l*DURATION);
}

void Siron (void )
{
	unsigned long hz;

	for (hz = 200; hz < 1000; hz++)
		PlayHz(hz, 5);
	for (; hz > 200; hz--)
		PlayHz(hz, 5);
	delay(2);

	for (hz = 0; hz < 5; hz++) {
		PlayHz(230, 800);
		PlayHz(680, 800);
	}

}


void loop()
{
#if 0
	PlayNotes("cdefgabC");
	PlayNotes("edcdeeedddeggedcdeeeeddedc");
	PlayNotes("ccggaag ffeeddccggffeeddggffeeddccggaaggffeeddc.");
#endif

	Siron();

	while (1) delay (1000);
}
/****************************************/
