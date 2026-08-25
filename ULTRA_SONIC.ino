int ECHOPIN = 2;  // Sets ECHO channel //
int TRIGPIN = 3;  // Sets TRIGGER channel //

void setup() {
Serial.begin(9600);  // Sets data stream speed from the Arduino Board to the connected Serial Screen //
pinMode(ECHOPIN,INPUT);  // Sets ECHO Channel as Digital Pin (2) for receiving data //
pinMode(TRIGPIN,OUTPUT);  // Sets TRIGGER Channel as Digital Pin (3) for sending data //
}

void loop() {
digitalWrite(TRIGPIN,LOW);  // Sets TRIGGER Channel to 0v for creating a signal //
delayMicroseconds(2);  // 2 MicroSec time delay //
digitalWrite(TRIGPIN,HIGH);  // Sets TRIGGER Channel to 5v for launching a signal //
delayMicroseconds(10);  // 10 MicroSec time delay //
digitalWrite(TRIGPIN,LOW);  // Sets TRIGGER Channel back to 0v in order to turn off the signal //
int distance = pulseIn(ECHOPIN,HIGH);  // Sets a veriable for launched signal pulse in time (MicroSec) as the distance the signal traveled //
distance = distance/58;  // Sets again the same veriable for calculating the distance (cm) //
Serial.println(distance);  // Prints the distance (cm) measured by the Sensor on a connected Serial Screen //
delay(50);  // 50 MicroSec time delay //
}

// *************** This Arduino Project uses an Ultra Sonic sensor for measuring distance (cm)  *************** //
  // ************* /!\ DO NOT ACTIVATE this code if pets are nearby, dogs in particular /!\  **************** //
