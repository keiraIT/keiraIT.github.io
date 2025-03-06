
float duration, distance;
const int trigPin = 9;
const int echoPin = 10;
const int red = 12;
const int yellow = 4; 
const int green = 2; 

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

  if (Serial.available() > 0) {
    String msg = Serial.readStringUntil('\n'); // Read command
    msg.trim(); // Remove any extra spaces or newlines
    
    if (distance < 50) {   //red
      digitalWrite(green, 0);
      digitalWrite(yellow, 0);
      digitalWrite(red, 255);      
    } else if (distance <= 200 && distance >= 50) {   //yellow
      digitalWrite(green, 0);
      digitalWrite(yellow, 255);
      digitalWrite(red, 0);
    } else if (distance > 300) {   //green
      digitalWrite(green, 255);
      digitalWrite(yellow, 0);
      digitalWrite(red, 0);
    } 
    if (msg == "off\n" || msg == "OFF\n" || msg == "off" || msg == "OFF") {
      Serial.println("Person Detected. Turning on light.");   
      digitalWrite(red, 255); // Turn LED  
      digitalWrite(yellow, 0);
      digitalWrite(green, 0); 
    }    
  }

  delay(100);
}