# Pinout – Retro Cassette

Board: ESP32-WROOM-32E (U1). All GPIO numbers below refer to the ESP32.

## Buttons (active LOW, 10 kΩ pull-ups on the PCB)

| Button | Function | GPIO | Pull-up |
|---|---|---|---|
| SW1 | ⏮ Previous / Volume − (long press) | GPIO32 | R8 |
| SW2 | ⏯ Play / Pause | GPIO33 | R9 |
| SW3 | ⏭ Next / Volume + (long press) | GPIO34 (input only) | R10 |
| SW4 | Mode (Bluetooth ↔ SD) | GPIO35 (input only) | R11 |
| SW5 | RESET | EN | R3 + C17 |
| SW6 | BOOT | GPIO0 | – |

## Audio – I2S to 2× MAX98357A

| Signal | GPIO | Goes to |
|---|---|---|
| BCLK | GPIO26 | U5 + U6 (BCLK) |
| LRCLK (WS) | GPIO25 | U5 + U6 (LRCLK) |
| DIN (data) | GPIO22 | U5 + U6 (DIN) |

| Amplifier | Channel | SD_MODE resistor | Speaker connector |
|---|---|---|---|
| U5 | Left | R22 = 47 kΩ | J5 (Lautspr_L) |
| U6 | Right | R21 = 240 kΩ | J4 (Lautspr_R) |

Gain: GAIN_SLOT not connected → 9 dB.

## microSD card (SPI)

| Signal | GPIO | J2 pin |
|---|---|---|
| CS | GPIO5 | DAT3/CD |
| SCK | GPIO18 | CLK |
| MISO | GPIO19 | DAT0 |
| MOSI | GPIO23 | CMD |

## Power / status

| Signal | GPIO | Note |
|---|---|---|
| Battery voltage | GPIO36 (SENSOR_VP) | VBAT / 2 via R14 + R15 (100 kΩ each) |
| USB power present (PGOOD) | GPIO39 (SENSOR_VN) | LOW = USB connected, pull-up R2 |
| Charge LED (D1) | – | driven directly by the charger (U3, CHG) |

## USB / programming

| Signal | ESP32 | Via |
|---|---|---|
| TX → PC | TXD0 (GPIO1) | CH340C (U2) RXD |
| RX ← PC | RXD0 (GPIO3) | CH340C (U2) TXD |
| Auto-reset | EN, GPIO0 | Q1, Q2 (DTR/RTS) |

## Connectors

| Ref | What | Pins |
|---|---|---|
| J1 | USB-C (power + programming) | 5 V, D+/D− |
| J2 | microSD card | see above |
| J3 | Battery (optional, 1S LiPo, JST PH 2.0) | **Pin 1 = +**, Pin 2 = − |
| J4 | Speaker right (JST PH 2.0) | U6 OUT+ / OUT− |
| J5 | Speaker left (JST PH 2.0) | U5 OUT+ / OUT− |

> ⚠️ Check the battery polarity with a multimeter before plugging it in (J3 pin 1 must be +).
> ⚠️ Never connect a speaker wire to GND – both amplifier outputs are active.
