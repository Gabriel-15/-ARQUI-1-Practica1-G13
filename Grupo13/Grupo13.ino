#include <MatrizLed.h>


MatrizLed matriz;



int val = -1;
int del = 500;
int pwm = 0;
bool boton = LOW;

void setup() {
  // put your setup code here, to run once:
  //pines utilizados para la matriz 
  matriz.begin(12,11,13,2);
  ////////////////////////////////////////////////////////////////////////////// 
  
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
  pinMode(13, OUTPUT); //prueba de led
  Serial1.begin(9600);
}


char c='\0';
String str = "";

void loop() {
  matriz.borrar();
  
  
  // put your main code here, to run repeatedly:

  /*while(true){
    delay(1000);
    analogWrite(12, pwm);
    pwm++;
    if(pwm==255) pwm=0;
    }*/
    int pot = analogRead(A0);
    digitalWrite(A1, HIGH);
    pot = map(pot, 0, 1023, 1, 5);
    disp(pot);
  if (boton == LOW) {
   msgEstatico();
    boton = digitalRead(8);
    
  } else {//AL PRESIONAR EL BOTON SE QUEDARÁ EN EL ELSE
    //AQUI IRÍA EL MENSAJE PERSONALIZADO
    boton=HIGH;
    
  }

  /*delay_pot(pot);
    digitalWrite(A1,LOW);
    delay_pot(pot);*/
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

void delay_pot(int pot) {
  int del = 100 / pot;
  delay(del);
}

//este es el definitivo
void disp(int pot) {
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
//Terminal
void terminal(){
//  if(Serial.available()>0){
//  c=Serial.read();
//  str+=c;
//  }
//  if (c=='\r'){
//    matriz.borrar();
//    
//   matriz.escribirFrase("" ,100);
//    str="";
//   c='\0';
//    }
  
  }
////////MENSAJE ESTATICO
void msgEstatico(){
   matriz.borrar();
   matriz.escribirFrase("*P1 – GRUPO 13 - SECCION A*");
  }
///////////////MENSAJE LETRA
void msgLetraPorLetra(){
  
  
  }
