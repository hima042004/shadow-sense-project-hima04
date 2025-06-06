/*

  Youtube: https://www.instagram.com/voidlooprobotech/
  Website: https://www.voidlooprobo.com
  Twitter: https://twitter.com/SandipRoboTix
  Facebook: https://www.facebook.com/groups/289579082069596/
  Fcebook: https://www.facebook.com/groups/228864595179720/
  Facebook: https://www.facebook.com/groups/2518809408247417/
  Facebook: https://www.facebook.com/groups/voidloop/
  Facebook: https://www.facebook.com/voidlooprobo/
  Instagram: https://www.instagram.com/voidlooprobotech/
  Telegram: https://t.me/voidloopnodemcu
  Telegram: https://t.me/voidlooprobotech
  Whatsapp: https://chat.whatsapp.com/IIyB2IyjyQ71eSfn1jnl3c

*/

#define BLYNK_TEMPLATE_ID "TMPL39h7H2TWh"
#define BLYNK_TEMPLATE_NAME "blind shadow"
#define BLYNK_AUTH_TOKEN "LgiLkz0Z8kgTA68wYb5ggjdK9HceJR0R"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define  trig  D2
#define  echo  D1

long duration;
int distance;

// You should get Auth Token in the Blynk App.

char auth[] = "LgiLkz0Z8kgTA68wYb5ggjdK9HceJR0R";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "int main()";
char pass[] = "INT456789";

BlynkTimer timer;
WidgetLCD lcd(V1);
void setup()
{
  // Debug console
  pinMode(trig, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echo, INPUT);   // Sets the echoPin as an Inpu
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
void sendSensor()
{
  digitalWrite(trig, LOW);   // Makes trigPin low
  delayMicroseconds(2);       // 2 micro second delay

  digitalWrite(trig, HIGH);  // tigPin high
  delayMicroseconds(10);      // trigPin high for 10 micro seconds
  digitalWrite(trig, LOW);   // trigPin low

  duration = pulseIn(echo, HIGH);   //Read echo pin, time in microseconds
  distance = duration * 0.034 / 2;   //Calculating actual/real distance

  Serial.print("Distance = ");        //Output distance on arduino serial monitor
  Serial.println(distance);

  Blynk.virtualWrite(V0, distance);
  
  lcd.print(0, 0, ""); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  lcd.print(0, 1, "Distance: " + String(distance) + "cm  ");
  delay(1000); 

}
