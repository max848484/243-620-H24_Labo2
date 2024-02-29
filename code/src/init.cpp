#include "Arduino.h"
#include "init.h"
#include <Wire.h>


// Fonction d'initialisation des GPIO
int initialisationBroches(void)
{

  // Boutons utilisateurs (entrées seulement)
  pinMode(GPIO_B1, INPUT);
  pinMode(GPIO_B2, INPUT);

  // Points de test (entrées seulement)
  pinMode(GPIO_TP1, INPUT);
  pinMode(GPIO_TP1, INPUT);

  // Desactivation des moteurs au démarrage
  pinMode(GPIO_ENABLE_MOTEURS, INPUT);
  digitalWrite(GPIO_ENABLE_MOTEURS, LOW);

  // Moteur droit
  pinMode(GPIO_DIR_D, OUTPUT);
  pinMode(GPIO_STEP_D, OUTPUT);
  pinMode(GPIO_MS1_D, OUTPUT);
  pinMode(GPIO_MS2_D, OUTPUT);
  pinMode(GPIO_MS3_D, OUTPUT);
  digitalWrite(GPIO_DIR_D, LOW);
  digitalWrite(GPIO_MS1_D, LOW);
  digitalWrite(GPIO_MS2_D, LOW);
  digitalWrite(GPIO_MS3_D, LOW);

  // Moteur gauche
  pinMode(GPIO_DIR_G, OUTPUT);
  pinMode(GPIO_STEP_G, OUTPUT);
  pinMode(GPIO_MS1_G, OUTPUT);
  pinMode(GPIO_MS2_G, OUTPUT);
  pinMode(GPIO_MS3_G, OUTPUT);
  digitalWrite(GPIO_DIR_G, LOW);
  digitalWrite(GPIO_MS1_G, LOW);
  digitalWrite(GPIO_MS2_G, LOW);
  digitalWrite(GPIO_MS3_G, LOW);

  // LED
  pinMode(GPIO_DATA_LED, OUTPUT);

  // SPI
  pinMode(GPIO_VPSI_CS1, OUTPUT);
  pinMode(GPIO_VPSI_SCK, OUTPUT);
  pinMode(GPIO_VPSI_MISO, INPUT);
  pinMode(GPIO_VPSI_MOSI, OUTPUT);
  digitalWrite(GPIO_VPSI_CS1, HIGH);

  // I2C
  pinMode(GPIO_I2C_SDA, OUTPUT);
  pinMode(GPIO_I2C_SCL, OUTPUT);

  return 0;
}

// Fonction d'initialisation de l'UART
int initialisationSerie(void)
{
  Serial.begin(115200);
  Serial.setPins(GPIO_UART_RX, GPIO_UART_TX);
  printf("\r\n\r\nRobot Balance code 2024\r\n");
  return 0;
}

// Fonction d'initialisation des DELS
int initialisationsNeoPixel(Adafruit_NeoPixel pixels)
{
  pinMode(GPIO_DATA_LED, OUTPUT);
  pixels.begin();
  pixels.clear();
  pixels.setBrightness(0x22);
  for (int i = 0; i < NEOPIXEL_COUNT; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0x00, 0x00, 0x00));
  }
  pixels.show();
  return 0;
}
