"""Generate data/cooling_curve.png from cooling_validation_log.csv."""
import csv
from pathlib import Path

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

here = Path(__file__).parent
rows = list(csv.DictReader(open(here / "cooling_validation_log.csv")))
t = [int(r["elapsed_min"]) / 60 for r in rows]
temp = [float(r["temp_c"]) for r in rows]

fig, ax = plt.subplots(figsize=(7, 4), dpi=150)
ax.plot(t, temp, marker="o", color="#1f6fb2", linewidth=2)
ax.axhline(8, color="#c0392b", linestyle="--", linewidth=1, label="8 °C safe-limit reference")
ax.axvspan(0, 2, color="#d6eaf8", alpha=0.5, label="Pull-down (2 h)")
ax.annotate("37.9 °C", (t[0], temp[0]), textcoords="offset points", xytext=(6, -4))
ax.annotate("8.7 °C", (t[2], temp[2]), textcoords="offset points", xytext=(6, 8))
ax.set_xlabel("Elapsed time (hours)")
ax.set_ylabel("Milk temperature (°C)")
ax.set_title("EcoChill-10 prototype: cooling validation")
ax.grid(alpha=0.3)
ax.legend()
fig.tight_layout()
fig.savefig(here / "cooling_curve.png")
print("saved", here / "cooling_curve.png")
