void setup() {
  Serial.begin(9600);
  ADMUX |= 1<<REFS0;  //Set reference voltage to AVCC
  ADMUX &= ~1<<ADLAR; //Set # of bits to 10
  ADCSRA |=1<<ADEN;   //Enable ADC
  ADCSRA |=1<<ADIE;   //Enable interrupt to be called on completion of ADC conversion
  ADCSRA |= (1<<ADPS0 | 1<< ADPS1 | 1<<ADPS2); //Set prescaler divisor value
  
  sei();              //Enable global interrupts
}

void loop() {
  delay(1000);
  mux(0);
  ADCSRA |= 1<<ADSC; // Initiate single ADC conversion
  delay(1000);
  mux(1);
  ADCSRA |= 1<<ADSC; // Initiate single ADC conversion
}

ISR(ADC_vect) {
  Serial.println(mux());
  Serial.println(ADC);
}

void mux(int pin)  {
  if (pin <=5){
    ADMUX &=0b11110000;
    ADMUX |= pin;
  }
}

int mux() {
  return ADMUX & 0b00001111;
}
