# Contributing to ECO CHILL 40

Thanks for your interest! This project started as a Smart India Hackathon 2026 entry
(SIH26110) and we welcome improvements from dairy scientists, mechanical/thermal
engineers, embedded developers and field practitioners.

## Ways to help
- **Field data:** run the cooling / pre-cooling tests described in `docs/pre_cooling_analysis.md`
  and open a PR adding your CSV to `data/` (with a short description of conditions).
- **Firmware:** sensor calibration, low-power modes, better spoilage-risk logic.
- **Hardware:** CAD files, alternative food-grade materials, PCM formulations.
- **Docs:** corrections, translations (Hindi, Assamese, Tamil, etc.).

## Workflow
1. Fork the repo and create a branch: `git checkout -b feature/short-description`
2. Make your change; keep commits small and descriptive.
3. If you change a number (weight, cost, temperature, PCM mass), update **every** file that
   quotes it (`README.md`, `docs/`, `hardware/BOM.csv`) so the figures stay consistent.
4. Open a pull request describing what changed and why.

## Firmware style
- Arduino C++; constants in `UPPER_SNAKE_CASE`; comment every pin and threshold.
- Test on real hardware or state clearly that it is untested.

## Safety note
This is a food-contact product. Any change touching milk-contact materials, PCM formulation
or cleaning procedure must cite the relevant food-safety standard or test evidence.

## Code of conduct
Be respectful and constructive. Harassment or discrimination of any kind is not tolerated.
