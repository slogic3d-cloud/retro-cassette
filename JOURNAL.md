Titel: "Retro-Kassette"
github: "https://github.com/slogic3d-cloud/retro-cassette"
Beschreibung: „Ein Deko-Teil mit einem Retro-Kassettenspieler, der Musik abspielen kann“
erstellt am: "2026-11-08"
Gesamtzeit: "18h 24m"
---

8. November 2026: Beginnend mit Forschung und Schema
<!-- fabricate:entry 2403 -->

Heute habe ich recherchiert, was ich brauche, und dann mit dem Schaltplan angefangen.
Ich fange mit der Leiterplatte an, schaffe es aber heute nicht mehr, deshalb muss ich das morgen machen.

![](https://fabricate.hackclub-assets.com/a40b2f92eceb4d69bd5579c634c50e2cfad9d8dced7b51a613d8d18bca5a74d0/image-png/Screenshot%202026-11-08%20170205.png)

**Gesamtzeitaufwand: 3 Stunden 18 Minuten**

# 9. November 2026: Beginnen wir mit der Leiterplatte
<!-- fabricate:entry 2501 -->

Heute habe ich mit der Leiterplatte angefangen und sie ist nicht so gut geworden, dass ich die alte Version wegen vieler Fehler löschen muss.

Die Fehler sind:
-dünne Spuren
-einige Probleme mit der Erdung
-umgekehrte Polarität bei der LED

Heute habe ich aufgegeben, das hat mich eine Menge Nerven gekostet.

![](https://fabricate.hackclub-assets.com/80b9092d0a059c45355dd60e2f2464b7423d3922a223b3b5772c33e2744f64c0/image-png/Screenshot%202026-11-09%20192648.png)

**Gesamtzeitaufwand: 4 Stunden 6 Minuten**

# 10. November 2026: Fertigstellung der Leiterplatte und Behebung der Probleme
<!-- fabricate:entry 2566 -->

Heute habe ich die Leiterplatte fertiggestellt.
Anstatt Leiterbahnen von GND zu GND herzustellen, habe ich eine GND-Zone in der B.Cu-Schicht erstellt, wodurch meine Probleme mit GND beseitigt wurden.
Das Problem mit der verpolten LED wurde ebenfalls gelöst.
Das Problem mit den dünnen Gleisen habe ich mit meinem Bruder gelöst, und er hat mir erklärt, wie ich es richtig gemacht habe, sodass er jetzt die restlichen Gleise fertig verlegen kann.

![](https://fabricate.hackclub-assets.com/7bee9e226288c0a9ff08a3dbb0537843cec10e8ab3fce17a535265e5b528d4a3/image-png/Screenshot%202026-11-10%20181639.png)

**Gesamtzeitaufwand: 4 Stunden 36 Minuten**

# 11. November 2026: Die Unterlagen für die Leiterplatte erstellt.
<!-- fabricate:entry 2630 -->

Heute habe ich die Unterlagen für die Leiterplatte erstellt.
Das heißt, ich habe die Datei Bom.csv exportiert und die Ordnerstruktur sortiert.
Tatsächlich habe ich eine abschließende DRC durchgeführt und die Fehler korrigiert.
Ich habe die Gerber-Dateien und die .step-Datei generiert, damit ich morgen den entsprechenden Fall bearbeiten kann.

![](https://fabricate.hackclub-assets.com/64d4b53aad99df01c3544cdb394190d027e8cab62799788381f0e41c02f562b3/image-png/Screenshot%202026-11-11%20175225%20-%20Copy.png)
![](https://fabricate.hackclub-assets.com/2344e3113b73128cab8f5941a4a35c3bd0621bd5c2bec8ad31a54c708724c58a/image-png/Screenshot%202026-11-11%20175406%20-%20Copy.png)

**Gesamtzeitaufwand: 1 Stunde**

# 11. November 2026 (Eintrag 2): Recherche für die Materialien
<!-- fabricate:entry 2642 -->

Nach einer kurzen Pause recherchierte ich die Preise und die Versandkosten bei Amazon und AliExpress.
Ich habe nach verschiedenen Teilen gesucht und sowohl gute als auch schlechte Ergebnisse erhalten.
Auf JLCPCB habe ich mir die Leiterplattenseite angesehen, um einen Blick auf die Preise zu werfen.

Ich habe ein wenig mit der Firmware angefangen.

![](https://fabricate.hackclub-assets.com/9ce2ed6d402c03609fa57f78b7d5cd0d2fc0389edf29541217a35662aee3b253/image-png/Screenshot%202026-11-11%20194904.png)
![](https://fabricate.hackclub-assets.com/9b76c8fdf37f87c802cb0fa52951170ed17b70eda13a22aaa15c5686129010cc/image-png/Screenshot%202026-11-11%20201735.png)
![](https://fabricate.hackclub-assets.com/ed503312758578f7af57a4f2299428af361b6aaa60d52e7edd9c33cc91ae966c/image-png/Screenshot%202026-11-11%20201823.png)
![](https://fabricate.hackclub-assets.com/9352c956d872dcf131185c71272e369fee9333cf7b5070fa9035452eaeab1e18/image-png/Screenshot%202026-11-11%20201831.png)

**Gesamtzeitaufwand: 48 Minuten**

# 15. November 2026: Beginnen wir mit den CAD-Sachen
<!-- fabricate:entry 3076 -->

Heute habe ich mit der Arbeit am Rahmen für das gesamte Projekt begonnen.
Ich konnte es nicht vollständig fertigstellen, da ich die Ausschnitte erst anbringen kann, wenn ich genau weiß, wo sie positioniert werden müssen. Daher werde ich die Ausschnitte während der Endmontage anfertigen.

![](https://fabricate.hackclub-assets.com/551a9daf608696ca0e02f8589ac68c2db462aa5a205adde943d75f78386958da/image-png/Screenshot%202026-11-15%20163609.png)
![](https://fabricate.hackclub-assets.com/8245e6fecb258b28d679c1e48b43b5abdd77c719ba425750b8558faf0570d043/image-png/Screenshot%202026-11-15%20163617.png)

**Gesamtzeitaufwand: 48 Minuten**

# 16. November 2026: Kam dem Ende etwas zu nahe.
<!-- fabricate:entry 3208 -->

Heute erstelle ich die README.md-Datei auf GitHub.
Ich habe die BOM.csv und die JOURNAL.md aktualisiert.
Ich habe die CAD-Arbeiten abgeschlossen.

Ich habe die benötigten Komponenten für einen ESP32 auf meinem PC installiert.

![](https://fabricate.hackclub-assets.com/8245e6fecb258b28d679c1e48b43b5abdd77c719ba425750b8558faf0570d043/image-png/Screenshot%202026-11-15%20163617.png)
![](https://fabricate.hackclub-assets.com/2bec1904fba7947576d0961e929b220071e634f75b39f102168122e685f2fc11/image-png/Screenshot%202026-11-16%20161219.png)
![](https://fabricate.hackclub-assets.com/22063f6caf0432523f005ca314b40f73164c47750d6a357ff8a9775eb235fad7/image-png/Screenshot%202026-11-16%20161229.png)

**Gesamtzeitaufwand: 2 Stunden**

# 19. November 2026: Firmware und Fertigstellung
<!-- fabricate:entry 3461 -->

Heute habe ich das Projekt abgeschlossen und mit der Firmware begonnen, die ich mithilfe von KI fertiggestellt habe.
Es gab nicht viel zu tun, aber ich war zu dumm dafür.
Mithilfe von KI korrigiere ich eventuelle Fehler auf GitHub.

![](https://fabricate.hackclub-assets.com/d2b49e1ffa43ac92a6e9e42b932fc0279b0cba7dff6ddab8f9eb1fb514028d7e/image-png/Screenshot%202026-11-19%20173931.png)
![](https://fabricate.hackclub-assets.com/4f6e5d189805899e2d47b5077bd1fc23c57caa8e76f581e6f194ca6056679f4a/image-png/Screenshot%202026-11-19%20173943.png)

**Gesamtzeitaufwand: 1 Stunde 48 Minuten**
