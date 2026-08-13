6-24-26 -ew
updaing pins:
Pin             |Update
--|--
VCAP1           |22µF cap to AVSS — required
VCAP2           |1µF cap to AVSS — required
VCAP3           |1µF cap to AVSS — required
VCAP4           |1µF cap to AVSS — required
CLKSEL          |Tie high (DVDD) for internal oscillator, or low for external clockDAISY_INTie to DGND if not using daisy chain
RESV1           |Must tie to DGND per datasheet
PWDN            |Active low — tie high to DVDD through resistor, or control from MCU
RESET           |Active low — pull high, control from MCU via the cable connector
START           |Control from MCU via cable connector
RESP_MODP/N     |Leave floating — these are ADS129xR only, not needed on ADS1298
GPIO1-          |4Tie to DGND if unused

setting clocksel high for now. may need to change to sync multiple adcs

further considerations:

after deciding to include and ADC on the mother board to make biosignal transmission more reliable, look into AFE159RP4. Might be lower power with 4 channels. newer chip.
https://www.ti.com/product/AFE159RP4

6-30-26 -ew
- Added 14 pin FFC header to daughterboard schematic (Molex 52793-1470 — 14 pos, 1.0mm pitch, Right Angle). arranged pins so pin 1 & 14 are gnd to protect against open loop problems while connecting. 
- Switched from ports to netlabels for main schematic net
Wired inputs/outputs from FFC header as follows:
---
Signal                              |Net Name        |Direction
--|--|--
SPI clock                           |SCLK_AFE        |MCU → ADS1298
SPI data in (to ADS1298)            |MOSI_AFE        |MCU → ADS1298
SPI data out (from ADS1298)         |MISO_AFE        |ADS1298 → MCU
Chip select (active low)            |~CS_AFE         |MCU → ADS1298
Data ready interrupt (active low)   |~DRDY_AFE       |ADS1298 → MCU
Reset (active low)                  |~RESET_AFE      |MCU → ADS1298
Start conversion                    |START_AFE       |MCU → ADS1298
---
Signal      |Pin Name    |TQFP64 Pin #
--|--|--
~CS_AFE     |*CS         |39
~DRDY_AFE   |*DRDY       |47
~RESET_AFE  |*RESET      |36
START_AFE   |START       |38
SCLK_AFE    |SCLK        |40
MOSI_AFE    |DIN         |31
MISO_AFE    |DOUT        |43
--- 

7-20-26 -ew

initilized PCB file - missing footprint to adc

7-22-2026 -ew

Recieved devboard and breakout for IMU

TODO: 
- update DRL PIN / add a dip switch to change between DGND (disabled) and a feedback circuit
- figure out how to make the netlabels not upside down