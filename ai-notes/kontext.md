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
- (VERALTET, Stand 11.11.: jetzt Tier 1–5 in Scraps: 1000/500/250/100/50) Früher: Tier 4 ~8–16 h/$50, Tier 3 ~17–33 h/$125, Tier 2 ~34–66 h/$250.
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

## Interview Runde 2 (08.11.2026)
- **Zweck:** Offiziell (README/Fabricate) Deko-Stück mit coolen Features; INOFFIZIELL Weihnachtsgeschenk → privates Ziel 24.12., PCB bis ~Ende Nov bestellen. Geschenk NICHT in README/Fabricate-Texte.
- **Lautsprecher:** User überlässt mir die Wahl → Stereo 2× 40 mm 3 W 4 Ω + 2× MAX98357A (direkt an VSYS).
- **Akku:** 4000 mAh, User will 2× 2000 mAh parallel (1S2P). Gewarnt: identische Zellen, gleich voll vor
  Verbinden, nur mit PCM. Alternative 1× 4000 mAh mit PCM empfohlen. Entscheidung beim Bestellen.
- **Laden:** Power-Path gewünscht (USB versorgt System, lädt nur wenn nötig, stoppt bei voll).
  Vorschlag BQ24074 oder MCP73871 – JLC-Verfügbarkeit/Preis noch prüfen.
- **Tier:** am Ende.

## Entscheidungen 08.11.2026 (Runde 3)
- **Tasten:** ⏮ Zurück · ⏯ Play/Pause · ⏭ Weiter · Modus BT/SD. Lautstärke = lang drücken ⏮/⏭. (User: "super")
- **Optik:** echte Deko-Kassette hinter Glas ODER gedruckte – User findet beides gut, Entscheidung beim CAD.
- **Lader:** BQ24074RGTR, LCSC C54313, QFN-16 3×3, $2.12, Extended (JLC-API-Abfrage 08.11.).
  Alternative MCP73871T-2CCI/ML C511310 $2.13.
- **Audio-Amp:** 2× MAX98357AETE+T, LCSC C910544, TQFN-16 3×3, $1.31, Extended. NICHT die BGA-Version C2682619.
- JLC-Extended-Rüstgebühr ~$3 pro Teilenummer einrechnen.

## Arbeitsweise Journal (08.11.2026)
- User loggt nach jeder Sitzung direkt auf Fabricate; JOURNAL.md auf GitHub wird erst am Projektende geschrieben.
  → Nicht ständig nach JOURNAL.md fragen. Hin und wieder an Screenshots erinnern.
