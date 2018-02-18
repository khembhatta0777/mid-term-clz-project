const int ENA = 5; // Port 5: Enable A
const int ENB = 6; // Port 6: Enable B
// IN1: 5v; IN2: GND -> Motor A Direction 1
// IN1: GND; IN2: 5v -> Motor A Direction 2
const int IN1 = 2; 
const int IN2 = 3;
// IN3: 5v; IN4: GND -> Motor B Direction 1
// IN3: GND; IN4: 5V -> Motor B Direction 2
const int IN3 = 4;
const int IN4 = 7;
// PWM
const int PWM255 = 255;
const int PWM128 = 128;

char incomingByte;// assigning char for reading char sed from mobile application

void setup() //initalising the motor
{
 
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);

  // Serial communication
  Serial.begin(9600);
}

void loop() //running something untile it stops
{
  if(Serial.available() > 0)
  {
    //Bluetooth Command
    incomingByte = Serial.read(); //checking what is the incoming byte 
    Serial.println(incomingByte); // printing what it receive 
    switch(incomingByte) // check the value it received and perform what it gets 
    {
      case 'f':
       forward();
       break;
       case 'b':
       reverse();
       break;
       case 'l':
       left( PWM128);
       break;
       case 'r':
       right( PWM128);
       break;
       case 's':
       break;
    }
  }
}
  
void forward() //for moving forward 
{
  analogWrite(ENA, PWM255);
  analogWrite(ENB, PWM255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

 
void reverse() //for moving backward
{
  analogWrite(ENA, PWM255);
  analogWrite(ENB, PWM255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void left(int pwm) //for moving left
{
  analogWrite(ENA, pwm);
  analogWrite(ENB, pwm);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right(int pwm) //for moving right
{
  analogWrite(ENA, pwm);
  analogWrite(ENB, pwm);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Break() //for stopping purpose
{
  analogWrite(ENA, PWM255);
  analogWrite(ENB, PWM255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
}
