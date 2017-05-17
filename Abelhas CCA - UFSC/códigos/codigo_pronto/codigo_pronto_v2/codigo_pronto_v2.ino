/*
*  Autor: Jonas Vieira de Souza
*  Data : 13/09/2016
*/

// -------------------------------------------------------
// Bibliotecas
#include <ESP8266WiFi.h>
#include "DHT.h"

// -------------------------------------------------------
// Definições de Projeto
const char* ssid     = "ABELHA_MIRIM";
const char* password = "12345678";
const char* host = "52.67.135.7";
const int httpPort = 80;

#define DHTTYPE DHT22

#define CX_1 12 // mudar p/ 4
#define CX_2 13
#define CX_3 14
#define CX_4 1
#define CX_5 4 // mudar p/ 6
#define CX_6 5 // mudar p/ 5

// -------------------------------------------------------
// Protótipos de funções
void conectar_wifi(void);
void iniciar_sensores(void);
void enviar_novo_pacote(void);

DHT dht_1( CX_1, DHTTYPE );
DHT dht_2( CX_2, DHTTYPE );
DHT dht_3( CX_3, DHTTYPE );
DHT dht_4( CX_4, DHTTYPE );
DHT dht_5( CX_5, DHTTYPE );
DHT dht_6( CX_6, DHTTYPE );

void setup() {
  Serial.begin(115200);
  delay(10);

  conectar_wifi();
  iniciar_sensores();
}

void loop()
{
  if( WiFi.status() != WL_CONNECTED ){
      conectar_wifi();
  }else{
    enviar_novo_pacote();
  }
  delay(60000);
}

void conectar_wifi(void){
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Conectado!");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
}

void enviar_novo_pacote(void){
  WiFiClient client;

  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // ---------------------------------------------------
  // Sensor 1

  float h_1 = dht_1.readHumidity();
  float t_1 = dht_1.readTemperature();

  if (isnan(h_1) || isnan(t_1) ) {
    Serial.println("Falha na leitura do sensor!");
    h_1 = -1;
    t_1 = -1;
  }

  // ---------------------------------------------------
  // Sensor 2

  float h_2 = dht_2.readHumidity();
  float t_2 = dht_2.readTemperature();

  if (isnan(h_2) || isnan(t_2) ) {
    Serial.println("Falha na leitura do sensor!");
    h_2 = -1;
    t_2 = -1;
  }

  // ---------------------------------------------------
  // Sensor 3

  float h_3 = dht_3.readHumidity();
  float t_3 = dht_3.readTemperature();

  if (isnan(h_3) || isnan(t_3) ) {
    Serial.println("Falha na leitura do sensor!");
    h_3 = -1;
    t_3 = -1;
  }

  // ---------------------------------------------------
  // Sensor 4

  float h_4 = dht_4.readHumidity();
  float t_4 = dht_4.readTemperature();

  if (isnan(h_4) || isnan(t_4) ) {
    Serial.println("Falha na leitura do sensor!");
    h_4 = -1;
    t_4 = -1;
  }

  // ---------------------------------------------------
  // Sensor 5

  float h_5 = dht_5.readHumidity();
  float t_5 = dht_5.readTemperature();

  if (isnan(h_5) || isnan(t_5) ) {
    Serial.println("Falha na leitura do sensor!");
    h_5 = -1;
    t_5 = -1;
  }

  // ---------------------------------------------------
  // Sensor 6

  float h_6 = dht_6.readHumidity();
  float t_6 = dht_6.readTemperature();

  if (isnan(h_6) || isnan(t_6) ) {
    Serial.println("Falha na leitura do sensor!");
    h_6 = -1;
    t_6 = -1;
  }

  String url = "/abelhas/php/post.php";
  url += "?t1=";
  url += t_1;
  url += "&h1=";
  url += h_1;

  url += "&t2=";
  url += t_2;
  url += "&h2=";
  url += h_2;

  url += "&t3=";
  url += t_3;
  url += "&h3=";
  url += h_3;

  url += "&t4=";
  url += t_4;
  url += "&h4=";
  url += h_4;

  url += "&t5=";
  url += t_5;
  url += "&h5=";
  url += h_5;

  url += "&t6=";
  url += t_6;
  url += "&h6=";
  url += h_6;

  Serial.print("Requesting URL: ");
  Serial.println(url);

  client.print (  String("GET ") +
                  url +
                  " HTTP/1.1\r\n" +
                  "Host: " + host + "\r\n" +
                  "Connection: close\r\n\r\n"
                );

  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
}

void iniciar_sensores(void)
{
  dht_1.begin();
  dht_2.begin();
  dht_3.begin();
  dht_4.begin();
  dht_5.begin();
  dht_6.begin();
}

