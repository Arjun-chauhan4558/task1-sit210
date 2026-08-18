int buttonpin = 4; // digital pin for button in arduino nano
int porchlight = 8; //digital pin  white led(porch light)
int hallwaylight = 9;//digital pin - red led(hallway light)

int delaytime = 3000;// 30 secounds
int buttonstate = 0; 

void setup()
{
  Serial.begin(9600);// use for debuggin and supervising ardunio activity
  Serial.println("The system is ready. ");
  // Initializing component which will be used in the system.
  pinMode(buttonpin,INPUT_PULLUP);// it changes the value of buttonstate to high
  pinMode(porchlight,OUTPUT);
  pinMode(hallwaylight,OUTPUT);
}

  void buttonpressed()
  {
    Serial.println("porch light (white) on");
    
    // porchlight is on 
    digitalWrite(porchlight,HIGH);
    digitalWrite(hallwaylight, HIGH);

    // 30 sec dealy
    delay(delaytime);
    // porchlight goes off
    digitalWrite(porchlight,LOW);
    Serial.println("porch light (white) off");
    // 30 sec more delay
    delay(delaytime);
    // hallwaylight goes off
    digitalWrite(hallwaylight,LOW);
    Serial.println("hallway light (red) off");
  
  }
void loop()
{
  
  buttonstate = digitalRead(buttonpin);
  if(buttonstate == LOW)
  { 
    Serial.println("button pressed, light is on");
    buttonpressed();
    Serial.println("both the light is off ");
  }
}