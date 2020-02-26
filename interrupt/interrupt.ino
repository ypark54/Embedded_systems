/*void timerInit() {
  TCCR1A = 0;               // set entire TCCR0A register to 0
  TCCR1B = 0;               // same for TCCR0B
  TCNT1  = 0;               //initialize counter value to 0
  TCCR1A |= (1 << WGM01);   // turn on CTC mode
  TIMSK1 |= (1 << OCIE0A);  // enable timer compare interrupt
}*/
void setup() {
  cli(); 
  //timerInit();
  Serial.begin(9600);
  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1A |= 1<<COM1A0;
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  //OCR1A = 1000;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei();
  DDRB |= 0b11111111;
  DDRD |= 1<<6;
  DDRD |= 1<<5;
}
/*
int freqtoclock(int freq, int bits, int prescaler) {
  return freq*2/
}*/
int i;
void loop() {
  Serial.println("a");
  for (i = 0;i<20000;i=i+1000){
    OCR1A = i;
    Serial.println(i);
  }
}
/*
ISR(TIMER0_COMPA_vect)  {
  if (PORTB ==0){
    PORTB |=2;
  }
  else {
  PORTB = 0;
  }

}
*/
