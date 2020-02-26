#include <SPI.h>
#include <SD.h>

File myFile;
int time = 0;
int analogPin0= 0;
int analogPin1= 1;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");


}

void loop() {
  delay(1000);
  time = time +1;
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println(time);
    myFile.println(analogRead(analogPin0));
    myFile.println(analogRead(analogPin1));
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

