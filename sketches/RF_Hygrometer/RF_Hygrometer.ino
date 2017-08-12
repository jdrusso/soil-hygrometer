/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CNS, CE
const uint64_t pipes[2] = { 0xABCDABCD71LL, 0x544d52687CLL }; 

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(pipes[1]);
//  radio.setPALevel(RF24_PA_MIN);                          // Setup and configure rf radio  
  radio.setChannel(1);                     // Set the channel  
  radio.setPALevel(RF24_PA_HIGH);  
  radio.setDataRate(RF24_250KBPS);  
//  radio.setDataRate(RF24_2MBPS);  
  radio.setAutoAck(1);                     // Ensure autoACK is enabled  
  radio.setRetries(2,15);                  // Optionally, increase the delay between retries. Want the number of auto-retries as high as possible (15)  
  radio.setCRCLength(RF24_CRC_16);         // Set CRC length to 16-bit to ensure quality of data  
  radio.stopListening();
}

void loop() {

   // Get hygrometer sensor data
  int sensorValue = analogRead(A0);
  const char sensor[4];
  sprintf(sensor, "%d", sensorValue);
  
  const char text[] = "Hello World";
  Serial.println(sensorValue);
  radio.write(&sensor, sizeof(sensor));
  delay(1000);
}
