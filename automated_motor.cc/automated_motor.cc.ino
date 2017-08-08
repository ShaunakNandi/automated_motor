
  const int trigPin_1 = 9;
  const int echoPin_1 = 10;
  const int buzzerPin = 11;
  const int trigPin_2 = 6;
  const int echoPin_2 = 7;

  long duration_1;
  long duration_2;
  int distance_1;
  int distance_2;
  int i=0;
  
void setup() 
{
  // put your setup code here, to run once:
  pinMode(trigPin_1,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(trigPin_2,OUTPUT);
  pinMode(echoPin_1,INPUT);
  pinMode(echoPin_2,INPUT);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin_1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_2,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin_1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_1,LOW);
  
  duration_1 = pulseIn(echoPin_1,HIGH);
  distance_1 = duration_1*0.034/2;
  
  digitalWrite(trigPin_2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_2,LOW);
    
  duration_2 = pulseIn(echoPin_2,HIGH);
  distance_2 = duration_2*0.034/2;
  
  Serial.print("Distance_1: ");
  Serial.print(distance_1);
  Serial.print(" Distance_2: ");
  Serial.println(distance_2);
  if(distance_2<5)
  {
      if(distance_1>5)
      {
         if(distance_1<15 && distance_1>5)
          {
            if(i==0)
            {
              digitalWrite(buzzerPin,LOW);
              delay(1000);
            }
            else
            {
              digitalWrite(buzzerPin,HIGH);
              delay(1000);
            }
          }
        else if(distance_1>15)
        {
          digitalWrite(buzzerPin,HIGH);
          delay(1000);
          i=1;
        }
       }
      if(distance_1<=5)
      {
        digitalWrite(buzzerPin,LOW);
        delay(1000);
        i=0;
      }
  }
  else
  {
    digitalWrite(buzzerPin,LOW);
    delay(1000);
  }
}



