#include <Arduino.h>
#include "AudioTools.h"          // I2S-Ausgang zu den MAX98357A
#include "BluetoothA2DPSink.h"   // Bluetooth-Lautsprecher

// Tasten (docs/PINOUT.md)
const int TASTE_ZURUECK = 32;  // ⏮
const int TASTE_PLAY    = 33;  // ⏯
const int TASTE_WEITER  = 34;  // ⏭
const int TASTE_MODUS   = 35;  // Modus (BT/SD) - kommt spaeter

// I2S zu den Verstaerkern (docs/PINOUT.md -> "Audio")
const int I2S_BCLK = 26;
const int I2S_LRC  = 25;
const int I2S_DIN  = 22;

I2SStream i2s;                       // der Audio-Ausgang
BluetoothA2DPSink a2dp_sink(i2s);    // Bluetooth schickt die Musik in den Ausgang

void setup() {
  Serial.begin(115200);
  pinMode(TASTE_ZURUECK, INPUT);
  pinMode(TASTE_PLAY, INPUT);
  pinMode(TASTE_WEITER, INPUT);
  pinMode(TASTE_MODUS, INPUT);

  // I2S-Pins einstellen und starten
  auto cfg = i2s.defaultConfig();
  cfg.pin_bck  = I2S_BCLK;
  cfg.pin_ws   = I2S_LRC;
  cfg.pin_data = I2S_DIN;
  i2s.begin(cfg);

  // Bluetooth starten. Diesen Namen sieht dein Handy:
  a2dp_sink.start("Retro Cassette");
  Serial.println("Retro Cassette gestartet - per Bluetooth verbinden");
}

// Wie lange eine Taste gedrueckt sein muss, damit es "lang" ist (Millisekunden)
const unsigned long LANG_DRUECKEN = 600;
// Lautstaerke-Schritt pro Wiederholung (0 = leise, 127 = laut)
const int LAUTSTAERKE_SCHRITT = 8;

// Wartet, bis die Taste losgelassen wird.
// Kurz gedrueckt  -> gibt true zurueck (dann Song wechseln)
// Lang gedrueckt  -> aendert waehrenddessen die Lautstaerke, gibt false zurueck
bool kurzOderLautstaerke(int taste, int richtung) {
  unsigned long start = millis();
  bool warLang = false;
  while (digitalRead(taste) == LOW) {
    if (millis() - start > LANG_DRUECKEN) {
      warLang = true;
      int lautstaerke = a2dp_sink.get_volume() + richtung * LAUTSTAERKE_SCHRITT;
      a2dp_sink.set_volume(constrain(lautstaerke, 0, 127));
      delay(150);
    }
    delay(10);
  }
  return !warLang;
}

void loop() {
  // ⏯ Play/Pause: Laeuft Musik, dann Pause, sonst Play
  if (digitalRead(TASTE_PLAY) == LOW) {
    if (a2dp_sink.get_audio_state() == ESP_A2D_AUDIO_STATE_STARTED) {
      a2dp_sink.pause();
    } else {
      a2dp_sink.play();
    }
    delay(300);
  }

  // ⏭ kurz: naechster Song, lang: lauter
  if (digitalRead(TASTE_WEITER) == LOW) {
    if (kurzOderLautstaerke(TASTE_WEITER, +1)) {
      a2dp_sink.next();
    }
    delay(50);
  }

  // ⏮ kurz: vorheriger Song, lang: leiser
  if (digitalRead(TASTE_ZURUECK) == LOW) {
    if (kurzOderLautstaerke(TASTE_ZURUECK, -1)) {
      a2dp_sink.previous();
    }
    delay(50);
  }

  // Work in progress (sobald die Platine da ist):
  // - Modus-Taste: Umschalten Bluetooth <-> MP3 von der SD-Karte
  // - MP3-Wiedergabe von der SD-Karte (SPI: CS 5, SCK 18, MISO 19, MOSI 23)
}
