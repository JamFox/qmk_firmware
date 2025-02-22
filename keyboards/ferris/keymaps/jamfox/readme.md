# JamFox's Ferris Sweep v2.2 RP2040 keymap

* Keyboard Maintainer: [Pierre Chevalier](https://github.com/pierrechevalier83)
* Hardware Supported: [Sweep](https://github.com/davidphilipbarr/Sweep) (all versions)
* Hardware Availability: Print the PCB with gerber files from the repository

## Sea-Picro RP2040 Controller

- [Sea-Picro](https://joshajohnson.com/sea-picro/)
- [QMK Raspberry Pi RP2040 Dev](https://docs.qmk.fm/#/platformdev_rp2040)

Sea-Picro can work with most existing Pro-Micro compatible keyboards on the market, you just need to recompile the firmware to suit Sea-Picro first. You cannot use an existing `.hex` file.

Pro Micro RP2040 controllers are supported with [QMK Converters](https://docs.qmk.fm/#/feature_converters). As Sea-Picro has the same pinout as the RP2040 Pro Micro, we can use the `promicro_rp2040` converter to remap the pins:

```bash
qmk flash -c -kb chalice -km default -e CONVERT_TO=promicro_rp2040
```

Setting handedness:

```bash
make CONVERT_TO=promicro_rp2040 ferris/sweep:default:uf2-split-left
make CONVERT_TO=promicro_rp2040 ferris/sweep:default:uf2-split-right
```

Change `MCU` to `RP2040` and `BOOTLOADER` to `rp2040` in `rules.mk`.

Update `MATRIX_ROW_PINS` and `MATRIX_COL_PINS` in `config.h` - Search pro micro and the Sparkfun RP2040, get pinouts for both, and rename the pins one by one, so like F6, B3, B2 becomes GP27, GP20, GP23 - when you look at the pinouts this should make more sense.

There's a compile command to convert to a Sea Picro and get a .UF2 file. I was able to successfully compile a .UF2 file using QMK MSYS, with the command:

`qmk compile -kb ferris/sweep -km via -e CONVERT_TO=promicro_rp2040`

Then you would just need to flash that .UF2 file once, and assuming Via still supports the keyboard after the conversion, you would then be able to change the layout of your keyboard straight from an internet browser on any computer. I've never actually used Via, so my understanding may be incorrect, but it seems fairly straightforward.

Ferris Sweep uses EEPROM to set which side each half of the board is. EEPROM data is not part of a compiled firmware file. QMK Toolbox apparently has an option to set the handedness in EEPROM when flashing, but we were getting errors, so chose to switch to hardcoded handedness instead since OP always plugs his USB into the same side.

In `config.h`, change `#define EE_HANDS` to `#define MASTER_LEFT` or `MASTER_RIGHT`. This will require you to always plug USB into the left or right side, respectively, otherwise your layout will be flipped. Save the file and compile with the above command, then flash that to both sides normally.

## Reset / Bootloader Control

Due to how the RP2040 microcontroller on Sea-Picro functions, the reset button behaves differently to traditional Pro Micro based controllers.

- Tapping the reset button for < 500ms will cause the board to reset and your code to start running again.
- Holding the reset button for > 1 second will cause the board to go into bootloader mode and allow you to flash new code.

QMK has added a "double tap for bootloader" feature for RP2040 boards, however due to the implementation on Sea-Picro this may not work and it’s suggested to hold the reset button to get into bootloader mode.

## Compiling / Flashing

Compile:

1. Change `MCU` to `RP2040` and `BOOTLOADER` to `rp2040` in `rules.mk`.
2. Compile using the `CONVERT_TO=promicro_rp2040` [converter](https://docs.qmk.fm/#/feature_converters).

Flash:

1. Compile your code as outlined above.
2. Place the board into bootloader by holding the `RESET` button or using the `QK_BOOT` keycode.
3. Once a drive called `RPI-RP2` is detected, drag the `.uf2` file generated by QMK onto the drive.
4. The `RPI-RP2` drive will disappear and a few seconds later your keyboard will be ready for use.

## Keymap

[Estonian keymap](https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_estonian.h) from [QMK Language-specific Keycodes](https://docs.qmk.fm/#/reference_keymap_extras).
