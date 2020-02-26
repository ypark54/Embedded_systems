void setup() {
  Serial.begin(9600);
  DDRB |= 2;
  
}

void loop() {
  delay(2);
  PORTB |=2;
  Serial.println(analogRead(0));
  PORTB = 0;
  Serial.println(analogRead(0));
}
