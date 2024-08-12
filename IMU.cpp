#include "IMU.h"

#include <Arduino_LSM9DS1.h>


/**
 * @brief Initialise the IMU for read acceleration, gyroscope and magnetometer values
 * 
 * 
 * @return int success =1
 *    failure =0 
 */
int initialise_imu(void)
{
  int success=0;
  if (!IMU.begin())
  {
    Serial.println("Failed to initialise IMU");
    success = 1;
  }

  return success;
}


/**
 * @brief Stop IMU reading and de-initialise
 * 
 */
void stop_imu(void)
{
  Serial.println("Deintialise IMU");
}

/**
 * @brief Read accn data into three variables.
 * 
 * @param x_axis float: x-axis
 * @param y_axis float: y-axis
 * @param z_axis float: z-axis
 */
void read_accn_data(float *x_axis, float *y_axis, float *z_axis)
{
  if (IMU.accelerationAvailable())
  {
    IMU.readAcceleration(*x_axis,*y_axis,*z_axis); // address of variable of calling function.
  }
}

/**
 * @brief Returns the sampling rate for accelerometer
 * 
 * @return float sample rate in Hz
 */
float sample_rate_accelerometer(void)
{
  return IMU.accelerationSampleRate();
}