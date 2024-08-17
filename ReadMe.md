# Global Variables
Acceleration varaibles

Xaxis_accn
Yaxix_accn
Zaxis_accn

window_size

sample_freq_in_hz

```
// Calculate moving average
  for (int i = 0; i < 3; i++)
  {
    movingAverage[i] -= accelData[i][index1];
    movingAverage[i] += accelData[i][(index1 + window_size - 1) % window_size];
    movingAverage[i] /= window_size;
  }
```

```
// Arrays to store accelerometer data and moving average
float accelData[3][window_size];
float movingAverage[3] = {0, 0, 0};
```