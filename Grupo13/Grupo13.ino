#include <MatrizLed.h>


MatrizLed matriz;


int pot;
int val = -1;
int del = 500;
int pwm = 0;
bool boton = LOW;
String str = "*P1-GRUPO13-SECCION A";

void setup() {
  // put your setup code here, to run once:
  //pines utilizados para la matriz
  matriz.begin(12, 11, 13, 2);
  pinMode(A1, OUTPUT);
  pinMode(10, INPUT);//entrada 1
  pinMode(8, INPUT);//Boton
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);//Potenciometro
  pinMode(10, INPUT);
  pinMode(14, INPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(13, OUTPUT); //prueba de led
  Serial.begin(9600);
}
const char* foo;
void loop() {
  pot = analogRead(A0);
  // digitalWrite(A1, HIGH);
  pot = map(pot, 0, 1023, 1, 6);
  disp();
  boton = digitalRead(8);
  if (boton == LOW) {
    if (digitalRead(10) == HIGH) {
      letra_();
      boton = digitalRead(8);
    } else {
      frase_();
      boton = digitalRead(8);
    }
    boton = digitalRead(8);
  } else {//AQUI IRÍA EL MENSAJE PERSONALIZADO
    digitalWrite(17,boton);
    if (Serial.available()) {
      str = Serial.readString();
      foo = str.c_str();
      Serial.println();
      Serial.println(str);
    }
    matriz.borrar();
    foo = str.c_str();
    boton = HIGH;
    if (digitalRead(14) == HIGH) {//Derecha
      letra_();
    } else {//IZQUIERDA
      frase_();
    }
  }
  /*foo = str.c_str();
    int del = 1000 / pot;
    matriz.escribirFraseScroll(foo, del);*/
  disp();
}

void letra_() {
  int tamano = str.length();
  char aux;
  for (int i = 0; i < tamano; i++) {
    matriz.borrar();
    aux = str[i];
    matriz.escribirCaracter(aux, 0);
    delay_pot();
  }
}

void frase_() {
  matriz.borrar();
  foo = str.c_str();
  int del = 1000 / pot;

  if (digitalRead(14) == LOW) {
    matriz.borrar();
    for (int i = 0; i < 10; i++) {
      matriz.escribirFrase(foo, i); // Texto, posicion en la pantalla
      delay(500);
    }
  } else {
    matriz.escribirFraseScroll(foo, del);
  }
}


void mostrar0() {
  digitalWrite(7, HIGH); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, HIGH); //d
  digitalWrite(3, HIGH); //e
  digitalWrite(2, HIGH); //f
  digitalWrite(9, LOW); //g
}

void mostrar1() {
  digitalWrite(7, LOW); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, LOW); //d
  digitalWrite(3, LOW); //e
  digitalWrite(2, LOW); //f
  digitalWrite(9, LOW); //g
}

void mostrar2() {
  digitalWrite(7, HIGH); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, LOW); //c
  digitalWrite(4, HIGH); //d
  digitalWrite(3, HIGH); //e
  digitalWrite(2, LOW); //f
  digitalWrite(9, HIGH); //g
}

void mostrar3() {
  digitalWrite(7, HIGH); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, HIGH); //d
  digitalWrite(3, LOW); //e
  digitalWrite(2, LOW); //f
  digitalWrite(9, HIGH); //g
}

void mostrar4() {
  digitalWrite(7, LOW); //a
  digitalWrite(6, HIGH); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, LOW); //d
  digitalWrite(3, LOW); //e
  digitalWrite(2, HIGH); //f
  digitalWrite(9, HIGH); //g
}

void mostrar5() {
  digitalWrite(7, HIGH); //a
  digitalWrite(6, LOW); //b
  digitalWrite(5, HIGH); //c
  digitalWrite(4, HIGH); //d
  digitalWrite(3, LOW); //e
  digitalWrite(2, HIGH); //f
  digitalWrite(9, HIGH); //g
}

void delay_pot() {
  int del = 1000 / pot;
  disp();
  delay(del);
}

//este es el definitivo
void disp() {
  if (pot == 1) {
    mostrar1();
  } else if (pot == 2) {
    mostrar2();
  } else if (pot == 3) {
    mostrar3();
  } else if (pot == 4) {
    mostrar4();
  } else {
    mostrar5();
  }
}
