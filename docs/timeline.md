# acquisition timeline

> **Hard Deadline:** September 21, 2026 — *Live EMG stream over BLE/USB to host*  
> **Off-Site Window:** July 10–17  
> **Power Stack:** TPS62827 (buck, DVDD 3.3V) + LT3042 (LDO, AVDD 3.0V) — discrete

---

## Timeline

### Schematic & Layout

| Date | Milestone | Deliverable |
|------|-----------|-------------|
| Jun 9 | **Phase 1 begins** | Design doc signed off. Stack A committed. All Phase 3 gates logged. |
| Jun 14 | **Altium environment ready** | Project created. Repo structured. Schematic symbols and footprints complete for all Stack A components — ADS1298, nRF5340, BMI270, TPS62827, LT3042. All footprints verified against IPC-7351B. |
| Jun 26 | **Daughter board schematic complete** | Electrode input protection network, ADS1298 with AVDD decoupling per datasheet, DRL circuit per TI TIDA-01069, board-to-board connector pinout defined. |
| Jul 2 | **Main board schematic complete** | nRF5340 with decoupling per Nordic PCA10095. Dedicated SPIM0 → ADS1298 and SPIM1 → BMI270. TPS62827 buck for DVDD, LT3042 LDO for AVDD. SWD header, USB connector, BLE antenna keep-out defined. |
| Jul 6 | **Schematic review & ERC clean** | Full checklist review complete. ERC passes zero errors. Layout does not begin until this gate is signed off. |
| Jul 9 | **Layout underway** | Daughter board placement complete. Main board placement started. Analog and digital domains separated. ADS1298 AVDD decoupling within 2mm of supply pins. BLE keep-out enforced. |

---

### Off-Site

| Date | Milestone | Deliverable |
|------|-----------|-------------|
| Jul 10–12 | **Layout finalized** | Both boards placed and routed. DRC clean. Gerbers and drill files exported and verified in Altium viewer. |
| Jul 13 | **Gerbers submitted + BOM ordered** | Submitted to JLCPCB. Full BOM ordered from Mouser/Digi-Key simultaneously. Fab confirmation in hand. Components shipping to home address. |
| Jul 10–17 | **Firmware scaffolding** | Zephyr project initialized in nRF Connect SDK. SPIM0 configured for ADS1298 (Mode 1, DRDY interrupt-driven). SPIM1 configured for BMI270 (Mode 0). ADS1298 register map defined — device ID, gain, sample rate, channel enable. BLE GATT service skeleton with streaming (notify) and config (write) characteristics. USB CDC device class configured. Project compiles cleanly against nRF5340 target. |
| Jul 17 | **Return** | Boards in fab. Components in transit or arrived. Ready to begin assembly. |

---

### Fabrication & Bring-Up

| Date | Milestone | Deliverable |
|------|-----------|-------------|
| Jul 27 | **PCBs arrive** | Boards inspected — pad alignment, soldermask, no visible shorts. All components confirmed in hand. |
| Jul 30 | **Power section verified** | TPS62827 and LT3042 assembled. DVDD = 3.3V, AVDD = 3.0V confirmed under load. No anomalous current draw before populating ICs. |
| Aug 5 | **MCU bring-up** | nRF5340 populated. SWD connected. Blink firmware running. RTT logging confirmed. Both cores booting. Firmware scaffold running on hardware. |
| Aug 11 | **AFE bring-up** | ADS1298 populated. Device ID register returns 0x92. Configuration verified — 2000 SPS, low-power mode, G=12. DRDY interrupt confirmed at 2 kHz. |
| Aug 17 | **Signal chain validated** | All 8 channels streaming without dropout. Known differential input verified through ADC. BMI270 WHO_AM_I confirmed. DRL active — 60 Hz rejection improvement confirmed on oscilloscope. |
| Aug 24 | **Streaming pipeline complete** | Raw 8-channel sEMG and IMU data logging to CSV over USB at 2 kSPS. BLE GATT streaming confirmed via nRF Connect. Both transport paths verified. |
| **Sep 21** | **🏁 Hard deadline** | Dry electrodes on forearm. Live sEMG visible in real-time host plot. Wrist flexion and extension produce distinguishable signal response across channels. Noise floor and SNR logged per channel. |