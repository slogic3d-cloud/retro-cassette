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

  // ⏭ naechster Song
  if (digitalRead(TASTE_WEITER) == LOW) {
    a2dp_sink.next();
    delay(300);
  }

  // ⏮ vorheriger Song
  if (digitalRead(TASTE_ZURUECK) == LOW) {
    a2dp_sink.previous();
    delay(300);
  }

  // TODO: Modus-Taste (Bluetooth <-> SD-Karte), Lautstaerke per langem Druck, MP3 von SD
}
