E-TEXTILE MATRIX SENSOR
=========

 - Purpose: 16x16 e-textile matrix sensors
 - Copyright (c) 2014 Maurin Donneaud : http://etextile.org
 - Licence : GNU GENERAL PUBLIC LICENSE


The only components essential with the Teesy board are 10K resistor ladder.
To make a voltage divider for each column, every resistor are connected between an analog input pins and VCC (3.3V).

Partslist
=====

| Part        |    Value                     |     Device              |          Package     |
|-------------|:-----------------------------|:------------------------|:---------------------|
ANALOG_INPUT  | 3.3V                         | PINHD-1X16/90           | 1X16/90              |
ANALOG_INPUT1 | 3.3V                         | PINHD-1X16              | 1X16                 |
C1            | 4.7uF                        | CAP0805                 | 0805                 |
C2            | 4.7uF                        | CAP0805                 | 0805                 |
C3            | 10uf                         | CPOL-EUE1.8-4           | E1,8-4               |
D1            | RED                          | LED1206                 | LED-1206             |
D11           | RED                          | LED1206                 | LED-1206             |
DIGITAL_OUT   |                              | PINHD-1X16/90           | 1X16/90              |
DIGITAL_OUT1  | 3.3V                         | PINHD-1X16/90           | 1X16/90              |
JP7           | LiPo Battery                 | M02-JST-2MM-SMT         | JST-2-SMD            |
R1            | 2K                           | RESISTOR0805-RES        | 0805                 |
R2            | 330                          | RESISTOR0805-RES        | 0805                 |
R3            | 330                          | RESISTOR0805-RES        | 0805                 |
RN1           | 3.3V                         | G08R                    | SIL9                 |
RN2           | 3.3V                         | G08R                    | SIL9                 |
S1            | SWITCH                       | SWITCH-SPSTSMD          | AYZ0202              |
SWITCH1       | SWITCH-MOMENTARY-2           | SWITCH-MOMENTARY-2      | TACTILE_SWITCH_TALL  |
U$1           | TEENSY_3.1_ALL_PINS_AND_PADS | TEENSY_3.1_ALL_PINS_AND_PADS | TEENSY_3.1_ALLPINS   |
U1            | MCP73831                     | MCP73831                     | SOT23-5              |
U3            |                              | AUDIO-JACKSMD2               | AUDIO-JACK-3.5MM-SMD |

## TODO
- Replace the Teensy With an other chip 
- Make the design with Upverter