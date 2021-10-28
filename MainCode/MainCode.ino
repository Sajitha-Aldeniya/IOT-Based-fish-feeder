#define BLYNK_PRINT Serial

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "nEZEX4y0FDheS7JA2Ua3MYXrriZfjgaU";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SLT -BAXTER";
char pass[] = "8920@slt";



//
//const char *ssid     = "SLT -BAXTER";
//const char *password = "8920@slt";



const long utcOffsetInSeconds = 19800;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);



int in1 = 13;
int in2 = 12;
int in3 = 14;
int in4 = 8;
int numRev =  512;

int SensorPin = 5;//5
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.println(pinValue);
  // process received value
}


BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.println(pinValue);
  // process received value
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.println(pinValue);
  // process received value
}












void setup() {

  Serial.begin(115200);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

  Blynk.begin(auth, ssid, pass);

  //  WiFi.begin(ssid, password);
  //
  //  while ( WiFi.status() != WL_CONNECTED ) {
  //    delay ( 500 );
  //    Serial.print ( "." );
  //  }

 timeClient.begin();
}


















void loop() {
timeClient.update();

  Serial.print(daysOfTheWeek[timeClient.getDay()]);
  Serial.print(", ");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.println(timeClient.getSeconds());
  //Serial.println(timeClient.getFormattedTime());


  Blynk.run();

    int i;
    i = 0;
    while (i < 100) {
      onestep(10);
      i++;
    }
  int irSensorVal = digitalRead(SensorPin);
  Serial.println(irSensorVal);
  delay(2000);
  }



void writen(int a, int b, int c, int d) {
  digitalWrite(in1, a);
  digitalWrite(in2, b);
  digitalWrite(in3, c);
  digitalWrite(in4, d);
}

void onestep(int speedIn) {
  if (speedIn != 0) {
    int speedTime = 20 / speedIn;
    //int speedTime = 1;

    writen(1, 0, 0, 1);
    delay(speedTime);
    writen(0, 0, 0, 1);
    delay(speedTime);
    writen(0, 0, 1, 1);
    delay(speedTime);
    writen(0, 0, 1, 0);
    delay(speedTime);
    writen(0, 1, 1, 0);
    delay(speedTime);
    writen(0, 1, 0, 0);
    delay(speedTime);
    writen(1, 1, 0, 0);
    delay(speedTime);
    writen(1, 0, 0, 0);
    delay(speedTime);


  }
}


void moveSlot(int wheelSpeed){
  int slotSteps = 20;
  int speedTime = 20 / wheelSpeed;
  int i = 0;
  
  while(i< slotSteps){

    writen(1, 0, 0, 1);
    delay(speedTime);
    writen(0, 0, 0, 1);
    delay(speedTime);
    writen(0, 0, 1, 1);
    delay(speedTime);
    writen(0, 0, 1, 0);
    delay(speedTime);
    writen(0, 1, 1, 0);
    delay(speedTime);
    writen(0, 1, 0, 0);
    delay(speedTime);
    writen(1, 1, 0, 0);
    delay(speedTime);
    writen(1, 0, 0, 0);
    delay(speedTime);
    
    }
  
  
  
  
  }
