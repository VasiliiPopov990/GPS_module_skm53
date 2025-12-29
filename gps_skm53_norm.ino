#include <SoftwareSerial.h>
#include <TinyGPS++.h>

SoftwareSerial gpsSerial(4, 3);
TinyGPSPlus gps;

unsigned long lastPrint = 0;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
}

void loop() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (millis() - lastPrint > 1000) {
    lastPrint = millis();

    if (gps.location.isValid()) {
      Serial.print("LAT: ");
      Serial.println(gps.location.lat(), 10);
      Serial.print("LON: ");
      Serial.println(gps.location.lng(), 10);
    } else {
      Serial.println("NO FIX");
    }

    Serial.print("SAT: ");
    Serial.println(gps.satellites.value());

    Serial.print("TIME UTC: ");
    Serial.print(gps.time.hour());
    Serial.print(":");
    Serial.print(gps.time.minute());
    Serial.print(":");
    Serial.println(gps.time.second());

    Serial.print("DATE: ");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.println(gps.date.year());

 
/*
    Serial.print("ALTITUDE: ");
    Serial.print(gps.altitude.meters());   
    
    float LON = gps.location.lng();
    if (0 <= LON < 15) {
      Serial.print("LOCAL TIME (geographically): ");
      Serial.print(gps.time.hour());
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());
    }
    else if (15 <= LON < 30) {
      Serial.print("LOCAL TIME (geographically): ");
      Serial.print(gps.time.hour() + 1);
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());      
    }
    else if (30 <= LON < 45) {
      Serial.print("LOCAL TIME (geographically): ");
      Serial.print(gps.time.hour() + 2);
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());      
    }
    else if (45 <= LON < 60) {
      Serial.print("LOCAL TIME (geographically): ");
      Serial.print(gps.time.hour() + 3);
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());      
    }
    else if (60 <= LON < 75) {
      Serial.print("LOCAL TIME (geographically): ");
      Serial.print(gps.time.hour() + 4);
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());      
    }
    else if (75 <= LON < 90) {
      Serial.print("LOCAL TIME (geographically): ");
      Serial.print(gps.time.hour() + 5);
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());      
    }
    else if (90 <= LON < 105) {
      Serial.print("LOCAL TIME (geographically): ");
      Serial.print(gps.time.hour() + 6);
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());      
    }
    else if (105 <= LON < 120) {
      Serial.print("LOCAL TIME (geographically): ");
      Serial.print(gps.time.hour() + 7);
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());      
    }
    else if (120 <= LON < 135) {
      Serial.print("LOCAL TIME (geographically): ");
      Serial.print(gps.time.hour() + 8);
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());      
    }
    else if (135 <= LON < 150) {
      Serial.print("LOCAL TIME (geographically): ");
      Serial.print(gps.time.hour() + 9);
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());      
    }
    else if (150 <= LON < 165) {
      Serial.print("LOCAL TIME (geographically): ");
      Serial.print(gps.time.hour() + 10);
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());      
    }
    else if (165 <= LON <= 180) {
      Serial.print("LOCAL TIME (geographically): ");
      Serial.print(gps.time.hour() + 1);
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());      
    }
*/

    Serial.println("------");
  }
}
