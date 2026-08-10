# pns-acquisition
WIP - dual pcb arm band for multi channel semg acquisition

Clamshell design, 8 channels, modular design with DB and MB

Status:
HW:
- DB : schematic complete, layout underway
- MB : schematic v1 complete, in need of revision

<img width="1141" height="577" alt="image" src="https://github.com/user-attachments/assets/e6601e46-bfe2-42a1-9ebb-e2f1ddd7af97" />

DB PCB Progress (8-10-26)
- some pads need to be swapped for vias
- no ground pour atm - need different planes for analog and digital
- would like to move signal lines out from under IC to reduce interference risk
- need to re route power line so it doesnt go through IC

FW:
- devboard: flashing + building works, no progress on actual functionality
- final PCB: n/a

## License
Firmware (`fw/`) — MIT  
Hardware (`hw/`) — CERN-OHL-P v2  
Documentation (`docs/`) — CC BY 4.0
