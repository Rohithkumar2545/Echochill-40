# ECO CHILL 40
## Development of a Low-Cost, Lightweight Milk Chilling Can for Small-Scale Dairy Farmers

**Problem Statement ID:** SIH26110 · **Organisation:** Ministry of Fisheries, Animal Husbandry & Dairying
**Department:** Department of Animal Husbandry & Dairying · **Category:** Hardware · **Theme:** Agriculture, FoodTech & Rural Development
**Team:** LactroniX (ID 149261)

---

## 1. Executive Summary
ECO CHILL 40 is a 40-litre, electricity-free, passive milk chilling can for small and marginal dairy farmers in remote, hilly and
North-Eastern regions where reliable refrigeration and electricity are unavailable. It replaces heavy, expensive stainless-steel
chilling containers with a lightweight insulated design built around a swappable dual phase-change-material (PCM) cooling system,
designed to hold 40 litres of milk in the safe range for 6–12 hours without external power.

## 2. Background and Problem Statement
Milk is highly perishable and begins deteriorating within hours of milking due to bacterial growth and enzymatic activity. In hilly
and North-Eastern dairy regions, farmers lack bulk milk coolers and consistent electricity, so milk often sits at ambient temperature
for hours before reaching collection centres, causing quality loss, reduced shelf life and economic damage to small farmers. Existing
chilling solutions (insulated stainless-steel cans) are heavy, expensive and impractical for daily individual use and transport.

## 3. Proposed Solution Overview
- Lightweight food-grade HDPE construction instead of stainless steel
- Dual-layer insulation (PUF + reflective foil) to minimise ambient heat gain
- **Swappable ice-gel PCM system** — only the gel packs are exchanged, not the whole can
- Passive **helical fin / auger rod** for internal heat distribution with no pump or motor
- **Optional** low-cost smart monitoring add-on (temperature + spoilage-risk indication)
- **Optional** pre-cooling protocol using locally available natural water

## 4. Detailed Design
**Cylindrical body (outside → inside):** reflective layer → outer food-grade HDPE shell → PUF insulation (25–40 mm) →
annular PCM/gel-pack layer (top-loading vertical slots) → inner food-grade HDPE shell → milk chamber (40 L).

**Tapered neck:** reflective + outer HDPE + PUF + inner HDPE only (no PCM); screw-detachable for manufacturing and maintenance.

**Lid assembly:** insulated, double-gasket leak-proof seal; small dedicated PCM slot; detachable food-grade anodized-aluminium
helical fin rod extending into the milk, with a thermal buffer sleeve at its base to prevent localised freezing.

**Base:** raised rotating rim (gas-cylinder style) for tilt-and-roll transport; two carrying handles on the cylindrical body.

**Optional smart monitoring (lid-mounted, IP65/67):** IR temperature sensor + MQ-135 gas sensor (VOC-based spoilage-risk proxy,
not a bacterial count) + Arduino Nano + three-colour LED indicator. Battery-powered and independent of the passive cooling.

## 5. Working Principle
- **Wall PCM jacket:** large-surface-area passive buffer giving slow, steady bulk cooling.
- **Lid PCM + fin/auger:** pulls heat from the milk's core/top toward the lid, countering thermal stratification, with no moving parts.

Both PCM sets follow a **daily swap model**: farmers exchange discharged packs for pre-charged ones at the village collection centre.

**Sensor logic:** IR temperature and MQ-135 readings feed the microcontroller, which compares them with preset thresholds
(temperature ≤ 8 °C, gas ≤ calibrated threshold). Green = safe, Yellow = warning, Red = alert. See [`../firmware/`](../firmware/).

## 6. Engineering Basis — Heat Load and PCM Sizing
Q1 (pull-down) ≈ 4,640 kJ; Q2 (ingress) ≈ 695 kJ; total ≈ 5,335 kJ. At ~280 kJ/kg latent heat, PCM ≈ 19 kg baseline →
**22–23 kg** with 15–20 % margin (≈75 % wall / 25 % lid). Full working in
[`engineering_calculations.md`](engineering_calculations.md).

## 7. Prototype Validation (Primary Data)
10 L prototype (EcoChill-10): **37.9 °C → 8.7 °C in 2 h**, then **held at 8.7 °C for 8 h** with no reheat or PCM exhaustion.

| Elapsed time | Phase | Temp (°C) |
| --- | --- | --- |
| 0 min | Pull-down | 37.9 |
| 60 min | Pull-down | 19.7 |
| 120 min | Pull-down | 8.7 |
| 180–600 min | Hold | 8.7 (stable) |

Details: [`prototype_validation.md`](prototype_validation.md).

