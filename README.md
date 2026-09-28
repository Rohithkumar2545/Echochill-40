# Hardware

## Layer stack (cylindrical body, outside → inside)
1. Reflective layer — cuts radiative heat gain
2. Outer food-grade HDPE shell — structural, weatherproof
3. PUF insulation (25–40 mm) — cuts conductive heat gain
4. Annular PCM / ice-gel pack layer (top-loading vertical slots) — swappable
5. Inner food-grade HDPE shell — milk contact
6. Milk chamber (40 L)

**Tapered neck** (screw-detachable): reflective + outer HDPE + PUF + inner HDPE — no PCM.

**Lid:** insulated, double-gasket seal, small PCM slot (~5 kg gel), detachable food-grade anodized
aluminium helical fin rod with a thermal buffer sleeve at its base.

**Base:** raised rotating rim (gas-cylinder style); two handles on the cylindrical surface.

## Files
- `BOM.csv` — bill of materials with costs (₹, indicative small-batch estimate; get real supplier quotes).
- *(add)* `cad/` — CAD models (STEP/STL) of shells, lid, fin rod.
- *(add)* `diagrams/exploded_view.png` — exploded-view diagram from the pitch deck.

## Design safeguards
- Gel melting point tuned to 2–4 °C (not 0 °C) to avoid local freezing of milk.
- Buffer/spacer gap between gel packs and the inner wall.
- Smooth, continuous fin profile (no sharp grooves) — CIP-cleanable.
- Double gasket at the fin's lid penetration.
- Cooling is 100 % passive; electronics are a battery-powered optional add-on.
