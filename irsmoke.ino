#include <IRremote.h>

int RECV_PIN = 11;
int RELAY_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  
  Serial.begin(9600);
  pinMode(RELAY_PIN,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Start Read IR");


}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    if ((results.value) == 1679860800) {
      Serial.println("Power Pressed");
      digitalWrite(RELAY_PIN,HIGH);
      digitalWrite(LED_BUILTIN,HIGH);
      delay(500);
      digitalWrite(RELAY_PIN,LOW);
      digitalWrite(LED_BUILTIN,LOW);
    }
    if ((results.value) == 1679860880) {
      Serial.println("Plasma Pressed");
      digitalWrite(RELAY_PIN,HIGH);
      delay(10000);
      digitalWrite(RELAY_PIN,LOW);
      digitalWrite(LED_BUILTIN,LOW);
    }


    irrecv.resume(); // Receive the next value

    
  }
}
