//MOTOR DRIVER
#define MOTOR_PWMA 4
#define MOTOR_INA1 17
#define MOTOR_INA2 16

#define MOTOR_PWMB 23
#define MOTOR_INB1 18
#define MOTOR_INB2 19

#define TmCh_PWMA 0
#define TmCh_PWMB 1

void setup() {
  // put your setup code here, to run once:
  Motors_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  Motors_Control(200, 200); //-1023 a 1023
  delay(1000);
  Motors_Control(0, 0);
  delay(1000);
  Motors_Control(-200, -200);
  delay(1000);
}

void Motors_Init(void)
{
  //Canal del Timer, Freq, Resolution
  ledcSetup(TmCh_PWMA, 10000, 10);
  ledcSetup(TmCh_PWMB, 10000, 10);
  //Pin, Canal del Timer
  ledcAttachPin(MOTOR_PWMA, TmCh_PWMA);
  ledcAttachPin(MOTOR_PWMB, TmCh_PWMB);

  pinMode(MOTOR_INA1, OUTPUT);
  pinMode(MOTOR_INA2, OUTPUT);
  pinMode(MOTOR_INB1, OUTPUT);
  pinMode(MOTOR_INB2, OUTPUT);

  digitalWrite(MOTOR_INA1, LOW);
  digitalWrite(MOTOR_INA2, LOW);
  digitalWrite(MOTOR_INB1, LOW);
  digitalWrite(MOTOR_INB2, LOW);

}

void Motors_Control(int pwmA, int pwmB)
{
  if (pwmA >= 0)
  {
    ledcWrite(TmCh_PWMA, pwmA);
    digitalWrite(MOTOR_INA1, LOW);
    digitalWrite(MOTOR_INA2, HIGH);
  }
  else
  {
    pwmA = pwmA * -1;
    ledcWrite(TmCh_PWMA, pwmA);
    digitalWrite(MOTOR_INA1, HIGH);
    digitalWrite(MOTOR_INA2, LOW);
  }

  if (pwmB >= 0)
  {
    ledcWrite(TmCh_PWMB, pwmB);
    digitalWrite(MOTOR_INB1, LOW);
    digitalWrite(MOTOR_INB2, HIGH);
  }
  else
  {
    pwmB = pwmB * -1;
    ledcWrite(TmCh_PWMB, pwmB);
    digitalWrite(MOTOR_INB1, HIGH);
    digitalWrite(MOTOR_INB2, LOW);
  }
}
