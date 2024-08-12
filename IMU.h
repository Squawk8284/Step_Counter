#ifndef _IMU_
#define _IMU_

// Header files

#include "global_variables.h"

#ifdef _cplusplus
extern "C" {
#endif

/**************** FUNCTION DEFINATIONS*************/

int initialise_imu(void);

void stop_imu(void);

void read_accn_data(float *x_axis, float *y_axis, float *z_axis);

float sample_rate_accelerometer(void);



#ifdef _cplusplus
}
#endif



#endif // _IMU_