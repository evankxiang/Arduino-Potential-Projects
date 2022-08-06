
// Include Libraries
#include "Arduino.h"
#include "LIDARLite.h"
#include "Wire.h"


// Pin Definitions
#define FINGERPRINTSCANNER_5V_PIN_RX	10
#define FINGERPRINTSCANNER_5V_PIN_TX	11



// Global variables and defines

// object initialization
LIDARLite lidarLite;


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    lidarLite.begin(0, true); // Set configuration to default '0', change this number to try out alternate configurations. I2C speed set to 400 kHz.
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1')
    {
    // Disclaimer: The Fingerprint Scanner - TTL (GT-511C3) is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '2') {
    // LIDAR-Lite v3 - Test Code
    // Take a measurement with receiver bias correction and print to serial terminal
    int lidarLiteDist = lidarLite.distance();
    Serial.print(lidarLiteDist);
    Serial.println(" [cm]");
    delay(50);
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}
