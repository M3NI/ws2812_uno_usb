String readString, r, g, b;
#include <FastLED.h> //Load FastLED Library
#define LED_PIN     6  //Pin that your LEDs are connected to
#define NUM_LEDS    1  //Number of your LEDs
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  Serial.println("Enter Color Code in this format RRRGGGBBB"); // so I can keep track of what is loaded
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {

  while (Serial.available()) {
    delay(3);  //delay to allow buffer to fill
    if (Serial.available() >0) {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
    }
  }

  if (readString.length() >0) {
      Serial.println(readString); //see what was received
     
      // expect a string like 07002100 containing the two servo positions     
      r = readString.substring(0, 3); //get the first four characters
      g = readString.substring(3, 6); //get the next four characters
      b = readString.substring(6, 9); //get the next four characters
      
    //  Serial.println(r);  //print to serial monitor to see parsed results
    //  Serial.println(g);
    //  Serial.println(b);

      int n1 = r.toInt();
      int n2 = g.toInt();
      int n3 = b.toInt();

    //  Serial.println("the numbers are :");
    //  Serial.println(n1);  //print to serial monitor to see number results
    //  Serial.println(n2);
    //  Serial.println(n3);
      leds[0] = CRGB(n1,n2,n3);
      FastLED.show();
           
    readString="";
  }
}
