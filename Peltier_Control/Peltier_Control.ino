int i=0;
int counter = 0;
const int buttonHot = 1;
const int buttonCold = 2;

int buttonHotState = 0;
int buttonColdState = 0;
int state = HIGH;
int reading;
int previous = LOW;
long time = 0;
long debounce = 200;

void setup() {          
  // TEC112703  controll pin initiate;
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT); // Speed control
//Enable the Motor Shield output;
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(buttonHot, INPUT);
  pinMode(buttonCold, INPUT);
  digitalWrite(6, HIGH);
  Serial.begin(9600);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
   digitalWrite(12, LOW);
  digitalWrite(13,  LOW);
  Serial.println("Please type either C for cold or H for Hot");
  

}
//4 is HIGH and 5 is LOW == COLD, 4 is LOW and 5 is HIGH == hot

void loop() 
{
 buttonHotState = digitalRead(buttonHot);
 buttonColdState = digitalRead(buttonCold);
 char option;
 
  //if(Serial.available())
//{
  digitalWrite(6, HIGH);
 
  //option = Serial.read();
  if(buttonColdState == HIGH && buttonHotState == LOW)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
   if (counter > 1) //Want it to cool down for 30 secs
  {
   digitalWrite(5, LOW);
   digitalWrite(4, LOW);
   digitalWrite(6, LOW);
   analogWrite(9,0);
   Serial.println ("Allowing peltier to rest for 30 secs");
   delay(30000);
  }
   digitalWrite(6, HIGH);
   delay(2000);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);  // Set the current direction of TEC112703
     for(i=20;i<200;i=i+5)
    {
        analogWrite(9,i);    // set the current of TEC112703
        delay(500);
    }
  }
else
{
   digitalWrite(12, LOW);
   digitalWrite(13,  LOW);
   digitalWrite(5, LOW);
   digitalWrite(4, LOW);
   digitalWrite(6, LOW);
   analogWrite(9,0);

}
  if(buttonHotState == HIGH && buttonColdState == LOW) 
  {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      if (counter > 1)
    {
     digitalWrite(5, LOW);
     digitalWrite(4, LOW);
     digitalWrite(6, LOW);
     analogWrite(9,0);
     Serial.println ("Allowing peltier to rest for 30 secs");
     delay(30000);
    }
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
     digitalWrite(6, HIGH);
     delay(2000);
     digitalWrite(4, LOW);
     digitalWrite(5, HIGH);
     for(i=20;i<200;i=i+5)
    {
        analogWrite(9,i);    // set the current of TEC112703
        delay(500);
    }
  }//
  else
  {
   digitalWrite(12, LOW);
   digitalWrite(13,  LOW);
   digitalWrite(5, LOW);
   digitalWrite(4, LOW);
   digitalWrite(6, LOW);
   analogWrite(9,0);

  }
  
   counter++;
  }
  
//}

