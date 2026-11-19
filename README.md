---
title: "retro-cassette"

## A decoration piece with a retro cassette that can play music

<img width="1024" height="559" alt="image" src="https://github.com/user-attachments/assets/730c1163-bd13-4e75-bf21-e0fa9a5c4108" />



## What does it do?

It can play music from an SD card with a retro look.

### Features:

- Bluetooth-Speaker, so your phone can connect to it

- plays MP3s from a microSD-card

- Stereo with 2 Speakers (2× 3 W)

- 4 mechanical switches like a cassette deck: ⏮ · ⏯ · ⏭ · Mode (Bluetooth/SD)

- Volume via long press on ⏮/⏭

- USB-C for power and for flashing

- with a 4000mAh battery, charges via USB-C


## Why did I build it?
### Because it looks amazing and I learned:

- How to design a PCB

- How the ESP32 works and how to flash it


## Pictures

<img width="1063" height="601" alt="Screenshot 2026-11-08 170205" src="https://github.com/user-attachments/assets/66898e35-3781-4bcd-b68c-3fa4e939739d" />
<img width="1086" height="754" alt="Screenshot 2026-11-11 201823" src="https://github.com/user-attachments/assets/30b3f69a-00de-4e55-8947-041f1415cc73" />
<img width="1085" height="761" alt="Screenshot 2026-11-11 201831" src="https://github.com/user-attachments/assets/82405c7d-1529-4ae5-b479-e96dfd7fe84b" />
<img width="1222" height="720" alt="Screenshot 2026-11-15 163617" src="https://github.com/user-attachments/assets/2656f5bf-6a45-4fe5-b1de-9ec049cfcb34" />

## Bom + Cost
BOM: [BOM](BOM.csv)
The total cost is about $165, I'll pay about $41.
- Grant: $123.86 for PCB with assembly and MX-Switches and shipping
- Me: about $41 for speakers, keycaps, cable extension and battery

## Assembly:
All parts will come together in a frame made out of wood.

I will solder the MX switches on the board and build the frame out of wood.

## Firmware:

[Firmware](firmware/)

### How to flash it:

To get started, you will need VS Code with the PlatformIO IDE extension installed, along with a USB-C cable that supports data transfer (charge-only cables will not work). If you are using Windows, you may also need the CH340 driver from the manufacturer WCH, as the chip on the board is a CH340C.

To flash the firmware, first open the firmware/ folder in VS Code by selecting File and then Open Folder, and connect the board to your PC via USB-C. Next, click the arrow icon (Upload) in the bottom blue status bar. PlatformIO will then compile and upload the firmware; because the auto-reset circuit via Q1/Q2 automatically switches the ESP32 into flash mode, you do not need to press any buttons during this process. However, if the upload fails—for instance, with a "Failed to connect" error—hold down the BOOT button (SW6), briefly press the RESET button (SW5), release the BOOT button, and click Upload once more.

## Pinout
[Pinout](docs/PINOUT.md)


## What AI did:

I used AI (Claude) as a mentor during this project. It helped me with:

- **Planning:** planning the whole project with me and researching the parts
- **PCB review:** checking my schematic and PCB for mistakes (I designed and routed everything by hand)
- **BOM:** keeping the BOM.csv up to date and converting the prices to USD
- **Firmware:** writing most of the firmware, because it is my first time programming an ESP32
- **Docs:** writing the PINOUT.md and the text on how to flash the firmware
- **Repo:** setting up the folder structure and correcting me every time I forgot something or made a mistake

## What I did:

- Designed the schematic in KiCad
- Placed and routed the PCB by hand (with help from my brother)
- Designed the frame in Fusion 360
- Wrote this README and the journal

## License

MIT-License [LICENSE](LICENSE)
