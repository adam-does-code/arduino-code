#include "SevSeg.h"
#include <DS3231.h>

DS3231 clock;
RTCDateTime dt;
SevSeg sevseg; 

void setup(){
  Serial.begin(9600); 
  clock.begin();
  clock.setDateTime(__DATE__,__TIME__);

  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop(){
    dt = clock.getDateTime();

    int result = (dt.hour * 100) + dt.minute;
    sevseg.setNumber(result, -1);
    sevseg.refreshDisplay(); 
}
