//LIBRERÍA NECESARIA PARA USAR EL SENSOR PZEM004
#include <PZEM004Tv30.h>

//definimos los pines para comunicación serial
#define PZEM_RX_PIN 16
#define PZEM_TX_PIN 17
#define NUM_PZEMS 3
#define PZEM_SERIAL Serial2

//para cada pzem004 se necesita un codigo previo para asignarle una dirección
const uint8_t pzemAdresses[NUM_PZEMS] = {0x02,0x03,0x04};
PZEM004Tv30 pzems[NUM_PZEMS];

void setup() {
  Serial.begin(115200);

  //serial2 para comunicaion con los pzem004
  PZEM_SERIAL.begin(9600, SERIAL_8N1, PZEM_RX_PIN, PZEM_TX_PIN); 

  //verificamos la conexion cada pzem

  for(int i=0; i< NUM_PZEMS; i++){
    pzems[i] = PZEM004Tv30(PZEM_SERIAL,PZEM_RX_PIN,PZEM_TX_PIN,pzemAdresses[i]);
    Serial.print("Verificando PZEM ");
        Serial.print(i);
        Serial.print(" (Addr: 0x");
        Serial.print(pzemAdresses[i], HEX);
        Serial.print(")... ");

        float voltage = pzems[i].voltage();
        if(!isnan(voltage)) {
            Serial.println("OK");
        } else {
            Serial.println("Error de comunicación!");
        }
    }
    Serial.println();
}

void loop() {
  Serial.println("PZEM 01: ");
  //variables 
  float power_pzem01 = pzems[0].power();
  float energy_pzem01 = pzems[0].energy();
  float pf_pzem01 = pzems[0].pf();

  if(!isnan(power_pzem01)) {
        Serial.print("Potencia:   "); Serial.print(power_pzem01, 1); Serial.println(" W");
    } else {
        Serial.println("Error leyendo potencia");
    }
  if(!isnan(energy_pzem01)) {
        Serial.print("Energía:    "); Serial.print(energy_pzem01, 3); Serial.println(" kWh");
    } else {
        Serial.println("Error leyendo energía");
    }
  if(!isnan(pf_pzem01)) {
        Serial.print("Factor P.:  "); Serial.println(pf_pzem01, 2);
    } else {
        Serial.println("Error leyendo factor de potencia");
    }
  Serial.println("-------------------");
//****************************************************************************
  Serial.println("PZEM 02: ");
  //variables 
  float power_pzem02 = pzems[1].power();
  float energy_pzem02 = pzems[1].energy();
  float pf_pzem02 = pzems[1].pf();

  if(!isnan(power_pzem02)) {
        Serial.print("Potencia:   "); Serial.print(power_pzem02, 1); Serial.println(" W");
    } else {
        Serial.println("Error leyendo potencia");
    }
  if(!isnan(energy_pzem02)) {
        Serial.print("Energía:    "); Serial.print(energy_pzem02, 3); Serial.println(" kWh");
    } else {
        Serial.println("Error leyendo energía");
    }
  if(!isnan(pf_pzem02)) {
        Serial.print("Factor P.:  "); Serial.println(pf_pzem02, 2);
    } else {
        Serial.println("Error leyendo factor de potencia");
    }
  Serial.println("-------------------");
  //*****************************************************************************
  Serial.println("PZEM 03: ");
  //variables 
  float power_pzem03 = pzems[0].power();
  float energy_pzem03 = pzems[0].energy();
  float pf_pzem03 = pzems[0].pf();

  if(!isnan(power_pzem03)) {
        Serial.print("Potencia:   "); Serial.print(power_pzem03, 1); Serial.println(" W");
    } else {
        Serial.println("Error leyendo potencia");
    }
  if(!isnan(energy_pzem03)) {
        Serial.print("Energía:    "); Serial.print(energy_pzem03, 3); Serial.println(" kWh");
    } else {
        Serial.println("Error leyendo energía");
    }
  if(!isnan(pf_pzem03)) {
        Serial.print("Factor P.:  "); Serial.println(pf_pzem03, 2);
    } else {
        Serial.println("Error leyendo factor de potencia");
    }
  Serial.println("-------------------");
delay(2000);
}
