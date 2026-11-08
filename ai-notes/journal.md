# Claude-Log

## 08.11.2026: Projektstart Retro-Kassette
- Vorgänger "stream-deck" abgebrochen (Repo gelöscht). Regeln/User-Kontext übernommen.
- Interview Runde 1: Bluetooth + SD, Akku + Dauerstrom, 4 Keyboard-Tasten, Größe egal.
- Erklärt: Link-Download (YouTube/Spotify) nicht machbar/legal → MP3-Datei; ESP32-S3 kann kein A2DP.
- Repo eingerichtet (main, Ordner, .gitignore, ai-notes), gepusht.

## 08.11.2026: Interview Runde 2
- Geschenk für Vater, Deadline Weihnachten → Zeitplan-Warnung gegeben.
- Stereo-Lautsprecher, 4000 mAh (Parallel-Warnung), Power-Path-Lader erklärt.
- Alte Repos: claude-workers lokale Kopie gelöscht; stream-deck ist Session-Startordner, nicht mehr anfassen.

## 08.11.2026: JLC-Check Lader + Amp
- JLC-API (selectSmtComponentList) abgefragt: BQ24074 gewählt, MAX98357A TQFN bestätigt. Echte LCSC-Nummern notiert.

## 08.11.2026: Repo-Start + BOM.csv
- BOM.csv angelegt (nur Teile mit echten JLC-Daten, Preise Stand 08.11.2026, 1-Stk.-Preis).
- 3,3 V: TPS63001DRCR (Buck-Boost, C28060) statt LDO – User: "passt".
- microSD: TF-01A (C91145/C2889258) bei JLC billig, aber KEIN Footprint in KiCad-10-Std-Lib → noch klären.

## 08.11.2026: Stückliste Schaltplan (Beratung im Chat)
- Datenblätter TI gelesen (pdftotext): BQ24074 KISET 890 AΩ, KILIM 1610 AΩ (0.5–1.5 A), RILIM min 1.1k,
  TMR 18–72k (tMAXCHG=10×48 s/kΩ×R), TS 10k wenn kein NTC, EN2=1/EN1=0 → ILIM-Widerstand, CHG/PGOOD open-drain.
  Pins: 1 TS, 2/3 BAT, 4 CE, 5 EN2, 6 EN1, 7 PGOOD, 8 VSS, 9 CHG, 10/11 OUT, 12 ILIM, 13 IN, 14 TMR, 15 ITERM, 16 ISET.
- TPS63001: L 2.2 µH, Cin 10 µF, Cout 2×10 µF, VINA 100 Ω + 0.1 µF, FB→VOUT. Pins: 1 VOUT, 2 L2, 3 PGND,
  4 L1, 5 VIN, 6 EN, 7 PS/SYNC, 8 VINA, 9 GND, 10 FB.
- Gewählt: R3 887Ω 1% (1 A), R4 1.1k (1.46 A), R5 68k (~9 h), F1 1.5 A (wegen Ladestrom!). CH340C an 3,3 V.
- microSD: Molex 104031-0811 (C585350, $0.68) – passt zu KiCad-Footprint.
- OFFEN: MAX98357A SD_MODE-Widerstand (Datenblatt-Download blockiert), Ein/Aus-Schalter?

## 08.11.2026: Ref-Nummern FINAL (nach Wert/Footprint gruppiert) – gilt für Pin-Liste!
- C1–C3 10u 0805: U3 IN / OUT / BAT
- C4–C9 10u 0603: U4 in / U4 out / U4 out / U1 3V3 / U5 VDD / U6 VDD
- C10–C16 100n 0402: U4 VINA / U1 3V3 / U2 VCC / U5 VDD / U6 VDD / J2 / ADC
- C17 1u 0402: U1 EN
- R1–R11 10k: TS / PGOOD / EN / Q1-B / Q2-B / SD-CS / SD-MISO / SW1 / SW2 / SW3 / SW4
- R12–R13 5.1k CC1/CC2 · R14–R15 100k Akku-Teiler · R16 887 ISET · R17 1.1k ILIM · R18 68k TMR
- R19 1k D1 · R20 100 VINA · R21–R22 SD_MODE (offen)
- D1 LED rot, F1 1.5A, H1–H4, J1 USB-C, J2 microSD, J3 Akku, J4/J5 Lautsprecher L/R, L1 2.2uH, Q1/Q2,
  SW1–4 MX (⏮ ⏯ ⏭ Modus, DNP), SW5 RESET, SW6 BOOT, U1 ESP32, U2 CH340C, U3 BQ24074, U4 TPS63001,
  U5/U6 MAX98357A L/R, U7 USBLC6.

## 08.11.2026: Zeit + PCB-Beratung
- User meldet heute 3 h 18 min Arbeitszeit (laut User). Hinweis gegeben: nur Zeit für dieses Projekt loggen,
  Eintrag ≤5 h, ≥1 eigenes Bild, Format "## TT.MM.JJJJ: Titel", Frontmatter-Felder. Text schreibt User selbst.
- Netzliste nach Funktionsblöcken (1 USB … 9 Audio R) im Chat gegeben.
- PCB-Vorschlag: 100×50 mm, 2 Lagen, Antenne an Kante mit Keepout, Ladeblock an J1, Bahnen ≥0,8 mm Strom.
- OFFEN: Tasten vorne (A) oder oben (B)? SD_MODE/GAIN_SLOT MAX98357A, Ein/Aus-Schalter.
