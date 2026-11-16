# retro-cassette

## A decoration thing with an retro cassette which can play musik

<img width="1024" height="559" alt="image" src="https://github.com/user-attachments/assets/730c1163-bd13-4e75-bf21-e0fa9a5c4108" />



## What it does? 

It can playing music from an SD card with an retro look

### Features:

Bluetooth-Speaker, so your phone can connect to it

plays MP3s from a microSD-card

Stereo with 2 Speakers (2× 3 W)

4 mechanic switches like an Cassettedeck: ⏮ · ⏯ · ⏭ · Modus (Bluetooth/SD)

Volume via long press on ⏮/⏭

USB-C for power and for flashing

with an battery


## Why I would work on it?

### Because of it look amazing an I learned:

-How I design an PCB

-How the ESP32 works and how I flashe it


## Pictures

<img width="1063" height="601" alt="Screenshot 2026-11-08 170205" src="https://github.com/user-attachments/assets/66898e35-3781-4bcd-b68c-3fa4e939739d" />
<img width="1086" height="754" alt="Screenshot 2026-11-11 201823" src="https://github.com/user-attachments/assets/30b3f69a-00de-4e55-8947-041f1415cc73" />
<img width="1085" height="761" alt="Screenshot 2026-11-11 201831" src="https://github.com/user-attachments/assets/82405c7d-1529-4ae5-b479-e96dfd7fe84b" />
<img width="1222" height="720" alt="Screenshot 2026-11-15 163617" src="https://github.com/user-attachments/assets/2656f5bf-6a45-4fe5-b1de-9ec049cfcb34" />

## Bom + Cost

### It cost round about 125$
The full bill of materials with links and prices is in [BOM.csv](BOM.csv).
BOM: [BOM](BOM.csv)

## Assemble:
All parts will come together in a frame made out of wood.

I solder the MX-Switches on the Board and made the frame.


## Firmware:

### [Firmware](firmware/)

### How do you do it, to flash it:

To get started, you will need VS Code with the PlatformIO IDE extension installed, along with a USB-C cable that supports data transfer (charge-only cables will not work). If you are using Windows, you may also need the CH340 driver from the manufacturer WCH, as the chip on the board is a CH340C.

To flash the firmware, first open the firmware/ folder in VS Code by selecting File and then Open Folder, and connect the board to your PC via USB-C. Next, click the arrow icon (Upload) in the bottom blue status bar. PlatformIO will then compile and upload the firmware; because the auto-reset circuit via Q1/Q2 automatically switches the ESP32 into flash mode, you do not need to press any buttons during this process. However, if the upload fails—for instance, with a "Failed to connect" error—hold down the BOOT button (SW6), briefly press the RESET button (SW5), release the BOOT button, and click Upload once more.

## Pinout
[Pinout](docs/PINOUT.md)


## What AI did:
AI wrote me the text to how you flash it and was planning the whole projekt with me. He cerrects me every time i forgot something or made mistakes, he did the repo structure and the research.

##License

MIT-License [LICENSE](LICENSE)
