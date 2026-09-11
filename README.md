# pns-acquisition
WIP - dual pcb arm band for multi channel semg acquisition

Clamshell design, 8 channels, modular design with DB and MB

Status:

Current plan is to finish design of DB, get boards manufactured, and test with nrf5340 devboard. After testing confirms functionality, design a pcb to stack with the DB to move SoC functionality, IMU, and power to the wrist.
HW:
- DB : schematic complete, layout underway
- MB : schematic v1 complete, in need of revision
# Hardware
---
## Current Layout

<img width="1115" height="770" alt="image" src="https://github.com/user-attachments/assets/91e8bb75-ed81-4e31-bb99-d2b604f42ca5" />



DB PCB Progress (9-10-26) - see [docs/db/daughterboard-adr.md](./docs/db/daughterboard-adr.md) for more details.
- no ground pour currently - need different planes for analog and digital
- need to confirm power rail is within spec (max current is 1.2A)
- Need to better organize silkscreen lettering

## Previous Versions
<img width="991" height="513" alt="image" src="https://github.com/user-attachments/assets/ad657aaa-5e50-4bc7-a854-052c94e75c4b" />

# Firmware
---
Barebones layout gets finalized.
- devboard: flashing + building works, no progress on actual functionality
- final PCB: n/a

## License
Firmware (`fw/`) — MIT  
Hardware (`hw/`) — CERN-OHL-P v2  
Documentation (`docs/`) — CC BY 4.0
