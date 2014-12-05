
#include <dht.h>

int red = 2;
int green = 3;
int blue = 4;


#define dht_dpin A0 //no ; here. Set equal to channel sensor is on

dht DHT;

void setup(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  digitalWrite( red, HIGH);
  digitalWrite( green, HIGH);
  digitalWrite( blue, HIGH);
  Serial.begin(9600);
  delay(300);//Let system settle
  Serial.println("Humidity and temperature\n\n");
  delay(700);//Wait rest of 1000ms recommended delay before
  //accessing sensor
}//end "setup()"

void loop(){
  //This is the "heart" of the program.
  DHT.read11(dht_dpin);

  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature); 
  Serial.println("C  ");
  delay(1000);//Don't try to access too frequently... in theory
  //should be once per two seconds, fastest,
  //but seems to work after 0.8 second.

  // if it's hot led will turn red
  if (tooHot() == true)

  // if the temperature is good led will turn green
  if (goodTemp() == true)
  {
    greenOn();
  }

  // if it's cold led will turn blue
  if (tooCold() == true)
  {
    blueOn();
  }
}

// end loop()

// rgb led changes to red
void redOn() {
  digitalWrite(red, LOW);  
  hBlink();
  digitalWrite(red, HIGH);   
  dBlink();         
  digitalWrite(blue, HIGH);
  digitalWrite(green, HIGH);
}
// humidity blink
void hBlink (){
  delay(920 - DHT.humidity);
}
//delay blink
void dBlink (){
  delay(1000);
}

// rgb led changes to green
void greenOn() {
  digitalWrite(green, LOW);
  hBlink();
  digitalWrite(green, HIGH);
  dBlink();
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH); 
}

// rgb led changes to red
void blueOn() {
  digitalWrite(blue, LOW);
  hBlink();
  digitalWrite(blue, HIGH);
  dBlink();
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
}

// if hot led changes to red
boolean tooHot() {
  if (DHT.temperature >= 26 ) {
    return true;
  } 
  else {

    return false; 
  }
}
// if a nice work environment temperature, led changes to green
boolean goodTemp() {
  if ( DHT.temperature < 25 && DHT.temperature >= 23){
    return true;
  }
  else {
    return false;
  }
}
// if cold, led changes to blue
boolean tooCold() {
  if ( DHT.temperature <= 23) {
    return true; 
  }
  else {
    return false;
  }

}











