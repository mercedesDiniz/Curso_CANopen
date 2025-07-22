#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(53); // Pino CS do Arduino Mega


void setup() {
  pinMode(4, OUTPUT);
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
    
    if(canMsg.data[2] == 1){
      digitalWrite(4, HIGH);
    }else{
      digitalWrite(4, LOW);
    }
  }
}
