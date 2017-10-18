/*
   3-led bounce for edge-lit flying toaster
   circuit: three LEDs connected to D5, 6 & 7 with
            cathodes common through 330 Ω resistor to GND
   converted from MicroPython to Arduino
   scruss - 2017-10 - for Elmwood Electronics
*/

int led = 0;
int delta = 1;

/*
   Sketch relies on three adjacent digital IO pins.
   Doesn't much matter which IO pins, they just have
    to be numbered consecutively.

   basepin is set to the lowest-numbered pin,
    so if basepin = 5, we use D5, D6 & D7
*/
int basepin = 5;

void setup() {
  // D5, D6 & D7 outputs
  pinMode(basepin + 0, OUTPUT);
  pinMode(basepin + 1, OUTPUT);
  pinMode(basepin + 2, OUTPUT);
}

void loop() {
  // light LEDs every 0.4 s in sequence 01210121 …
  digitalWrite(basepin + led, HIGH);
  delay(400);
  digitalWrite(basepin + led, LOW);
  led += delta;
  if (led != 1) {
    // reverse direction if at highest or lowest LED
    // (world's simplest Larson scanner …)
    delta = -delta;
  }
}
