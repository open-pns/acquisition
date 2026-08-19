# pns-acquisition
WIP - dual pcb arm band for multi channel semg acquisition

Clamshell design, 8 channels, modular design with DB and MB

Status:

Current plan is to finish design of DB, get boards manufactured, and test with nrf5340 devboard. After tsting confirms functionality, design a pcb to stack with the DB to move SoC functionality, IMU, and power to the wrist.
HW:
- DB : schematic complete, layout underway
- MB : schematic v1 complete, in need of revision

<img width="1156" height="601" alt="image" src="https://github.com/user-attachments/assets/e7c1ee46-5ad9-4e23-bc48-e324c2a28bf4" />


DB PCB Progress (8-11-26)
- no ground pour atm - need different planes for analog and digital
- would like to move signal lines out from under IC to reduce interference risk
- need to confirm power rail is within spec (max current is 1.2A)

FW:
- devboard: flashing + building works, no progress on actual functionality
- final PCB: n/a

## License
Firmware (`fw/`) — MIT  
Hardware (`hw/`) — CERN-OHL-P v2  
Documentation (`docs/`) — CC BY 4.0
