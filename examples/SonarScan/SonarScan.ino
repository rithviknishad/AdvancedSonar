#include <Sonar.h>

#define PIN_TRIG    2
#define PIN_ECHO    3

// unit is by default uints_cm. to change unit to units_inch, uncomment the line below
//#define DEFAULT_ULTRASONIC_REPORTING_UNIT units_inch

// Initialize a Sonar Object with offset => 3 units, MaxDistance => 100 units
Sonar distance = Sonar(PIN_TRIG, PIN_ECHO, 3, 100);

void setup() {
    Serial.begin( 115200 );
}

void loop() {
    // prints the sonar reading in a new line
    Serial.println( (float) distance ); // casting a Sonar_Object to int / float 
                                        // reutrns Sonar_Object.Scan() (ie the distance)
    delay(200);
}