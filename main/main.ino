#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>

Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();

uint8_t pixelArray[9][16];

void initArray(){
  for (int x = 0; x < 9; ++x)
  {
    for (int y = 0; y < 16; ++y)
    {
      pixelArray[x][y] = int(x * y * 1.7) + 10; // diagonal brightness gradient as default pattern; range is 0-255
    }
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("ISSI manual animation test");
  if (! matrix.begin()) {
    Serial.println("IS31 not found");
    while (1);
  }
  Serial.println("IS31 Found!");
  initArray();
  matrix.clear();
}

void loop() {
  matrix.setRotation(0);
  for (int x = 0; x < 9; ++x)
  {
    for (int y = 0; y < 16; ++y)
    {
      matrix.drawPixel(y, x, pixelArray[x][y]); // matrix is in a "portrait" orientation to match a smartphone screen
    }
  }  
}
