# Prototype Validation — EcoChill-10 (10 L)

A 10 L prototype was built and field-tested. Raw data: [`../data/cooling_validation_log.csv`](../data/cooling_validation_log.csv).

| Elapsed time | Phase | Temperature (°C) |
| --- | --- | --- |
| 0 min | Pull-down | 37.9 |
| 60 min | Pull-down | 19.7 |
| 120 min | Pull-down | 8.7 |
| 180–600 min | Hold (8 h) | 8.7 (stable) |

![Cooling curve](../data/cooling_curve.png)

## Result
- Milk cooled from **37.9 °C to 8.7 °C in 2 hours**.
- It then **held at 8.7 °C for a further 8 hours** with no reheat and no PCM exhaustion observed.
- Prototype measured empty weight ≈ 10 kg; prototype cost ₹5,000.

## Interpretation and limits
- Supports the passive-cooling approach and the general sizing logic used for the 40 L design.
- 8.7 °C is slightly above the 8 °C upper bound of the 4–8 °C target; reaching 4–6 °C is a design goal for the 40 L
  version (higher PCM mass, fin rod) and needs further testing.
- Single test run; test conditions (ambient temperature, gel mass, pack pre-chill temperature) should be recorded
  and repeated runs added for statistical confidence.
