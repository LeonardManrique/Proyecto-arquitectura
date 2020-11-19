#include <NewPing.h>
/*Aqui se configuran los pines donde debemos conectar el sensor*/
#define sensorout1  PB4// Frontal
#define sensorin1  PB3 // Frontal
#define sensorout2 PB6 // Derecho
#define sensorin2  PB5 // Derecho
#define sensorout3 PB1 // Izquierdo
#define sensorin3  PB0 // Izquierdo
#define distancia_maxima 200

/*Crear el objeto (sensores) de la clase NewPing*/
NewPing ultrasonido1(sensorout1, sensorin1, distancia_maxima);
NewPing ultrasonido2(sensorout2, sensorin2, distancia_maxima);
NewPing ultrasonido3(sensorout3, sensorin3, distancia_maxima);

void setup() {
  Serial.begin(9600);
  pinMode(PB9, OUTPUT);//Vibrador frontal
  pinMode(PB14, OUTPUT);//Vibrador izquierdo
  pinMode(PB13, OUTPUT);//Vibrador derecho 
  pinMode(PB8, OUTPUT);//zumbador
}

void loop() {
  // Esperar 1 segundo entre mediciones
  delay(1000);

/************************************ Sensor Frontal***************************************/
  // Obtener medicion de tiempo de viaje del sonido y guardar en variable uS
  int tiempo1 = ultrasonido1.ping_median();
  // Imprimir la distancia medida a la consola serial
  Serial.print("Distancia1: ");
  int distancia1 = tiempo1 / US_ROUNDTRIP_CM;
  // Calcular la distancia con base en una constante
  Serial.print(distancia1);
  Serial.println("cm");
//Activa el zumbador y el vibrador
  if(distancia1<50 && distancia1 != 0){
    digitalWrite(PB9, HIGH);
    digitalWrite(PB8, HIGH);
    
  }else{
    digitalWrite(PB9, LOW);
    digitalWrite(PB8, LOW);
  }

/************************************* Sensor derecho ***************************************/
  int tiempo2 = ultrasonido2.ping_median();
  Serial.print("Distancia2: ");
  int distancia2 = tiempo2 / US_ROUNDTRIP_CM;
  Serial.print(distancia2);
  Serial.println("cm");
  if(distancia2<50 && distancia2 != 0){
    digitalWrite(PB13, HIGH);
    digitalWrite(PB8, HIGH); 
  }else{
    digitalWrite(PB13, LOW);
    digitalWrite(PB8, LOW);
  }

/************************************* Sensor izquierdo ***************************************/

  int tiempo3 = ultrasonido3.ping_median();
  Serial.print("Distancia3: ");
  int distancia3 = tiempo3 / US_ROUNDTRIP_CM;
  Serial.print(distancia3);
  Serial.println("cm");
  if(distancia3<50 && distancia3!= 0){
    digitalWrite(PB14, HIGH);
    digitalWrite(PB8, HIGH); 
  }else{
    digitalWrite(PB14, LOW);
    digitalWrite(PB8, LOW);
  }
}


}
