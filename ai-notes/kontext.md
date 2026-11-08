# Kontext (ausführlich) – Retro-Kassetten-Rahmen für Hack Club Fabricate

## Über den User
- 13–15 J., Deutschland. Chat auf Deutsch, kurz, Erklärungen "mittel" (bei Elektronik/Code kurz das Warum).
- Erfahrung: ESP32-Dev-Board in KiCad 10 (Repo slogic3d-cloud/dev-board), Python-Grundlagen, Arduino-Beispiele,
  Fusion 360 Grundlagen, Drucker Anycubic Kobra 2 Neo (PLA). GitHub im Browser / GitHub Desktop, lädt oft ZIPs hoch.

## Harte Regeln (Fabricate)
- **Ich schreibe keinen Text in README.md oder JOURNAL.md.** Nur Struktur-Tipps, Leitfragen, Feedback, Rechtschreibkorrektur.
- **Kein CAD/PCB direkt designen.** Schaltplan/Platzierung/Routing macht der User von Hand (kein Autorouter).
  Erlaubt: erklären, Pin-/Netzlisten als Beratung, Reviews, Fehler finden, Bauteile vorschlagen.
- **Firmware:** helfen und erklären, nicht komplett allein schreiben.
- Keine KI-Bilder. User schreibt AI Disclosure selbst.
- JOURNAL: Eintrag max. 5 h, mind. 1 Bild, Format `## TT.MM.JJJJ: Titel`, Fehler/Umwege dokumentieren, nur echte Zeit.
- **Nur Branch `main`**, keine weiteren Branches.
- Bei Design- und Geldentscheidungen fragen (Popup-Fragetool, max. 4 Fragen/Runde).

## Meine Rolle
- Mentor/Reviewer: Schaltplan-/PCB-Reviews (KiCad-Dateien selbst prüfen: Netze, offene Verbindungen, Bahnbreiten,
  Bohrungen, Edge.Cuts), Code-Hilfe, CAD-Feedback, BOM + Preise.
- Repo ordnen, .gitignore, Dateien einsortieren, BOM.csv pflegen. Hochgeladene Dateien/ZIPs zuerst prüfen.
- ai-notes/ regelmäßig aktualisieren und pushen.

## Fabricate-Anforderungen (vor Einreichen auf fabricate.hackclub.com/docs prüfen)
- Tier nach Stunden + Komplexität: Tier 4 ~8–16 h/$50, Tier 3 ~17–33 h/$125, Tier 2 ~34–66 h/$250.
  Kostenoptimiert, keine Teile "für später".
- Repo: README (Beschreibung, Warum, Bilder, Screenshots Schaltplan/PCB/3D, Pinout/Verkabelung, BOM-Tabelle/Link +
  Gesamtkosten, AI Disclosure, Lizenz), JOURNAL.md mit Frontmatter (title, github, description, created_at, total_time),
  BOM.csv mit Links/Preisen/Versand, PCB/ (KiCad, gerbers.zip, STEP), CAD/ (STEP + Quelle/Onshape-Link), firmware/ (Pflicht).
- Design-Gegencheck in #fabricate (Hack Club Slack). Nicht selbst bezahlen, bevor Grant-Ablauf geklärt.

## Lessons Learned des Users (letztes Projekt)
- Power-Symbole (+5V, +3V3, GND) + Net-Labels statt langer Drähte; ERC/DRC laufen lassen.
- Strombahnen 0,5 mm, Signale 0,25 mm, Vias 0,3/0,6 mm (JLC 2-Lagen min. 0,3 mm Bohrung).
- JLC-Export mit KiCad-Plugin "Fabrication Toolkit" (Gerber + BOM + CPL). LCSC-Nummern als Feld "LCSC".
  Stiftleisten als DNP, selbst löten.
- JLC: Module wie ESP32-WROOM nur mit Standard PCBA (min. 5 Stk.). Versand "Global Standard Direct Line".
  Bleifreies HASL, kein ENIG.
- Privat gekaufte Kleinteile in BOM als "bought privately - not part of grant" markieren.

## Projekt (ab 08.11.2026): Retro-Kassetten-Bilderrahmen
- Vorheriges Projekt "stream-deck" abgebrochen, Repo vom User gelöscht.
- Idee: Retro-Deko, Bilderrahmen mit (nur optischer) Kassette + 4 Tasten zum Abspielen.
- **Musikquelle:** Bluetooth (A2DP, Handy streamt) + eigene MP3s auf microSD, Upload per WLAN-Webseite.
  → MCU **ESP32-WROOM-32E** (klassisch; S3 kann kein A2DP). Audio: MAX98357A (I2S, 3 W) + Lautsprecher.
  Link-Download (YouTube/Spotify) erklärt als nicht machbar/legal → MP3-Datei statt Link.
- **Strom:** Akku (LiPo) UND Dauerbetrieb am USB → Lade-IC mit Power-Path/Load-Sharing nötig.
- **Tasten:** 4 Keyboard-Tasten (MX).
- **Rahmengröße:** egal (Vorschlag 13×18 cm).
- **Repo:** slogic3d-cloud/retro-cassette (noch anzulegen, add_repo schlug fehl am 08.11.).
- Offen: Tier, Spulen-Motor/VU-LEDs (nicht gewählt), Flashen (ESP32 klassisch braucht USB-UART, z. B. CH340C).
