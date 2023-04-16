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

[Tap hold](https://docs.qmk.fm/#/tap_hold) using [Okke's cheatsheet](https://cdn.discordapp.com/attachments/663573863480950808/757162393209012304/modtap.pdf) and [precondition's Home Row Mods Guide](https://precondition.github.io/home-row-mods#tap-hold-configuration-settings):

- [Ignore Mod-Tap Interrupt](https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt) - ignoring key presses that interrupt a mod-tap. That is to say, keys which get pressed while the mod-tap is held down do not automatically activate the modifier of the mod-tap. The mod-tap ignores the interruptions, hence the name. As long as your fingers don't linger on the keys for longer than the tapping term, you won't get accidental mod activations.
- [Quick Tap Term](https://docs.qmk.fm/#/tap_hold?id=quick-tap-term) - When the user holds a key after tapping it, the tapping function is repeated by default, rather than activating the hold function. This allows keeping the ability to auto-repeat the tapping function of a dual-role key.

Custom shift keys from [Getreuer - Custom shift keys](https://getreuer.info/posts/keyboards/custom-shift-keys/index.html) and Getreuer's [QMK Keymap repo](https://github.com/getreuer/qmk-keymap).
