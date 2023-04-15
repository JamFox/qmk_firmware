# JamFox's Helidox Corne Choc keymap

* Keyboard Maintainer: [foostan](https://github.com/foostan/) [@foostan](https://twitter.com/foostan)  
* Hardware Supported: Crkbd PCB, Pro Micro  
* Hardware Availability: [PCB & Case Data](https://github.com/foostan/crkbd)

## Elite-C ATmega32U4 Controller

Compile:

- `qmk compile -kb crkbd -km jamfox`

Flash:

1. Compile your code as outlined above.
2. Open [QMK Toolbox](https://github.com/qmk/qmk_toolbox)
3. Press the reset button on the PCB
4. Select the `.hex` file from the root of the `qmk_firmware` folder
5. Flash

## Keymap

[Estonian keymap](https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_estonian.h) from [QMK Language-specific Keycodes](https://docs.qmk.fm/#/reference_keymap_extras).
