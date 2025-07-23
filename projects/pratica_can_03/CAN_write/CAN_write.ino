#include <SPI.h>
#include <mcp2515.h>

#define CS_PIN 10
#define POT_PIN A0
#define CHAV_PIN 7

uint8_t status = 0;  // valores de 0 à 255
int potValue = 0;    // valores de 0 à 1023
uint8_t bH_potValue = 0;  // byte mais significativo
uint8_t bL_potValue = 0;  // byte menos significativo

struct can_frame canMsg1;
struct can_frame canMsg2;
MCP2515 mcp2515(CS_PIN); // Pino CS do Arduino Uno


void setup() {
  pinMode(CHAV_PIN, INPUT_PULLUP);

  canMsg1.can_id  = 0x0F6;
  canMsg1.can_dlc = 8;
  canMsg1.data[0] = 0x0;
  canMsg1.data[1] = 0x0;
  canMsg1.data[2] = 0x0;
  canMsg1.data[3] = 0x0;
  canMsg1.data[4] = 0x0;
  canMsg1.data[5] = 0x0;
  canMsg1.data[6] = 0x0;
  canMsg1.data[7] = 0x0;

  canMsg2.can_id  = 0x036;
  canMsg2.can_dlc = 8;
  canMsg2.data[0] = 0x0;
  canMsg2.data[1] = 0x0;
  canMsg2.data[2] = 0x0;
  canMsg2.data[3] = 0x0;
  canMsg2.data[4] = 0x0;
  canMsg2.data[5] = 0x0;
  canMsg2.data[6] = 0x0;
  canMsg2.data[7] = 0x0;
  
  while (!Serial);
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();
  
  Serial.println("Example: Write to CAN");
}

void loop() {
  status = digitalRead(CHAV_PIN); // Lendo o valor da entrada digital
  
  potValue = analogRead(POT_PIN); // Lendo o valor da entrada analógica
  bH_potValue = highByte(potValue);
  bL_potValue = lowByte(potValue);
  
  // Exibido os dados monitorados
  Serial.print("Status Chave: ");
  Serial.println(status);

  Serial.print("Valor do Trimpot: ");
  Serial.println(potValue);
  Serial.print("Byte High: ");
  Serial.println(bH_potValue);
  Serial.print("Byte LOW: ");
  Serial.println(bL_potValue);

  // Formando o frame de dados
  canMsg1.data[0] = bH_potValue;
  canMsg1.data[1] = bL_potValue;
  canMsg1.data[2] = status;

  // Enviando os frames pelo barramento
  mcp2515.sendMessage(&canMsg1);
  mcp2515.sendMessage(&canMsg2);
  Serial.println("Messages sent");
  
  delay(100);
}
