#include "LedControl.h"
#include "stdio.h"

LedControl lc=LedControl(8,11,12,4);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=200;  // Delay between Frames

/* Blank
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000
*/

// Put values in arrays
byte forward[]={
  B00000000,
  B00111100,
  B01000010,
  B01011010,
  B01011010,
  B01000010,
  B00111100,
  B00000000
};
byte closed[]={
  B00000000,
  B00000000,
  B00000000,
  B01111110,
  B01111110,
  B00000000,
  B00000000,
  B00000000
};
byte left[]={
  B00000000,
  B00011110,
  B00100001,
  B00100111,
  B00100111,
  B00100001,
  B00011110,
  B00000000
};
byte leftup[]={
  B00011110,
  B00100111,
  B00100111,
  B00100001,
  B00100001,
  B00011110,
  B00000000,
  B00000000
};
byte up[]={
  B00111100,
  B01011010,
  B01011010,
  B01000010,
  B01000010,
  B00111100,
  B00000000,
  B00000000
};
byte rightup[]={
  B01111000,
  B11100100,
  B11100100,
  B10000100,
  B10000100,
  B01111000,
  B00000000,
  B00000000
};
byte right[]={
  B00000000,
  B01111000,
  B10000100,
  B11100100,
  B11100100,
  B10000100,
  B01111000,
  B00000000
};
byte rightdown[]={
  B00000000,
  B00000000,
  B01111000,
  B10000100,
  B10000100,
  B11100100,
  B11100100,
  B01111000
};
byte down[]={
  B00000000,
  B00000000,
  B00111100,
  B01000010,
  B01000010,
  B01011010,
  B01011010,
  B00111100
};
byte leftdown[]={
  B00000000,
  B00000000,
  B00011110,
  B00100001,
  B00100001,
  B00100111,
  B00100111,
  B00011110
};

void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.shutdown(2,false);
  lc.shutdown(3,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.setIntensity(2,5);  
  lc.setIntensity(3,5);
  lc.clearDisplay(0);    // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
}


//  Take values in Arrays and Display them
void eyeshow(byte picture[])
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,picture[i]);
  }
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(2,i,picture[i]);
  }
}

void testroll()
{
  int wait=100;
  eyeshow(forward);
  delay(300);
  eyeshow(closed);
  delay(wait);
  eyeshow(forward);
  delay(wait);
  eyeshow(closed);
  delay(wait);
  eyeshow(left);
  delay(200);
  eyeshow(leftup);
  delay(wait);
  eyeshow(up);
  delay(wait);
  eyeshow(rightup);
  delay(wait);
  eyeshow(right);
  delay(wait);
  eyeshow(rightdown);
  delay(wait);
  eyeshow(down);
  delay(wait);
  eyeshow(leftdown);
  delay(wait);
  eyeshow(left);
  delay(200);
  eyeshow(closed);
  delay(wait);
  eyeshow(forward);
  delay(300);  
}

void blinkingtest()
{
  eyeshow(forward);
  delay(random(100,5000));
  eyeshow(closed);
  delay(100);  
}

void randomeye(int a)
{
  switch(a)
  {
  case 1:
    eyeshow(left);
    break;
  case 2:
    eyeshow(leftup);
    break;
  case 3:
    eyeshow(up);
    break;
  case 4:
    eyeshow(rightup);
    break;
  case 5:
    eyeshow(right);
    break;
  case 6:
    eyeshow(rightdown);
    break;
  case 7:
    eyeshow(down);
    break;
  case 8:
    eyeshow(leftdown);
    break;
  default:
    eyeshow(forward);
  }
}

void loop()
{
  testroll();
  while(true)
  {
    randomeye(random(1,50));
    delay(random(200,4000));
    eyeshow(closed);
    delay(100);
  }
}
