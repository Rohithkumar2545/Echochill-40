# Optional Enhancement — Natural-Water Pre-Cooling

**Status: optional.** The can's default PCM sizing assumes *no* pre-cooling. Pre-cooling is a bonus
(more hold time, or a lighter gel load where water is easy to reach).

## Idea
Farmers in the target regions already dip freshly milked containers in local water. Doing this for
~10 minutes before filling the can lowers the milk's starting temperature and so reduces the pull-down
load **Q1** (the ambient ingress load Q2 is unchanged).

## Model
Partial heat exchange with effectiveness ε (fraction of the milk–water temperature gap closed in 10 min).
Moderate scenario ε = 0.5, milk starts at 35 °C, water temperature ≈ seasonal ambient.

| Season | Water temp | Milk after dip | Q1 saved | PCM saved | PCM needed | Reduction vs 19 kg |
| --- | --- | --- | --- | --- | --- | --- |
| Summer | 20 °C | ~27.5 °C | ~1,200 kJ | ~4.3 kg | ~15 kg | ~22 % |
| Monsoon | 30 °C | ~32.5 °C | ~400 kJ | ~1.4 kg | ~17.6 kg | ~7.5 % |
| Winter | 15 °C | ~25 °C | ~1,600 kJ | ~5.7 kg | ~13.3 kg | ~30 % |

Monsoon benefits little because the temperature gradient is small.

## Well water vs surface water
Groundwater is fairly stable (~20–24 °C) year-round: better than surface water in peak summer, less
helpful in winter. Test both.

## Hygiene
Dip the **sealed** outer vessel only — never expose milk to open water — and use reasonably clean water
to avoid contaminating the lid and seal area.

## Field test protocol (get your own ε)
1. Fill a container with milk (or a water proxy) at ~35 °C; record temperature.
2. Immerse the sealed container in the local water source for 10 min; record water temperature.
3. Record the milk temperature after 10 min.
4. ε = (T_start − T_after) / (T_start − T_water).
5. Repeat across seasons and sources; add CSVs to `data/`.

> ε = 0.3 / 0.5 / 0.7 in the analysis is an engineering assumption, not measured data.
