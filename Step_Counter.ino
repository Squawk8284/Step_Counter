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
float sample_freq_in_hz;

void setup() {
  Serial.begin(9600);
  if(!initialise_imu())
  {
    while(1);
  }
  sample_freq_in_hz = sample_rate_accelerometer();
  window_size = 40;
}

void loop() 
{

}