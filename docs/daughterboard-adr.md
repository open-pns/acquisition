6-24-26
updaing pins:

VCAP1           22µF cap to AVSS — required
VCAP2           1µF cap to AVSS — required
VCAP3           1µF cap to AVSS — required
VCAP4           1µF cap to AVSS — required
CLKSEL          Tie high (DVDD) for internal oscillator, or low for external clockDAISY_INTie to DGND if not using daisy chain
RESV1           Must tie to DGND per datasheet
PWDN            Active low — tie high to DVDD through resistor, or control from MCU
RESET           Active low — pull high, control from MCU via the cable connector
START           Control from MCU via cable connector
RESP_MODP/N     Leave floating — these are ADS129xR only, not needed on ADS1298
GPIO1-          4Tie to DGND if unused

setting clocksel high for now. may need to change to sync multiple adcs

further considerations:

after deciding to include and ADC on the mother board to make biosignal transmission more reliable, look into AFE159RP4. Might be lower power with 4 channels. newer chip.
https://www.ti.com/product/AFE159RP4
