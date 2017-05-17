/*
*  Autor: Jonas Vieira de Souza
*  Data : 13/09/2016
*/

// -------------------------------------------------------
// Bibliotecas
#include "DHT.h"

// -------------------------------------------------------
// Definições de Projeto
#define DHTPIN 13
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("testando o sensor DHT 22");
  dht.begin();
}

void loop()
{
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t) ) {
    Serial.println("Falha na leitura do sensor!");
  }else{
    Serial.print("Umidade: ");
      Serial.print(h);
      Serial.print(" %\t");
    Serial.print("Temperatura: ");
      Serial.print(t);
      Serial.print(" *C ");
  }

}