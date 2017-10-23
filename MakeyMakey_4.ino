/*
  Serial Event example
 
 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and 
 clears it.
 
 A good test for this is to try it with a GPS receiver 
 that sends out NMEA 0183 sentences. 
 
 Created 9 May 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/SerialEvent
 
 */

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH); 
  
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString); 
    
    if (inputString == "1\n"){
     digitalWrite(3,LOW); 
    }
    if (inputString == "2\n"){
     digitalWrite(4,LOW); 
    }
    if (inputString == "3\n"){
     digitalWrite(5,LOW); 
    }
    if (inputString == "4\n"){
     digitalWrite(6,LOW); 
    }
    delay(100);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}
/*
PROCESSING
// Example by Tom Igoe 
 
import processing.serial.*; 
//import processing.sound.*;

import ddf.minim.spi.*;
import ddf.minim.signals.*;
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.ugens.*;
import ddf.minim.effects.*;
 
Minim minim;
AudioPlayer file1;
AudioPlayer file2;
boolean keyP;


Serial myPort;    // The serial port
PFont myFont;     // The display font
String inString;  // Input string from serial port
int lf = 10;      // ASCII linefeed 
 int value = 0;
 
void setup() { 
  size(400,200); 
  // You'll need to make this font with the Create Font Tool 

  // List all the available serial ports: 
  printArray(Serial.list()); 
  // I know that the first port in the serial list on my mac 
  // is always my  Keyspan adaptor, so I open Serial.list()[0]. 
  // Open whatever port is the one you're using. 
  myPort = new Serial(this, Serial.list()[0], 9600); 

  minim = new Minim(this);
  file1 = minim.loadFile("sample.mp3");
  
  file2 = minim.loadFile("sample1.mp3");

} 
 
void draw() { 
  background(0); 
  text("received: " + inString, 10,50); 
  text(value , 40,90); 
  
} 



void keyPressed() {
    if (key == 'g' && !file1.isPlaying()) {
      myPort.write("1\n");
  // Load a soundfile from the /data folder of the sketch and play it back
      file1.rewind();
      file1.play();
    } else if (key == 'f' && !file2.isPlaying()) {
      myPort.write("2\n");
  // Load a soundfile from the /data folder of the sketch and play it back
      file2.rewind();
      file2.play();
     
    } else if (key ==  'd' && !file2.isPlaying()) {
      myPort.write("3\n");
  // Load a soundfile from the /data folder of the sketch and play it back
      file2.rewind();
      file2.play();
    } 
     else if (key == 's' && !file2.isPlaying()) {
      myPort.write("4\n");
  // Load a soundfile from the /data folder of the sketch and play it back
      file2.rewind();
      file2.play();
     
  } else {
    myPort.write("n\n");
  }
    
}
*/
