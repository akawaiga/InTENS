#include <SPI.h>
#define MAX_4_BIT 15
int valSin;
void setup() {
  Serial.begin(9600);
}
void loop() {
  for (int i = 0; i<360;i++) {
    valSin = ((sin(i*2.4)+1)* MAX_4_BIT)/2;
    byte lowbite = valSin;
    PORTD = lowbite;
    delay(1);
    Serial.print(valSin/4);
    Serial.print(",");
    Serial.println(analogRead(6));
  }
}
