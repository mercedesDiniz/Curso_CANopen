#include <SPI.h>
#include <mcp2515.h>

#define CS_PIN 53
#define LED_PIN 4
#define COOLER_PIN 7

// Bytes do valor do Trimpo recebido pelo CAN
byte bytes_potValue[2] = {0, 0};

struct can_frame canMsg;
MCP2515 mcp2515(CS_PIN); // Pino CS do Arduino Mega


void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(COOLER_PIN, OUTPUT);
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
  
  Serial.println("------- CAN Read ----------");
  Serial.println("ID  DLC   DATA");
}

void loop() {
  // Filtragem das mensagens recebidas
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK && canMsg.can_id == 0x0F6) {
    Serial.print("ID: ");
    Serial.print(canMsg.can_id, HEX); // print ID
    Serial.print(" ");
    Serial.print("DLC: "); 
    Serial.print(canMsg.can_dlc, HEX); // print DLC
    Serial.print(" ");
    Serial.print("DATA: ");
    Serial.print(" ");
    
    for (int i = 0; i<canMsg.can_dlc; i++)  {  // print the data
      Serial.print(canMsg.data[i],HEX);
      Serial.print(" ");
    }

    Serial.println();  

    // Convertendo os bytes para formar o valor real do trimpot
    bytes_potValue[0] = canMsg.data[0];
    bytes_potValue[1] = canMsg.data[1];

    short potValue = bytes_potValue[0];
    potValue <<= 8;
    potValue += bytes_potValue[1];

    Serial.print("Valor do Trimpot: ");
    Serial.println(potValue);

    // Logica do acionamento do led
    if(canMsg.data[2] == 1){
      digitalWrite(LED_PIN, HIGH);
    }else{
      digitalWrite(LED_PIN, LOW);
    }

    // Logica do acionamento do cooler
    if(potValue > 500){
      digitalWrite(COOLER_PIN, HIGH);
    }else{
      digitalWrite(COOLER_PIN, LOW);
    }
  }
}