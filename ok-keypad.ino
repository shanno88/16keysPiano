
#include <SoftwareSerial.h>
#include <TTP229.h>
SoftwareSerial Serial1(10, 11);

const int SCL_PIN = A4;  // The pin number of the clock pin.
const int SDO_PIN = A5;  // The pin number of the data pin.

TTP229 ttp229(SCL_PIN, SDO_PIN); // TTP229(sclPin, sdoPin)
unsigned char order[4] = {0xAA,0x06,0x00,0xB0};
void setup()
{
    Serial.begin(115200);
    Serial.println("Start Touching One Key At a Time!");
  Serial1.begin(9600);
  volume(0x1E);//音量设置0x00-0x1E
}

void loop()
{
    uint8_t key = ttp229.ReadKey16(); // Blocking
    if (key) 
    Serial.println(key);
  if (key == 9) {
  play(0x01);
  }
  else if (key == 10) {
  play(0x02);
  }
  else if (key == 11) {
  play(0x03);
  }
  else if (key == 12) {
  play(0x04);
  }
  else if (key == 13) {
  play(0x05);
  }
  else if (key == 14) {
  play(0x06);
  }
  else if (key == 15) {
  play(0x07);
  }
  else if (key == 16) {
  play(0x08);
  }
}
void play(unsigned char Track)
{
unsigned char play[6] = {0xAA,0x07,0x02,0x00,Track,Track+0xB3};//0xB3=0xAA+0x07+0x02+0x00,即最后一位为校验和
Serial1.write(play,6);
}
void volume( unsigned char vol)
{
unsigned char volume[5] = {0xAA,0x13,0x01,vol,vol+0xBE};//0xBE=0xAA+0x13+0x01,即最后一位为校验和
Serial1.write(volume,5);
}
