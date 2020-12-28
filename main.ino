unsigned long step_1_time;
int val;
bool flag_1 = false;
bool flag_2 = false;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, 0);
}
void loop()
{
  val = analogRead(A0);
  if ((val > 450) && (flag_1 == 0)){
    step_1_time = millis();
    flag_1 = 1;
    delay(100);
  }
  else if ((val > 500) && (flag_1 == 1))
  {
    unsigned long dt = millis()-step_1_time;
    if ((dt > 240) && (dt < 450))
    {
      delay(100);
      digitalWrite(9, flag_2);
      delay(100);
      flag_2 = !flag_2;
    }
    flag_1 = 0;
  }
}
