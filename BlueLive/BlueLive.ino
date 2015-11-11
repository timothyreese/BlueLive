//Written by Timothy Reese, October 11th, 2015. 
//This code is a mix of Adafruit examples and my own customization.

// Connect pin #12 of the expander to Analog 5 (i2c clock)
// Connect pin #13 of the expander to Analog 4 (i2c data)
// Connect pins #15, 16 and 17 of the expander to ground (address selection)
// Connect pin #9 of the expander to 5V (power)
// Connect pin #10 of the expander to ground (common ground)
// Connect pin #18 through a ~10kohm resistor to 5V (reset pin, active low)

// Input #0 is on pin 21 so connect a button or switch from there to ground

#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_MCP23017 mcp0;
Adafruit_MCP23017 mcp1;
Adafruit_MCP23017 mcp2;

#define PIN 6 // for the NeoPixel data line.

Adafruit_NeoPixel strip = Adafruit_NeoPixel(14, PIN, NEO_GRB + NEO_KHZ800);

SoftwareSerial BT(4,3);  //RX, and then TX. These are not your hardware serials, don't get them confused or gibberish will ensue on boot.

void setup() {  
  Serial.begin(9600);
  BT.begin(9600);
  mcp0.begin(0);      // use default address 0
  mcp1.begin(1);      // use address 1
  mcp2.begin(2);      // use address 2

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

//  This could probably be an array
  mcp0.pinMode(0, INPUT);
  mcp0.pullUp(0, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(1, INPUT);
  mcp0.pullUp(1, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(2, INPUT);
  mcp0.pullUp(2, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(3, INPUT);
  mcp0.pullUp(3, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(4, INPUT);
  mcp0.pullUp(4, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(5, INPUT);
  mcp0.pullUp(5, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(6, INPUT);
  mcp0.pullUp(6, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(7, INPUT);
  mcp0.pullUp(7, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(8, INPUT);
  mcp0.pullUp(8, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(9, INPUT);
  mcp0.pullUp(9, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(10, INPUT);
  mcp0.pullUp(10, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(11, INPUT);
  mcp0.pullUp(11, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(12, INPUT);
  mcp0.pullUp(12, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(13, INPUT);
  mcp0.pullUp(13, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(14, INPUT);
  mcp0.pullUp(14, HIGH);  // turn on a 100K pullup internally
  mcp0.pinMode(15, INPUT);
  mcp0.pullUp(15, HIGH);  // turn on a 100K pullup internally
  
  mcp1.pinMode(0, INPUT);
  mcp1.pullUp(0, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(1, INPUT);
  mcp1.pullUp(1, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(2, INPUT);
  mcp1.pullUp(2, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(3, INPUT);
  mcp1.pullUp(3, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(4, INPUT);
  mcp1.pullUp(4, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(5, INPUT);
  mcp1.pullUp(5, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(6, INPUT);
  mcp1.pullUp(6, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(7, INPUT);
  mcp1.pullUp(7, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(8, INPUT);
  mcp1.pullUp(8, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(9, INPUT);
  mcp1.pullUp(9, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(10, INPUT);
  mcp1.pullUp(10, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(11, INPUT);
  mcp1.pullUp(11, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(12, INPUT);
  mcp1.pullUp(12, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(13, INPUT);
  mcp1.pullUp(13, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(14, INPUT);
  mcp1.pullUp(14, HIGH);  // turn on a 100K pullup internally
  mcp1.pinMode(15, INPUT);
  mcp1.pullUp(15, HIGH);  // turn on a 100K pullup internally

  mcp2.pinMode(0, INPUT);
  mcp2.pullUp(0, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(1, INPUT);
  mcp2.pullUp(1, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(2, INPUT);
  mcp2.pullUp(2, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(3, INPUT);
  mcp2.pullUp(3, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(4, INPUT);
  mcp2.pullUp(4, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(5, INPUT);
  mcp2.pullUp(5, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(6, INPUT);
  mcp2.pullUp(6, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(7, INPUT);
  mcp2.pullUp(7, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(8, INPUT);
  mcp2.pullUp(8, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(9, INPUT);
  mcp2.pullUp(9, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(10, INPUT);
  mcp2.pullUp(10, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(11, INPUT);
  mcp2.pullUp(11, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(12, INPUT);
  mcp2.pullUp(12, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(13, INPUT);
  mcp2.pullUp(13, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(14, INPUT);
  mcp2.pullUp(14, HIGH);  // turn on a 100K pullup internally
  mcp2.pinMode(15, INPUT);
  mcp2.pullUp(15, HIGH);  // turn on a 100K pullup internally

 // pinMode(13, OUTPUT);  // use the p13 LED as debugging
}

// For the Raw HID commands, here's the function.

void keyCommand(uint8_t modifiers, uint8_t keycode1, uint8_t keycode2 = 0, uint8_t keycode3 = 0, 
                uint8_t keycode4 = 0, uint8_t keycode5 = 0, uint8_t keycode6 = 0) {
  BT.write(0xFD);       // our command
  BT.write(modifiers);  // modifier!
  BT.write((byte)0x00); // 0x00  
  BT.write(keycode1);   // key code #1
  BT.write(keycode2); // key code #2
  BT.write(keycode3); // key code #3
  BT.write(keycode4); // key code #4
  BT.write(keycode5); // key code #5
  BT.write(keycode6); // key code #6
}

void loop() {
  // The LED will 'echo' the button - used for debugging.
//  digitalWrite(13, mcp0.digitalRead(0));

//NeoPixel Arcade Button Colors

strip.setPixelColor(0, 255, 165, 0);
strip.setPixelColor(1, 255, 165, 0);
strip.setPixelColor(2, 255, 165, 0);
strip.setPixelColor(3, 255, 165, 0);
strip.setPixelColor(4, 255, 165, 0);
strip.setPixelColor(5, 255, 165, 0);
strip.setPixelColor(6, 255, 0, 0);
strip.setPixelColor(7, 255, 0, 0);
strip.setPixelColor(8, 255, 0, 0);
strip.setPixelColor(9, 255, 0, 0);
strip.setPixelColor(10, 255, 0, 0);
strip.setPixelColor(11, 255, 0, 0);
strip.setPixelColor(12, 255, 0, 0);
strip.setPixelColor(13, 255, 165, 0);
strip.show();

  
// All keyCommands are from the Raw HID Keyboard Reports section, and you just count up from 4, 
//starting at 4 on the list. So "B" would be a 5.
// Likewise "I" would be a 12.
// The BT.write commands are using the Hex values for ASCII.
// I've included both because I used both while writing the original code, and also so you can 
//pick and choose if you wish to use it for another project.
  
  //Preview 1
  
  if (mcp0.digitalRead(0) == LOW) {
    Serial.println("Success Preview 1!");
  keyCommand(0,30);
  strip.setPixelColor(6, 255, 255, 255);
  strip.show();
  delay(250);
  keyCommand(0,0);
  }
  
  //Preview 2

if (mcp0.digitalRead(1) == LOW) {
    Serial.println("Success Preview 2!");
   keyCommand(0,31);
   strip.setPixelColor(7, 255, 255, 255);
  strip.show();
     delay(250);
   keyCommand(0,0);

  }

  //Preview 3

if (mcp0.digitalRead(2) == LOW) {
    Serial.println("Success Preview 3!");
   keyCommand(0,32);
   strip.setPixelColor(8, 255, 255, 255);
  strip.show();
     delay(250);
   keyCommand(0,0);

  }

  //Preview 4

if (mcp0.digitalRead(3) == LOW) {
    Serial.println("Success Preview 4!");
   keyCommand(0,33);
   strip.setPixelColor(9, 255, 255, 255);
  strip.show();
     delay(250);
   keyCommand(0,0);

  }

  //Preview 5

if (mcp0.digitalRead(4) == LOW) {
    Serial.println("Success Preview 5!");
   keyCommand(0,34);
   strip.setPixelColor(10, 255, 255, 255);
   strip.show();
     delay(250);
   keyCommand(0,0);

  }

  //Preview 6

if (mcp0.digitalRead(5) == LOW) {
    Serial.println("Success Preview 6!");
   keyCommand(0,35);
   strip.setPixelColor(11, 255, 255, 255);
   strip.show();
     delay(250);
   keyCommand(0,0);

  }

  //Auto Transition (Space)

if (mcp0.digitalRead(6) == LOW) {
    Serial.println("Success Auto Transition!");
   keyCommand(0,44);
   strip.setPixelColor(12, 255, 255, 255);
   strip.show();
   delay(250);
   keyCommand(0,0);

  }


  //Prog 1

if (mcp0.digitalRead(7) == LOW) {
    Serial.println("Success F1!");
  BT.write(0x0F);
  strip.setPixelColor(5, 255, 255, 255);
  strip.show();
     delay(250);
  }

  //Prog 2

if (mcp0.digitalRead(8) == LOW) {
    Serial.println("Success F2!");
  BT.write(0x10);
  strip.setPixelColor(4, 255, 255, 255);
  strip.show();
     delay(250);
  }

  //Prog 3

if (mcp0.digitalRead(9) == LOW) {
    Serial.println("Success F3!");
  BT.write(0x11);
  strip.setPixelColor(3, 255, 255, 255);
  strip.show();
     delay(250);
  }

  //Prog 4

if (mcp0.digitalRead(10) == LOW) {
    Serial.println("Success F4!");
  BT.write(0x12);
  strip.setPixelColor(2, 255, 255, 255);
  strip.show();
     delay(250);

  }

  //Prog 5

if (mcp0.digitalRead(11) == LOW) {
    Serial.println("Success F5!");
  BT.write(0x13);
  strip.setPixelColor(1, 255, 255, 255);
  strip.show();
     delay(250);
  }

  //Prog 6

if (mcp0.digitalRead(12) == LOW) {
    Serial.println("Success F6!");
  BT.write(0x14);
  strip.setPixelColor(0, 255, 255, 255);
  strip.show();
     delay(250);
  }

  //Cut (enter)

if (mcp0.digitalRead(13) == LOW) {
    Serial.println("Success Cut!");
   BT.write(0x0A);
   strip.setPixelColor(13, 255, 255, 255);
   strip.show();
     delay(250);

  }

  // Record (home)

if (mcp0.digitalRead(14) == LOW) {
    Serial.println("Success Record!");
  BT.write(0x02);
     delay(250);
  }

  // Go Live (end)

if (mcp0.digitalRead(15) == LOW) {
    Serial.println("Success Go Live!");
  BT.write(0x05);
     delay(250);
  }
  

  // Edit Media 1 (z)

if (mcp1.digitalRead(0) == LOW) {
    Serial.println("Success Edit Media 1!");
  BT.write(0x7A);
     delay(250);
  }
  

  // Edit Graphic 1 (q)

if (mcp1.digitalRead(1) == LOW) {
    Serial.println("Success Edit Graphic 1!");
  BT.write(0x71);
     delay(250);
  }
  

  // Edit Graphic 2 (w)

if (mcp1.digitalRead(2) == LOW) {
    Serial.println("Success Edit Graphic 2!");
  BT.write(0x77);
     delay(250);
  }


  // Edit Graphic 3 (e)

if (mcp1.digitalRead(3) == LOW) {
    Serial.println("Success Edit Graphic 3!");
  BT.write(0x65);
     delay(250);
  }
  
  
  // Go to Start (g)

if (mcp1.digitalRead(4) == LOW) {
    Serial.println("Success Go to Start!");
  BT.write(0x67);
     delay(250);
  }
  
  
  // Play/Pause (k)

if (mcp1.digitalRead(5) == LOW) {
    Serial.println("Success Play/Pause!");
  BT.write(0x6b);
     delay(250);
  }
  

  // Go to End (')

if (mcp1.digitalRead(6) == LOW) {
    Serial.println("Success Go to End!");
  BT.write(0x27);
     delay(250);
  }

  // Edit Media 2 (x)

if (mcp1.digitalRead(7) == LOW) {
    Serial.println("Success Edit Media 2!");
  BT.write(0x78);
     delay(250);
  }
  
    // Edit Audio (a)

if (mcp1.digitalRead(8) == LOW) {
    Serial.println("Success Edit Audio!");
  BT.write(0x61);
     delay(250);
  }

  // Edit Stream (s)

if (mcp1.digitalRead(9) == LOW) {
    Serial.println("Success Edit Stream!");
  BT.write(0x73);
     delay(250);
  }

  // Edit Transition (d)

if (mcp1.digitalRead(10) == LOW) {
    Serial.println("Success Edit Transition!");
  BT.write(0x64);
     delay(250);
  }

  // Go to In (u)

if (mcp1.digitalRead(11) == LOW) {
    Serial.println("Success Go to In!");
  BT.write(0x75);
     delay(250);
  }

  // Set In (i)

if (mcp1.digitalRead(12) == LOW) {
    Serial.println("Success Set In!");
  BT.write(0x69);
     delay(250);
  }

  // Set Out (o)

if (mcp1.digitalRead(13) == LOW) {
    Serial.println("Success Set Out!");
  BT.write(0x6F);
     delay(250);
  }

  // Graphics 1 Preview (Numpad 1)

if (mcp1.digitalRead(14) == LOW) {
    Serial.println("Success Graphics 1 Preview!");
   keyCommand(0,89);
     delay(250);
   keyCommand(0,0);

  }
  
  // Graphics 2 Preview (Numpad 2)

if (mcp1.digitalRead(15) == LOW) {
    Serial.println("Success Graphics 2 Preview!");
   keyCommand(0,90);
     delay(250);
   keyCommand(0,0);

  }

  // Graphics 3 Preview (Numpad 3)

if (mcp2.digitalRead(0) == LOW) {
    Serial.println("Success Graphics 3 Preview!");
   keyCommand(0,91);
     delay(250);
   keyCommand(0,0);

  }

  // Graphics 1 Push (Numpad 4)

if (mcp2.digitalRead(1) == LOW) {
    Serial.println("Success Graphics 1 Push!");
   keyCommand(0,92);
     delay(250);
   keyCommand(0,0);

  }

  // Graphics 2 Push (Numpad 5)

if (mcp2.digitalRead(2) == LOW) {
    Serial.println("Success Graphics 2 Push!");
   keyCommand(0,93);
     delay(250);
   keyCommand(0,0);

  }

  // Graphics 3 Push (Numpad 6)

if (mcp2.digitalRead(3) == LOW) {
    Serial.println("Success Graphics 3 Push!");
   keyCommand(0,94);
     delay(250);
   keyCommand(0,0);

  }

  // Graphics 1 Pull (Numpad 7)

if (mcp2.digitalRead(4) == LOW) {
    Serial.println("Success Graphics 1 Pull!");
   keyCommand(0,95);
     delay(250);
   keyCommand(0,0);

  }

  // Graphics 2 Pull (Numpad 8)

if (mcp2.digitalRead(5) == LOW) {
    Serial.println("Success Graphics 2 Pull!");
   keyCommand(0,96);
     delay(250);
   keyCommand(0,0);
   
  }

  // Graphics 3 Pull (Numpad 9)

if (mcp2.digitalRead(6) == LOW) {
    Serial.println("Success Graphics 3 Pull!");
   keyCommand(0,97);
   delay(250);
   keyCommand(0,0);
     
  }

}

//This is a breakdown of the Function Commands via Hex, 
//since they're not spelled out on the Bluefruit guide.
//0x0F  = F1
//0x10 = F2
//0x11 = F3
//0x12 = F4
//0x13 = F5
//0x14  = F6
//0x15  = F7
//0x16  = F8
//0x17  = F9
//0x18  = F10
//0x19  = F11
//0x1A  = F12

// https://learn.adafruit.com/introducing-bluefruit-ez-key-diy-bluetooth-hid-keyboard/sending-keys-via-serial
// http://www.instructables.com/id/different-ways-to-count/
