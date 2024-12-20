# Step Counter and Stride Length Measurement

This repository provides an implementation for accurately calculating steps and measuring stride length using an accelerometer sensor. The sensor is positioned along the neckband to measure user activity. The solution combines a sliding window averaging algorithm for step detection and an inverted pendulum model for stride length estimation, ensuring precise distance measurement.

---

## Features

- **Step Detection**: 
  - Implements the Sliding Window Averaging Technique (SWAT) to calculate step counts based on acceleration data.
  - Eliminates alignment error and gravity interference using a calibration phase.
  - Uses a threshold-based approach to detect steps, discarding false positives with a time-based filter.

- **Stride Length Measurement**:
  - Utilizes biomechanical models to compute stride length based on vertical displacement of the center of mass (COM).
  - Adapts stride length calculations using anthropometric dimensions for precise results.

---

## Step Calculation

The step detection algorithm uses the SWAT methodology, which processes acceleration data as follows:

1. **Magnitude Calculation**:
   The magnitude of acceleration is computed using the equation:  
   \[
   a_i = \sqrt{a_{x,i}^2 + a_{y,i}^2 + a_{z,i}^2}
   \]

2. **Sliding Window Averaging**:
   A 24-sample overlapping window is applied to calculate the local mean acceleration:
   \[
   \bar{a}_i = \frac{1}{N} \sum_{k=i}^{i+N-1} a_k
   \]
   - Window size: 24 samples (0.2 seconds interval).
   - Sampling frequency: 119 Hz.

3. **Calibration**:
   Users stand still for 10 seconds before starting the walk, during which the alignment error and gravity are subtracted from the mean acceleration.

4. **Threshold Detection**:
   A step is detected if the corrected acceleration exceeds **1.2 m/s²**. Peaks within **0.30 seconds** of a detected step are ignored to prevent false positives.

---

## Stride Length Calculation

Stride length estimation is based on the inverted pendulum biomechanical model, which relates step length to the vertical displacement of the center of mass (COM):

\[
Step\_Length = 2 \times \sqrt{2 \times COM\_Disp \times Leg\_Length - COM\_Disp^2} + (K \times Foot\_Length)
\]

- **COM Displacement**: Referenced from [Saini et al., 1998].
- **Leg Length**: Anthropometric dimensions sourced from [Indian Anthropometric Dimensions by D. Chakrabarti].
- **Proportional Constant (K)**: Calibrated as 0.83.

---

## Usage

1. **Sensor Placement**:
   Attach the accelerometer sensor along the neckband for optimal accuracy.

2. **Calibration**:
   Ensure the user stands still for at least 10 seconds at the start to remove alignment errors and calibrate gravity.

3. **Data Collection**:
   - The sensor records acceleration in the x, y, and z axes at a sampling rate of 119 Hz.
   - Acceleration is processed to compute step count and stride length.

4. **Results**:
   - **Steps**: Total steps detected during activity.
   - **Distance**: Distance traveled based on calculated stride length.

---

## References

1. **Indian Anthropometric Dimensions** by D. Chakrabarti.
2. **Saini, M., Kerrigan, D. C., et al. (1998)**: *The Vertical Displacement of the Center of Mass During Walking*. *Journal of Biomechanical Engineering*, 120(1), 133. [DOI:10.1115/1.2834293](https://doi.org/10.1115/1.2834293)

---

## Contributing

Contributions to improve step detection and stride length estimation are welcome. Please submit a pull request or open an issue for discussion.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
