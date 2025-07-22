#include <SPI.h>
#include <mcp2515.h>

uint8_t status = 0;

struct can_frame canMsg1;
struct can_frame canMsg2;
MCP2515 mcp2515(10); // Pino CS do Arduino Uno


void setup() {
  pinMode(7, INPUT_PULLUP);

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

  status = digitalRead(7);
  canMsg1.data[2] = status;
  Serial.print("Status: ")
  Serial.println(status);

  mcp2515.sendMessage(&canMsg1);
  mcp2515.sendMessage(&canMsg2);
  Serial.println("Messages sent");
  
  delay(100);
}
