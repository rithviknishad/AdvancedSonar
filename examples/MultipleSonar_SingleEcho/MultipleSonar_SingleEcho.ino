#include <Sonar.h>

#define PIN_TRIG0   2
#define PIN_TRIG1   3
#define PIN_TRIG2   4
#define PIN_TRIG3   5
#define PIN_ECHO    7

// unit is by default uints_cm. to change unit to units_inch, uncomment the line below
//#define DEFAULT_ULTRASONIC_REPORTING_UNIT units_inch

// Initialize all Sonar Objects with
// respective trig pins, and shared echo pin
Sonar sonar0 = Sonar(PIN_TRIG0, PIN_ECHO);
Sonar sonar1 = Sonar(PIN_TRIG1, PIN_ECHO);
Sonar sonar2 = Sonar(PIN_TRIG2, PIN_ECHO);
Sonar sonar3 = Sonar(PIN_TRIG3, PIN_ECHO);

void setup() {
    Serial.begin( 115200 );
}

void loop() { 
    // prints sonar readings in a new line
    Serial.print  ( (float) sonar0 );   Serial.print(',');
    Serial.print  ( (float) sonar1 );   Serial.print(',');
    Serial.print  ( (float) sonar2 );   Serial.print(',');
    Serial.println( (float) sonar3 );   

    delay(200);
}