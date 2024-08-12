#include <Arduino_LSM9DS1.h>

#include "hello.h"

// Global Variables
float Xaxis_accn;
float Yaxix_accn;
float Zaxis_accn;

void setup() {
  Serial.begin(9600);
}

void loop() 
{
  testing();
}