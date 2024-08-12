#ifndef _IMU_
#define _IMU_

// Header files

#include "global_variables.h"

#ifdef _cplusplus
extern "C" {
#endif

/ **************** FUNCTION DEFINATIONS*************/

void initialise_imu(void);

void read_accn_data(float *Xaxis_accn, float *Yaxix_accn, float *Zaxis_accn);



#ifdef _cplusplus
}
#endif



#endif // _IMU_