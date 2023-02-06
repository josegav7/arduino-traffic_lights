//Define pins

#define GREEN1 9
#define RED1 10

#define GREEN2 5
#define RED2 6

#define ECHO_PIN1 11
#define TRIG_PIN1 12

#define ECHO_PIN2 2
#define TRIG_PIN2 3


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(RED1,OUTPUT);
  pinMode(GREEN1, OUTPUT);
  digitalWrite(RED1, HIGH);
  digitalWrite(GREEN1, LOW);

  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);


  pinMode(RED2,OUTPUT);
  pinMode(GREEN2, OUTPUT);
  digitalWrite(RED2, LOW);
  digitalWrite(GREEN2, HIGH);

}

float readDistanceCM1() {
  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);
  int duration = pulseIn(ECHO_PIN1, HIGH);
  return duration * 0.034 / 2;
}

float readDistanceCM2() {
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
  int duration = pulseIn(ECHO_PIN2, HIGH);
  return duration * 0.034 / 2;
}

   //define variables
  int red1Value;
  int green1Value;


  //define variables
  int red2Value;
  int green2Value;
  
void loop() {

  
  #define delayTime 5000 //fading time between colors (in ms)
  #define delayTime2 1000


  float distance1 = readDistanceCM1();
  float distance2 = readDistanceCM2();

  bool isNearby1 = distance1 < 3;
  bool isNearby2 = distance2 < 3;

if(isNearby1 == isNearby2){

  red1Value = 200; 
  green1Value = 0;

  red2Value = 200; 
  green2Value = 0;

  analogWrite(RED1, red1Value);
  analogWrite(GREEN1, green1Value);
  analogWrite(RED2, red2Value);
  analogWrite(GREEN2, green2Value);
  delay(delayTime2);


   red1Value = 200; 
  green1Value = 0;

  red2Value = 0; 
  green2Value = 200;
 
  analogWrite(RED1, red1Value);
  analogWrite(GREEN1, green1Value);
  analogWrite(GREEN2, green2Value);
  analogWrite(RED2, red2Value);
  delay(delayTime);

  red1Value = 200; 
  green1Value = 0;

  red2Value = 200; 
  green2Value = 200;


  analogWrite(RED1, red1Value);
  analogWrite(GREEN1, green1Value);
  analogWrite(GREEN2, green2Value);
  analogWrite(RED2, red2Value);
  delay(delayTime2);

   red1Value = 200; 
  green1Value = 0;

  red2Value = 200; 
  green2Value = 0;

  analogWrite(RED1, red1Value);
  analogWrite(GREEN1, green1Value);
  analogWrite(RED2, red2Value);
  analogWrite(GREEN2, green2Value);
  delay(delayTime2);

  red1Value = 0; 
  green1Value = 200;

  red2Value = 200; 
  green2Value = 0;


  analogWrite(RED1, red1Value);
  analogWrite(GREEN1, green1Value);
  analogWrite(RED2, red2Value);
  analogWrite(GREEN2, green2Value);
  delay(delayTime);

  red1Value = 200; 
  green1Value = 200;

  red2Value = 200; 
  green2Value = 0;


  analogWrite(RED1, red1Value);
  analogWrite(GREEN1, green1Value);
  analogWrite(RED2, red2Value);
  analogWrite(GREEN2, green2Value);
  delay(delayTime2);

  isNearby1 = distance1 < 5;
  isNearby2 = distance2 < 5;


}

 if(isNearby1 && !isNearby2)
{
  
  red1Value = 0; 
  green1Value = 200;

  red2Value = 200; 
  green2Value = 0;

  analogWrite(RED1, red1Value);
  analogWrite(GREEN1, green1Value);
  analogWrite(RED2, red2Value);
  analogWrite(GREEN2, green2Value);
  delay(delayTime2);

}

if(!isNearby1 && isNearby2)
{


  red1Value = 200; 
  green1Value = 0;

  red2Value = 0; 
  green2Value = 200;


  analogWrite(RED1, red1Value);
  analogWrite(GREEN1, green1Value);
  analogWrite(RED2, red2Value);
  analogWrite(GREEN2, green2Value);
  delay(delayTime2);

}

}
