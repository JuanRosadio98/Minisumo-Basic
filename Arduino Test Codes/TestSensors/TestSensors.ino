
//LINE SENSORS
#define QTR_1 32
#define QTR_2 35
//PRESENCE SENSORS
#define SENSOR_1 14
#define SENSOR_2 27
#define SENSOR_3 26
#define SENSOR_4 25
#define SENSOR_5 33

//REMOTE CONTROL
#define IR_STAR 15

#define USER_LED 2

//Variables
int s_ii = 0, s_i = 0, s_c = 0, s_d = 0, s_dd = 0;
int qtr_i = 0, qtr_d = 0;
int ir_star = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Sensors_Init();

  pinMode(USER_LED, OUTPUT);
}

void loop() {
  Sensors_Read();

  Serial.print("S_II: ");
  Serial.print(s_ii);
  Serial.print("\t ");
  Serial.print("S_I: ");
  Serial.print(s_i);
  Serial.print("\t ");
  Serial.print("S_C: ");
  Serial.print(s_c);
  Serial.print("\t ");
  Serial.print("S_D: ");
  Serial.print(s_d);
  Serial.print("\t ");
  Serial.print("S_DD: ");
  Serial.print(s_dd);
  Serial.print("\t");

  Serial.print("QTR_I: ");
  Serial.print(qtr_i);
  Serial.print("\t");
  Serial.print("QTR_D: ");
  Serial.print(qtr_d);
  Serial.print("\t");

  Serial.print("IR: ");
  Serial.print(ir_star);
  Serial.println("");

  digitalWrite(USER_LED, !digitalRead(USER_LED));
  delay(200);
}

void Sensors_Read(void) {
  s_ii = digitalRead(SENSOR_1);
  s_i = digitalRead(SENSOR_2);
  s_c = digitalRead(SENSOR_3);
  s_d = digitalRead(SENSOR_4);
  s_dd = digitalRead(SENSOR_5);

  qtr_i = digitalRead(QTR_1);
  qtr_d = digitalRead(QTR_2);

  ir_star = digitalRead(IR_STAR);
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
