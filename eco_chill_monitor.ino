/*
 * ECO CHILL 40 - optional smart monitoring add-on
 * ------------------------------------------------
 * Reads an MLX90614 IR temperature sensor and an MQ-135 gas sensor, and shows a
 * Green / Yellow / Red status on three LEDs. Cooling itself is 100% passive; this
 * unit only reports status.
 *
 * Board : Arduino Nano (ATmega328P)
 * Libs  : Adafruit MLX90614 Library (+ Adafruit BusIO)
 *
 * STATUS: reference sketch written from the project documentation. Pin numbers and gas
 * thresholds are placeholders - verify on your hardware and calibrate the MQ-135
 * (see firmware/README.md) before relying on any reading.
 *
 * NOTE: the MQ-135 gives a VOC-based spoilage-RISK proxy. It is NOT a bacterial-count
 * measurement.
 */

#include <Wire.h>
#include <Adafruit_MLX90614.h>

// ---------- Pins (change to match your wiring) ----------
const uint8_t PIN_MQ135 = A0;   // MQ-135 analog output
const uint8_t PIN_LED_G = 5;    // Green LED  (safe)
const uint8_t PIN_LED_Y = 6;    // Yellow LED (warning)
const uint8_t PIN_LED_R = 7;    // Red LED    (alert)
// MLX90614 uses I2C: SDA = A4, SCL = A5 on the Nano

// ---------- Thresholds ----------
const float TEMP_GREEN_MAX_C = 8.0;    // <= 8 C  -> safe (SIH: 4-8 C range)
const float TEMP_RED_MIN_C   = 10.0;   // >  10 C -> alert. 8-10 C -> warning.

// MQ-135 raw ADC (0-1023). PLACEHOLDERS: measure clean-air baseline and fresh-milk
// readings on your unit, then set these.
const int GAS_WARN_RAW  = 350;
const int GAS_ALERT_RAW = 500;

// ---------- Timing ----------
const unsigned long SAMPLE_INTERVAL_MS = 2000;
const unsigned long MQ135_WARMUP_MS    = 60000UL;  // warm-up; real burn-in takes longer
const uint8_t       N_SAMPLES          = 8;        // averaging

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
unsigned long lastSample = 0;
bool sensorOk = false;

enum Level : uint8_t { LEVEL_OK = 0, LEVEL_WARN = 1, LEVEL_ALERT = 2 };

void setLeds(bool g, bool y, bool r) {
  digitalWrite(PIN_LED_G, g);
  digitalWrite(PIN_LED_Y, y);
  digitalWrite(PIN_LED_R, r);
}

Level tempLevel(float t) {
  if (t <= TEMP_GREEN_MAX_C) return LEVEL_OK;
  if (t <= TEMP_RED_MIN_C)   return LEVEL_WARN;
  return LEVEL_ALERT;
}

Level gasLevel(int raw) {
  if (raw <= GAS_WARN_RAW)  return LEVEL_OK;
  if (raw <= GAS_ALERT_RAW) return LEVEL_WARN;
  return LEVEL_ALERT;
}

int readGasAveraged() {
  long sum = 0;
  for (uint8_t i = 0; i < N_SAMPLES; i++) {
    sum += analogRead(PIN_MQ135);
    delay(10);
  }
  return (int)(sum / N_SAMPLES);
}

float readTempAveraged() {
  float sum = 0;
  uint8_t good = 0;
  for (uint8_t i = 0; i < N_SAMPLES; i++) {
    float t = mlx.readObjectTempC();
    if (!isnan(t)) { sum += t; good++; }
    delay(20);
  }
  return good ? sum / good : NAN;
}

void blinkFault() {           // all LEDs blink = sensor fault
  static bool on = false;
  on = !on;
  setLeds(on, on, on);
}

void setup() {
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_Y, OUTPUT);
  pinMode(PIN_LED_R, OUTPUT);
  Serial.begin(9600);

  sensorOk = mlx.begin();
  Serial.println(F("ms,temp_c,gas_raw,status"));   // CSV header for data logging

  // Warm-up indicator: yellow on while the MQ-135 heats up
  setLeds(false, true, false);
  delay(MQ135_WARMUP_MS);
}

void loop() {
  if (millis() - lastSample < SAMPLE_INTERVAL_MS) return;
  lastSample = millis();

  if (!sensorOk) {            // try to recover from a missing MLX90614
    sensorOk = mlx.begin();
    blinkFault();
    Serial.println(F("FAULT: MLX90614 not found"));
    return;
  }

  float t = readTempAveraged();
  int gas = readGasAveraged();

  if (isnan(t)) {
    blinkFault();
    Serial.println(F("FAULT: invalid temperature reading"));
    return;
  }

  // Combined status = worst of temperature and gas levels
  Level lvl = max(tempLevel(t), gasLevel(gas));

  switch (lvl) {
    case LEVEL_OK:    setLeds(true,  false, false); break;
    case LEVEL_WARN:  setLeds(false, true,  false); break;
    case LEVEL_ALERT: setLeds(false, false, true ); break;
  }

  Serial.print(millis());  Serial.print(',');
  Serial.print(t, 1);      Serial.print(',');
  Serial.print(gas);       Serial.print(',');
  Serial.println(lvl == LEVEL_OK ? F("GREEN") : lvl == LEVEL_WARN ? F("YELLOW") : F("RED"));
}
