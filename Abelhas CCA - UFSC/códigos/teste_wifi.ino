/*
*  Autor: Jonas Vieira de Souza
*  Data : 13/09/2016
*/

// -------------------------------------------------------
// Bibliotecas
#include <ESP8266WiFi.h>

// -------------------------------------------------------
// Definições de Projeto
const char* ssid     = "AP-504";
const char* password = "05051955";
const char* host = "abelhascca.esy.es";
const int httpPort = 80;

// -------------------------------------------------------
// Protótipos de funções
void conectar_wifi(void);
void enviar_novo_pacote(void);

void setup() {
  Serial.begin(115200);
  delay(10);

  conectar_wifi();
}

void loop()
{
  if( WiFi.status() != WL_CONNECTED ){
      conectar_wifi();
  }else{
    enviar_novo_pacote();
  }
  delay(5000);
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

  String url = "/php/post.php";
  url += "?valor_1=";
  url += 1;
  url += "&valor_2=";
  url += 2;

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
