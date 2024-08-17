#include <Arduino_LSM9DS1.h>

/* ----------------- Definations ------------------ */

#define THRESHOLD 1.2
#define BAUD_RATE 9600
#define WINDOW_SIZE 24

/* ----------------- Global Variations ------------------ */

// Acceleration
float Xaxis_accn;
float Yaxis_accn;
float Zaxis_accn;

float mag_of_acc;

float acc_buf[WINDOW_SIZE];

float local_mean_acc;

float stand_acc;

// index
int index1;

// Steps
int steps;

// timings
unsigned long prev_start_time;
unsigned long current_false_time;

/* ----------------- SETUP ------------------ */

void setup()
{
  Serial.begin(BAUD_RATE);
  while (!Serial)
    ; // wait till serial initialises
  Serial.println("Started.....");

  if (!IMU.begin())
  {
    Serial.println("FAILED TO INITIALISE IMU!!!!");
    while (1)
      ;
  }

  Serial.print("Acceralation Rate is = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println("Acceleration in m/s"); // Multiple IMU accelaration with '10'

  calibrate();

  // initialise buffer
  for (int i = 0; i < WINDOW_SIZE; i++)
  {
    acc_buf[i] = 0;
  }

  // initialise index
  index1 = 0;

  // intialise steps
  steps = 0;

  // initialise time
  prev_start_time = millis();
  current_false_time = prev_start_time;
}

/* ----------------- LOOP ------------------ */

void loop()
{

  if (IMU.accelerationAvailable())
  {
    IMU.readAcceleration(Xaxis_accn, Yaxis_accn, Zaxis_accn);
    Xaxis_accn *= 10; // Convert to m/s
    Yaxis_accn *= 10; // Convert to m/s
    Zaxis_accn *= 10; // Convert to m/s

    mag_of_acc = sqrt((Xaxis_accn * Xaxis_accn) + (Yaxis_accn * Yaxis_accn) + (Zaxis_accn * Zaxis_accn));

    acc_buf[index1] = mag_of_acc / WINDOW_SIZE;

    local_mean_acc = 0;

    for (int i = 0; i < WINDOW_SIZE; i++)
    {
      local_mean_acc += acc_buf[i];
    }

    local_mean_acc -= stand_acc;

    current_false_time = millis();

    if ((local_mean_acc > THRESHOLD) && ((current_false_time - prev_start_time) > 300))
    {
      steps++;
      prev_start_time = current_false_time;
      Serial.println(steps);
    }

    // increment and reset index
    index1 = (index1 + 1) % WINDOW_SIZE;
  }
}

/* ----------------- FUNCTIONS ------------------ */

void calibrate(void)
{
  float mean = 0;
  int mean_count = 0;
  int cal_index = 0;

  unsigned long start_time, curren_time;

  // initialise buffer
  for (int i = 0; i < WINDOW_SIZE; i++)
  {
    acc_buf[i] = 0;
  }

  Serial.println("Calibrating, Stand still ..........");
  delay(10000);

  start_time = millis();
  curren_time = start_time;

  while ((curren_time - start_time) < 10000)
  {
    if (IMU.accelerationAvailable())
    {
      IMU.readAcceleration(Xaxis_accn, Yaxis_accn, Zaxis_accn);
      Xaxis_accn *= 10; // Convert to m/s
      Yaxis_accn *= 10; // Convert to m/s
      Zaxis_accn *= 10; // Convert to m/s

      mag_of_acc = sqrt((Xaxis_accn * Xaxis_accn) + (Yaxis_accn * Yaxis_accn) + (Zaxis_accn * Zaxis_accn));

      acc_buf[cal_index] = mag_of_acc / WINDOW_SIZE;

      stand_acc = 0;

      for (int i = 0; i < WINDOW_SIZE; i++)
      {
        stand_acc += acc_buf[i];
      }

      mean += stand_acc;
      mean_count++;

      // increment and reset index
      cal_index = (cal_index + 1) % WINDOW_SIZE;
    }

    curren_time = millis();
  }

  stand_acc = mean / mean_count;

  Serial.print("Mean standing acceleration = ");
  Serial.println(stand_acc);
  delay(1000);
  Serial.println("Start Walking.....");
}