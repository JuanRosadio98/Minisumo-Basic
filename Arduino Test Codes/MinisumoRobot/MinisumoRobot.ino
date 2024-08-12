#define PUSH_1 36
#define PUSH_2 39
#define PUSH_3 34
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

//MOTOR DRIVER
#define MOTOR_PWMA 4
#define MOTOR_INA1 17
#define MOTOR_INA2 16

#define MOTOR_PWMB 23
#define MOTOR_INB1 18
#define MOTOR_INB2 19

#define TmCh_PWMA 0
#define TmCh_PWMB 1

int s_ii, s_i, s_c, s_d, s_dd, qtr_i, qtr_d, ctrl_star;
int strategy = 0;

void Push_Init(void);
void Motors_Init(void);
void Sensors_Init(void);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Push_Init();
  Motors_Init();
  Sensors_Init();
  digitalWrite(USER_LED, LOW);

  Serial.println("Seleccione Estrategia(1-3): ");
  while (1) {
    if (digitalRead(PUSH_1) == 1) {
      digitalWrite(USER_LED, HIGH);
      while (1) {
        if (digitalRead(PUSH_1) == 0) {
          strategy++;
          digitalWrite(USER_LED, LOW);
          Serial.println(strategy);
          break;
        }
      }
    }

    if (digitalRead(PUSH_2) == 1 && strategy > 0) {
      digitalWrite(USER_LED, HIGH);
      while (1) {
        if (digitalRead(PUSH_2) == 0) {
          strategy--;
          digitalWrite(USER_LED, LOW);
          Serial.println(strategy);
          break;
        }
      }
    }

    if (digitalRead(PUSH_3) == 1) {
      while (1) {
        if (digitalRead(PUSH_3) == 0) {
          for (int i = 0; i < strategy; i++) {
            digitalWrite(USER_LED, HIGH);
            delay(500);
            digitalWrite(USER_LED, LOW);
            delay(400);
          }
          break;
        }
      }
      break;
    }
  }
  Serial.print("Strategy selected: ");
  Serial.println(strategy);

  while (ctrl_star == 0) {
    digitalWrite(USER_LED, HIGH);
    delay(100);
    digitalWrite(USER_LED, LOW);
    delay(100);
    Sensors_Read();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (strategy) {
    case 1:
      Strategy_1();
      break;

    case 2:
      Strategy_2();
      break;

    case 3:
      Strategy_3();
      break;

    default:
      break;
  }
}