## 8. Weight Analysis
Component estimate for the 40 L design ≈ 8.0 kg (see [`engineering_calculations.md`](engineering_calculations.md)); the 10 L prototype
measured ≈ 10 kg empty. A plain non-insulated 40 L SS304 can (NDDB spec) weighs 8.2–8.5 kg but cannot chill; the fair benchmark is an
**insulated SS chiller can** at an estimated 15–20 kg empty.

## 9. Cost Analysis (indicative, per unit)
| Item | Cost (₹) |
| --- | --- |
| Structure subtotal | ≈ 2,430 |
| Electronics subtotal (optional) | ≈ 1,880 |
| Assembly/labour | 600 |
| **Passive-only unit** | **≈ 3,030** |
| **Smart unit (with electronics)** | **≈ 4,910** |
| **Measured prototype cost** | **₹5,000** (vs ₹7,000 conventional SS can — ~28.5 % lower) |

Gel pack set (reusable capital): 22–23 kg @ ₹150–200/kg ≈ ₹3,300–4,600 one-time. Recharging electricity is centralised at the
collection centre and shared across many units. Line items: [`../hardware/BOM.csv`](../hardware/BOM.csv).

## 10. Optional Enhancement: Pre-Cooling with Natural Water
Estimated PCM reduction with a 10-min dip (ε ≈ 0.5): summer ~15 kg (~22 %), monsoon ~17.6 kg (~7.5 %), winter ~13.3 kg (~30 %).
Strictly optional; default sizing assumes none. Field validation pending. See [`pre_cooling_analysis.md`](pre_cooling_analysis.md).

## 11. Design Safeguards
- PCM/gel melting point tuned to 2–4 °C (not 0 °C) to avoid localised freezing and protein/fat damage
- Buffer/spacer gap between gel packs and inner wall
- Smooth, continuous fin geometry (no sharp grooves) for CIP-friendly cleaning
- Double-gasket sealing at the fin's lid penetration
- Sensors are a monitoring convenience; cooling stays 100 % passive

## 12. Comparative Advantage
| Parameter | ECO CHILL 40 | Insulated SS chiller can (typical) |
| --- | --- | --- |
| Empty weight | ~10 kg (prototype measured) | ~15–20 kg |
| Power requirement | None (passive) | None, but bulkier insulation |
| Cost | ~₹5,000 (+ reusable gel packs) | ₹8,000–15,000+ |
| Cooling recharge | Daily swap at collection centre | Ice added manually, less controlled |
| Monitoring | Real-time temperature + spoilage-risk alert | None |
| Field validation | 8.7 °C held for 8+ h | — |

## 13. Feasibility, Challenges and Mitigation
**Feasibility:** readily available HDPE, PUF, gel packs and low-cost sensors; ~28.5 % cheaper than SS cans; no continuous electricity; modular and reusable.
**Challenges:** seasonal ambient variation; temperature gradients in the milk; gas-sensor accuracy vs milk composition; long-term seal/sensor durability.
**Mitigation:** climatic-chamber testing; CFD/thermal analysis for fin design; calibrated prediction model from lab milk-quality data; accelerated durability and field trials.

## 14. Scalability and Deployment Model
The daily gel-pack swap centralises refrigeration at the village collection centre, cutting the number of refrigeration points needed
by an order of magnitude versus farm-level cooling, and fits existing cooperative logistics.
- **Phase 1:** pilot with 1 cooperative collection centre (50–100 farmers)
- **Phase 2:** district-level rollout via NDDB-affiliated milk unions
- **Phase 3:** state-level deployment on existing cooperative collection routes

## 15. Impact and Benefits
**Social:** reliable rural collection option; visual quality-status indicators; livelihood security.
**Economic:** lower cold-chain expenditure; more saleable milk; longer saleable window.
**Environmental:** less food waste; better resource utilisation; reusable components.
**SDGs:** 2 (Zero Hunger), 9 (Industry, Innovation & Infrastructure), 12 (Responsible Consumption & Production), 15 (Life on Land).

## 16. Future Scope
- IoT-enabled variant for collection-centre fleet monitoring
- Solar-assisted hybrid gel-pack charging at off-grid centres
- Standardised cartridge sizing across manufacturers

## 17. Conclusion
ECO CHILL 40 offers a lightweight, low-cost, electricity-independent answer to milk spoilage in remote dairy regions, combining passive
dual-PCM cooling, a centralised swap-based logistics model, and optional enhancements (smart monitoring, natural-water pre-cooling) that add
value without creating dependencies. The design rests on explicit heat-load calculations and material choices that address dairy-science and
food-safety concerns.
