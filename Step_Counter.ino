#include <Arduino_LSM9DS1.h>

#include "IMU.h"
#include "SWAT.h"

// Global Variables

// Acceleration
volatile float Xaxis_accn;
volatile float Yaxix_accn;
volatile float Zaxis_accn;

//Window size
int window_size;

// Sample Frequency
int sample_freq_in_khz;

void setup() {
  Serial.begin(9600);
}

void loop() 
{

}