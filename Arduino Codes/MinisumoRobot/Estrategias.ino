void Strategy_1(void) {

  Motors_Control(400, -400);
  while (1) {

    Atack();

    /////Verificacion del control de Juez
    if (ctrl_star == 0) {
      while (1) {
        Motors_Control(0, 0);
        Serial.println("Detenido!");
      }
    }
    //////
  }
}

void Strategy_2(void) {
}

void Strategy_3(void) {
}

void Atack(void){
  Sensors_Read();

  if(s_i == 1 && s_c == 0 && s_d == 0){
    Motors_Control(-1023, 1023); 
  }
  else if(s_i == 1 && s_c == 1 && s_d == 0){
    Motors_Control(0, 1023);
  }
  else if(s_i == 0 && s_c == 1 && s_d == 0){
    Motors_Control(1023, 1023);
  }
  else if(s_i == 0 && s_c == 1 && s_d == 1){
    Motors_Control(1023, 0);
  }
  else if(s_i == 0 && s_c == 0 && s_d == 1){
    Motors_Control(1023, -1023); 
  }

}