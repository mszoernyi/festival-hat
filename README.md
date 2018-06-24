# Festival Hat

![FloraLED](https://github.com/mszoernyi/festival-hat/raw/master/flora.gif)

Festival Hat is a simple adruino controller for a custom build LED hat.

# Getting Started

PlatformIO is used as build path which is available as CLI or IDE integration. In case you have PlatformIO setup already you can skip this step.

1. Install [Platform IO](https://platformio.org/)
2. (optional) Install VS Code extension `platformio.platformio-ide`
2. Clone repository with `git clone https://github.com/mszoernyi/festival-hat.git`
3. Edit `platformio.ini` and adjust USB port for serial monitoring.
3. Build project with `ctrl+alt+b` / `pio build`
4. Upload project to controller with `ctrl+alt+u` / `pio upload`

# Used component

- FastLED for LED control
- Animately for non-blocking animations
- AceButton for non-blocking button handling

# Concepts

## Scenes

Scenes are used to describe an animation sequence for LED strips. Take a look into the `Strobe` for details.

# Roadmap / Ideas

- Add multiple scenes to switch between with button
- Add RF logic to commuicate with other hats
- Add Gyro to switch animation based on movements
