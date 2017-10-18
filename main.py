# CircuitPython 2.0.0 - Trinket M0
# 3 led bounce:
#  LED anodes to D0, D1 & D2
#   cathodes common thru 330 Ω resistor to GND
# scruss - 2017-10

import board
import digitalio
import time

leds = [ digitalio.DigitalInOut(board.D0),
         digitalio.DigitalInOut(board.D1),
         digitalio.DigitalInOut(board.D2) ]
for i in range(3):
    leds[i].direction = digitalio.Direction.OUTPUT

led=0
delta=1
while True:
    leds[led].value = True # on
    print("LED %1d on" % (led))
    time.sleep(0.4)
    leds[led].value = False # off
    print("LED %1d off" % (led))
    led = led + delta
    if (led != 1):
        delta = -delta
