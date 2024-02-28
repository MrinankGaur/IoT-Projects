// #define BLYNK_TEMPLATE_ID "TMPL3i67qL5je"
// #define BLYNK_TEMPLATE_NAME "DHT11 temp and humidity"
// #define BLYNK_AUTH_TOKEN "X04v1MFj9g_-2YxrlYfrXpUPMre60_gE"
#define BLYNK_TEMPLATE_ID "TMPL3LnQwTfhC"
#define BLYNK_TEMPLATE_NAME "Laila"
#define BLYNK_AUTH_TOKEN "_qSHLODC-iZTnCfr4vFByNmy3gMvmATq"
#define DHTTYPE DHT11

#define BLYNK_PRINT Serial

#include "DHT.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Define the pulse sensor settings
uint8_t DHTPin = 16;

DHT dht(DHTPin, DHTTYPE);
float temp; // temperature sensor value
float hum;

// Your WiFi credentials.
// Set password to "" for open networks.
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Mrinank's Phone";// enter you wifi ssid here
char pass[] = "nhihaipassword";//enter your wifi password here
BlynkTimer timer;

void setup()
 {
  // Start the serial communication
  Serial.begin(115200);
  pinMode(DHTPin,INPUT);

  // Connect to WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Connect to Blynk
  Blynk.begin(auth, ssid, pass);
  while (!Blynk.connected()) {
    Serial.println("Connecting to Blynk...");
    delay(1000);
  }
  Serial.println("Connected to Blynk");

  // Set up the pulse sensor
}

void loop()
 {
  // Read the dht11 sensor value
  temp = dht.readTemperature();
  hum  = dht.readHumidity();
  

    // Send the temp to Blynk
    Blynk.virtualWrite(V0, temp);
    Blynk.virtualWrite(V1, hum);
    delay(200);

    // Print the temperature and humidity on the serial monitor
    String message = "Temperature: " + String(temp) + " C";
    String message1 = "Humidity: " + String(hum);
    Serial.println(message);
    Serial.println(message1);
  

  // Run the Blynk loop
  Blynk.run();
}
