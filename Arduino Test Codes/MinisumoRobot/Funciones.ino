void Sensors_Read(void) {
  s_ii = digitalRead(SENSOR_1);
  s_i = digitalRead(SENSOR_2);
  s_c = digitalRead(SENSOR_3);
  s_d = digitalRead(SENSOR_4);
  s_dd = digitalRead(SENSOR_5);

  qtr_i = digitalRead(QTR_1);
  qtr_d = digitalRead(QTR_2);

  ctrl_star = digitalRead(IR_STAR);
}

void Sensors_Init(void) {
  pinMode(SENSOR_1, INPUT);
  pinMode(SENSOR_2, INPUT);
  pinMode(SENSOR_3, INPUT);
  pinMode(SENSOR_4, INPUT);
  pinMode(SENSOR_5, INPUT);

  pinMode(QTR_1, INPUT);
  pinMode(QTR_2, INPUT);

  pinMode(IR_STAR, INPUT);
}

void Push_Init(void){
  pinMode(PUSH_1, INPUT);
  pinMode(PUSH_2, INPUT);
  pinMode(PUSH_3, INPUT);
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