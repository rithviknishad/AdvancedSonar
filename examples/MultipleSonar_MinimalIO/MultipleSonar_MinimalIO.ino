#include <Sonar.h>

#define PIN_TRIG        2
#define PIN_ECHO        3
#define no_of_sensors   8

// unit is by default uints_cm. to change unit to units_inch, uncomment the line below
//#define DEFAULT_ULTRASONIC_REPORTING_UNIT units_inch

// Initialize SonarArray Object
SonarArray<no_of_sensors> sonars = SonarArray<no_of_sensors>(PIN_TRIG, PIN_ECHO);

void setup() {
    Serial.begin( 115200 );
}

void loop() {
    sonars.Scan();

    for (size_t i = 0; i < no_of_sensors; ++i) {
        Serial.print(sonars.Distances[i]);  Serial.print(", ");
    }
    Serial.println();

    delay(200);
}