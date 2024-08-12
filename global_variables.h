#ifndef _GLOBAL_VARIABLES_
#define _GLOBAL_VARIABLES_


// ******** Header files
#include <Arduino.h>

// ******** Variables

// Acceleration
extern volatile float Xaxis_accn;
extern volatile float Yaxix_accn;
extern volatile float Zaxis_accn;


// Window Size
extern int window_size;

// Sampling Frequency
extern float sample_freq_in_hz;


#endif // _GLOBAL_VARIABLES_
