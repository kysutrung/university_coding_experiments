#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <Ticker.h>
#include <U8g2lib.h>

const int buttn01 = 12;
const int buttn02 = 14;

// Initialize Pulse Oximeter
PulseOximeter pox;
Ticker timer;

// Initialize OLED display (using U8g2 library)
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

unsigned long measurementStartTime = 0;
bool measuring = false;
float totalHeartRate = 0;
float totalSpO2 = 0;
int measurementCount = 0;
bool displayFinalResult = false;
unsigned long displayStartTime = 0;

// Callback function when a beat is detected
void onBeatDetected() {
    Serial.println("Beat detected!");
}

// Update function called periodically
void update() {
    pox.update();
}

void setup() {
    // Start Serial communication
    Serial.begin(115200);

    // Button
    pinMode(buttn01, INPUT_PULLUP);
    pinMode(buttn02, INPUT_PULLUP);

    // Initialize Pulse Oximeter
    if (!pox.begin()) {
        Serial.println("MAX30100 initialization FAILED");
        for (;;);
    } else {
        Serial.println("MAX30100 initialization SUCCESS");
    }

    // Set IR LED current and callback for beat detection
    pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
    pox.setOnBeatDetectedCallback(onBeatDetected);

    // Start periodic updates every 100ms
    timer.attach_ms(100, update);

    // Initialize the OLED display
    u8g2.begin();
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(10, 30, "Initializing...");
    u8g2.sendBuffer();
    delay(2000);
}

void loop() {
    float heartRate = pox.getHeartRate();
    float spO2 = pox.getSpO2();
    int butState01 = digitalRead(buttn01);
    int butState02 = digitalRead(buttn02);

    if (heartRate > 0 && spO2 > 0 && !measuring && !displayFinalResult) {
        // Start measurement process
        measuring = true;
        measurementStartTime = millis();
        totalHeartRate = 0;
        totalSpO2 = 0;
        measurementCount = 0;
    }

    if (measuring) {
        // Accumulate data
        totalHeartRate += heartRate;
        totalSpO2 += spO2;
        measurementCount++;

        // Check if 2 seconds have passed
        if (millis() - measurementStartTime >= 2000) {
            // Calculate average values
            float avgHeartRate = totalHeartRate / measurementCount;
            float avgSpO2 = totalSpO2 / measurementCount;

            // Prepare to display final results
            u8g2.clearBuffer();
            u8g2.setFont(u8g2_font_ncenB08_tr);

            char buffer[32];
            snprintf(buffer, sizeof(buffer), "HeartR: %.0f bpm", avgHeartRate);
            u8g2.drawStr(5, 20, buffer);

            snprintf(buffer, sizeof(buffer), "SpO2  : %.1f %%", avgSpO2);
            u8g2.drawStr(5, 40, buffer);

            if(butState01 == 0 && butState02 == 1){
              if(avgHeartRate >= 60 && avgSpO2 >= 95){
                snprintf(buffer, sizeof(buffer), "Normal");
                u8g2.drawStr(5, 60, buffer);
              }
              else{
                snprintf(buffer, sizeof(buffer), "Not Normal");
                u8g2.drawStr(5, 60, buffer);
              }
              if(avgHeartRate < 40 || avgSpO2 < 90){
                snprintf(buffer, sizeof(buffer), "Danger");
                u8g2.drawStr(5, 60, buffer);
              }              
            }

            if(butState01 == 1 && butState02 == 0){
              if(avgHeartRate >= 70 && avgSpO2 >= 95){
                snprintf(buffer, sizeof(buffer), "Normal");
                u8g2.drawStr(5, 60, buffer);
              }
              else{
                snprintf(buffer, sizeof(buffer), "Not Normal");
                u8g2.drawStr(5, 60, buffer);
              }
              if(avgHeartRate < 40 || avgSpO2 < 90){
                snprintf(buffer, sizeof(buffer), "Danger");
                u8g2.drawStr(5, 60, buffer);
              } 
            }

            u8g2.sendBuffer();

            displayFinalResult = true;
            displayStartTime = millis();
            measuring = false;
        } else {
            // Display "waiting" message during measurement
            u8g2.clearBuffer();
            u8g2.setFont(u8g2_font_ncenB08_tr);
            u8g2.drawStr(10, 30, "Waiting...");
            u8g2.sendBuffer();
        }
    }

    if (displayFinalResult) {
        // Display the final result for 5 seconds
        if (millis() - displayStartTime >= 5000) {
            displayFinalResult = false;
        }
    } else if (heartRate == 0 || spO2 == 0) {
        // Prompt user to place finger
        u8g2.clearBuffer();
        u8g2.setFont(u8g2_font_ncenB08_tr);
        u8g2.drawStr(10, 30, "Place a finger ---->");
        u8g2.sendBuffer();
    }
}
