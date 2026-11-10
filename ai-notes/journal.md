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

## 09.11.2026: Erster Upload KiCad + Review
- User-Dateien (pro/sch/pcb, KiCad 10) nach PCB/ hochgeladen. .kicad_prl bewusst nicht (gitignored).
- Netz-Check (Pads der .kicad_pcb gegen Netzliste): alles korrekt AUSSER D1 verpolt (CHG an Anode, R19 an Kathode).
  Vertauscht aber unkritisch: R21↔R22 (SD_MODE U6/U5), J4↔J5 (U5→J5, U6→J4) – nur Beschriftung.
- PCB: 100×100 mm, 2 Lagen, 146 Vias 0,6/0,3. Probleme: keine GND-Fläche, Strombahnen zu dünn
  (VSYS/VBAT 0,2–0,3, VBUS 0,4, L1-Netze 0,2), Lader U3 ~60 mm von J1 entfernt. User mag Layout selbst nicht.

## 09.11.2026: Review Version 2 (100×70 mm)
- Netze ok bis auf: D1 weiterhin verpolt. Keine Zonen (keine GND-Fläche).
- Verbindungs-Check (eigenes Skript tools/conn.py, Pads+Segmente+Vias): nur GND offen → 2 Inseln
  (U4/3V3-Block vs. Rest), nur über Teil-Pads des ESP32-Masse-Pads verbunden.
- Strompfade 0,5 mm ok. VSYS hat 42 mm in 0,2 mm (prüfen: nicht zu U5/U6). 3V3/Lautsprecher 0,2–0,3 (optional).
- User will nur Pflicht-Fixes hören.

## 09.11.2026: SD_MODE gelöst
- Quelle: Adafruit MAX98357 Guide (pinouts): intern 100k Pull-down; <0,16 V aus, 0,16–0,77 (L+R)/2,
  0,77–1,4 rechts, >1,4 links. GAIN offen = 9 dB (15 dB: 100k→GND, 12: GND, 6: Vin, 3: 100k→Vin).
- Empfehlung: R21/R22 Pin 1 an +3V3 statt VSYS (VSYS 3,0–4,4 V zu variabel für Rechts-Fenster).
- R22 (an U5;4) = 47k → ~2,2 V = links. R21 (an U6;4) = 220k → ~1,0 V = rechts. GAIN offen.
- J4/J5-Werte tauschen (U5→J5 trägt "Lautspr_R").

## 09.11.2026: PCB Neuanfang (Zwischenstand, 100×100 mm)
- User meldet Gesamtzeit Hack Club gestern+heute: 7 h 18 min (laut User).
- Neues Layout begonnen: 100×100, noch keine Vias, 36 Netze offen (WIP). Kein GND-Flächen-Plan (User will Leitungen, min. 0,45 mm).
- R21 = 240k, R22 = 47k eingetragen (an VSYS) ✓. D1 IMMER NOCH verpolt (Pin 2/Anode an U3;9).
- 09.11.: D1 im Schaltplan korrigiert (D1;1→U3;9, D1;2→R19;2), per tools/sch.py geprüft. PCB braucht F8.

## 10.11.2026: Review PCB Version 3 (100×70 mm)
- Alle Netze bis auf GND geroutet. 293 Vias. Netze jetzt benannt (VBUS, VBUS_F, VBAT, VSYS, +3V3).
- D1 korrekt (U3;9 an D1;1). R21/R22 doch an +3V3 (User), Werte 240k/47k → bei 3V3 eigentlich 220k/47k (240k → 0,97 V, ok).
- Strompfade 0,6 mm ✓, 3V3 0,4 ✓, Lautsprecher 0,4 ✓, D+/D− 0,25 ✓. L1-Netze nur 0,2 mm (1,6 mm lang).
- GND-Zone (F.Cu+B.Cu) + Keepout vorhanden, aber NICHT gefüllt gespeichert → User muss B drücken + speichern, dann DRC.
