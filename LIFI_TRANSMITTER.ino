const int buzzerPin = 9;
const int fireSensorPin = 8;

char* string = "This is a test transmission";
int string_length;
#define PERIOD 15 // Removed semicolon here

void setup()
{
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(fireSensorPin, INPUT);
  string_length = strlen(string);
}
void loop()
{
  int fireValue = digitalRead(fireSensorPin);
  Serial.println(fireValue);
  if(fireValue == 0)
  {
    digitalWrite(buzzerPin, HIGH);
    for(int i = 0; i < string_length; i ++)
    {
      send_byte(string[i]);
    }
    delay(1000);
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
  }
  delay(500);
}

void send_byte(char my_byte)
{
  digitalWrite(buzzerPin, LOW);
  delay(PERIOD);

  //transmission of bits
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(buzzerPin, (my_byte&(0x01 << i))!=0 );
    delay(PERIOD);
  }

  digitalWrite(buzzerPin, HIGH);
  delay(PERIOD);
}
