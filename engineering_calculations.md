# Engineering Basis — Heat Load and PCM Sizing (40 L design)

## Assumptions
| Parameter | Value |
| --- | --- |
| Milk volume | 40 L |
| Milk density | 1.03 kg/L → mass ≈ 41 kg |
| Milk specific heat | 3.9 kJ/kg·°C |
| Initial milk temperature | 35 °C (fresh from milking) |
| Target hold temperature | 6 °C (midpoint of 4–8 °C) |
| Ambient (worst case) | 35 °C |
| Hold duration | 10 h |
| Wall U-value (outer HDPE + PUF) | ≈ 0.95 W/m²K |
| Wall surface area | ≈ 0.7 m² |
| Gel-pack latent heat | ≈ 280 kJ/kg |

## Pull-down load (Q1)
Q1 = m · c · ΔT = 41 × 3.9 × (35 − 6) ≈ **4,640 kJ**

## Heat-ingress load (Q2)
Q2 = U · A · ΔT · t = 0.95 × 0.7 × 29 × (10 × 3600 s) ≈ 694 kJ ≈ **695 kJ**
(ΔT taken as 29 K, i.e. 35 °C ambient vs 6 °C hold.)

## Total load and PCM mass
Q = Q1 + Q2 ≈ **5,335 kJ**
PCM mass = Q / 280 ≈ **19 kg** baseline → +15–20 % safety margin → **22–23 kg**

| Circuit | Share | Mass |
| --- | --- | --- |
| Wall layer | ~75 % | ~14 kg |
| Lid + fin | ~25 % | ~5 kg |

## Weight (component estimate, 40 L design)
| Component | kg |
| --- | --- |
| Inner food-grade HDPE shell | 1.5 |
| Outer HDPE shell | 1.5 |
| PUF insulation | 1.8 |
| Reflective foil layer | 0.1 |
| Fin/auger assembly (anodized aluminium) | 0.4 |
| Lid assembly (gaskets + screw mechanism) | 1.0 |
| Base rim (rotating) | 0.8 |
| Handles (2×) | 0.3 |
| Electronics + enclosure | 0.4 |
| Fasteners/seals/misc | 0.2 |
| **Component total** | **≈ 8.0** |

The 10 L prototype measured ≈ 10 kg empty. Loaded weight (40 L design, using the 8 kg estimate) ≈ 8 + 22–23 + 41 ≈ **71–72 kg**.

## Benchmark note
A plain, non-insulated 40 L SS304 can (NDDB specification) weighs 8.2–8.5 kg empty and has no chilling
capability. The fair comparison is a dedicated **insulated SS chiller can** (est. 15–20 kg empty,
₹8,000–15,000+, often quoted "on request").

*Source: NDDB SS milk can specification (rev. May 2009).*

## Limitations
- Steady-state, lumped calculation; no transient or CFD model yet.
- U-value, area and latent heat are estimates; verify by experiment.
- Gel latent heat (~280 kJ/kg) must be confirmed for the actual saline/glycol-tuned formulation (melt point 2–4 °C).
