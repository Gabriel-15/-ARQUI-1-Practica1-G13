void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);

  pinMode(A0, INPUT);
  Serial1.begin(9600);

}

int val = -1;
int pwm = 0;
void loop() {
  // put your main code here, to run repeatedly:

  /*while(true){
    delay(1000);
    analogWrite(12, pwm);
    pwm++;
    if(pwm==255) pwm=0;
    }*/


  int pot = analogRead(A0);
  pot = map(pot, 0, 1023, 0, 5);

  disp(pot);

}


void mostrar0() {
  digitalWrite(7, HIGH); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, HIGH); //d
  digitalWrite(3, HIGH); //e
  digitalWrite(2, HIGH); //f
  digitalWrite(1, LOW); //g
}

void mostrar1() {
  digitalWrite(7, LOW); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, LOW); //d
  digitalWrite(3, LOW); //e
  digitalWrite(2, LOW); //f
  digitalWrite(1, LOW); //g
}

void mostrar2() {
  digitalWrite(7, HIGH); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, LOW); //c
  digitalWrite(4, HIGH); //d
  digitalWrite(3, HIGH); //e
  digitalWrite(2, LOW); //f
  digitalWrite(1, HIGH); //g
}

void mostrar3() {
  digitalWrite(7, HIGH); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, HIGH); //d
  digitalWrite(3, LOW); //e
  digitalWrite(2, LOW); //f
  digitalWrite(1, HIGH); //g
}

void mostrar4() {
  digitalWrite(7, LOW); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, LOW); //d
  digitalWrite(3, LOW); //e
  digitalWrite(2, HIGH); //f
  digitalWrite(1, HIGH); //g
}

void mostrar5() {
  digitalWrite(7, HIGH); //a
  digitalWrite(6, LOW); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, HIGH); //d
  digitalWrite(3, LOW); //e
  digitalWrite(2, HIGH); //f
  digitalWrite(1, HIGH); //g
}
void mostrar6() {
  digitalWrite(7, HIGH); //a
  digitalWrite(6, LOW); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, HIGH); //d
  digitalWrite(3, HIGH); //e
  digitalWrite(2, HIGH); //f
  digitalWrite(1, HIGH); //g
}

void mostrar7() {
  digitalWrite(7, HIGH); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, LOW); //d
  digitalWrite(3, LOW); //e
  digitalWrite(2, LOW); //f
  digitalWrite(1, HIGH); //g
}
void mostrar8() {
  digitalWrite(7, HIGH); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, HIGH); //d
  digitalWrite(3, HIGH); //e
  digitalWrite(2, HIGH); //f
  digitalWrite(1, HIGH); //g
}


void mostrar9() {
  digitalWrite(7, HIGH); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, LOW); //d
  digitalWrite(3, LOW); //e
  digitalWrite(2, HIGH); //f
  digitalWrite(1, HIGH); //g
}














void disp(int pot) {
  if (pot ==0) {
    mostrar1();
  }else if (pot ==1) {
    mostrar2();
  } else if (pot ==2) {
    mostrar3();
  } else if (pot ==3) {
    mostrar4();
  } else{
    mostrar5();
  } 
}
