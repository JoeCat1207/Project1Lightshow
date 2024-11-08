int REDPIN = 8; //LED pins for the tri color LED
int BLUEPIN = 10;
int GREENPIN = 9;

int POTPIN = A5; //Potentiometer pin & Value
int POTVAL = 0;

int redVal = 0; //LED color mixing values
int blueVal = 0;
int grnVal = 0;

int BUTTON_PIN = 7; //Button Pin value
int REDLED = 3; //pin for red led
int YELLOWLED = 4; //pin for yellow led
int REDLEDTWO = 5; //pin for my second red led... why a second one? festivities. 
int GREENLED = 2; // pin for green led

void setup() {
  Serial.begin(9600); //begins serial in case of debugging, I can plug in a serial.Print line that shows me when parts of a code are running.
  pinMode(BLUEPIN, OUTPUT); //These set up *what* the pins do
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(POTPIN, INPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(REDLEDTWO, OUTPUT);
  pinMode(GREENLED, OUTPUT);
}

void loop() {
  float POTVAL = analogRead(POTPIN); //Reads the pot pin
  float EQPOT = POTVAL/1023; //conversion to percentage
  float EQPOT2 = EQPOT*255; //conversion from percentage in the 100's to 255's
  int brightness = EQPOT2; //I copied the code from my last project so I kept both brightness and hue
  int HUE = EQPOT2; 
  int BUTTONREAD = digitalRead(BUTTON_PIN);
  float POTVALADJ = POTVAL; //floating point due to analog nature, theres two of these 'blocks' at the start and end of void loop() to allow the LED to change color every begginning of LED cycle and end of it.
    if (POTVAL < 341){ //When potentiometer is at its lowest value, up till 341, its more red and green

    redVal = 256 - HUE;
    grnVal = HUE;
    blueVal = 1;
  }
  if (1023 > POTVAL > 682){//once we go past 682 but stll below 1023, we mix in more blue and less red

    redVal = 1;
    grnVal = 256 - HUE;
    blueVal = HUE;
  }
  if (POTVAL > 1023){//past 1023, we mix back in the red and include more blue and less green

    redVal = HUE;
    grnVal = 1;
    blueVal = 256 - HUE;
  }
  analogWrite(REDPIN, redVal); //writes the color values to each tri-color LED pin
  analogWrite(BLUEPIN, blueVal);
  analogWrite(GREENPIN, grnVal);

  if(BUTTONREAD == HIGH){ //checks if the button is pressed before starting a LED loop that uses the potentiometer value as a delay
    digitalWrite(GREENLED, HIGH);
    POTVALADJ = analogRead(POTPIN); //each of these analogreads provide updates the delay between each LED blink
    delay(POTVALADJ);
    digitalWrite(GREENLED, LOW);
    digitalWrite(REDLED, HIGH);
    POTVALADJ = analogRead(POTPIN);
    delay(POTVALADJ);
    digitalWrite(REDLED, LOW);
    digitalWrite(YELLOWLED, HIGH);
    POTVALADJ = analogRead(POTPIN);
    delay(POTVALADJ);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(REDLEDTWO, HIGH);
    POTVALADJ = analogRead(POTPIN);
    delay(POTVALADJ);
    digitalWrite(REDLEDTWO, LOW);
  }
  if (POTVAL < 341){ //When potentiometer is at its lowest value, up till 341, its more red and green

    redVal = 256 - HUE;
    grnVal = HUE;
    blueVal = 1;
  }
  if (1023 > POTVAL > 682){ //once we go past 682 but stll below 1023, we mix in more blue and less red

    redVal = 0;
    grnVal = 256 - HUE;
    blueVal = HUE; 
  }
  if (POTVAL > 1023){ //past 1023, we mix back in the red and include more blue and less green

    redVal = HUE;
    grnVal = 1;
    blueVal = 256 - HUE;
  }

  analogWrite(REDPIN, redVal); //These 3 analogWrites set the color mixing values/intensity of each LED in the tricolor LED.
  analogWrite(BLUEPIN, blueVal);
  analogWrite(GREENPIN, grnVal);


}
