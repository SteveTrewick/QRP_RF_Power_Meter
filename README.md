# A Tiny QRP RF Power Meter

A tiny QRP (< 400 mW) RF power meter with an ATTiny85, SSD1306 OLED and a peak detection circuit.

This project uses the simplest possible RF peak detection circuit as given in EMRFD et al, just a diode and a capacitor to measure the peak voltage.

An ATTiny85 MCU samples using a 10 bit DAC and calculates the RMS power and dBm values of the signal.

Note that when the ATTiny85 is on circuit you cannot program it via USB as the ADC is shared with the USB pins. You will either need to remove the ATTiny or disconnect the ADC line.
# Schematic

![Circuitschematic](QRP_Power_Meter_Schematic.png?raw=true "Schematic")

# On The Bench

![Circuit on bread board](breadboard.jpeg?raw=true "QRP Power Meter")
