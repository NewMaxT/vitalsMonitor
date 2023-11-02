[![Issues](https://img.shields.io/github/issues-raw/NewMaxT/vitalsMonitor?label=Issues&style=for-the-badge)]()
[![Build Status](https://img.shields.io/github/actions/workflow/status/NewMaxT/vitalsMonitor/msbuild.yml?style=for-the-badge)]()

/!\ WIP

# ECG, SpO2, Blood Pressure and Respiratory Rate monitoring software

Reliable C++ Software that can monitor and save data locally of you vitals constants.
For security purposes, the software will only be able to read selected wireless sensors hardware (e.g. Polar H10) 

Built with SDL2, C++ and Visual Compiler

## Repo Structure :open_file_folder:

```markdown
* vitalsMonitor/
  * (Headers Files)
  * (Sources Files)
  * CMakeLists.txt (Thanks to @Albrecht-S)
  * libs/
    * (GUI Librairie files)
 
* LICENCE.txt
```


## Features

- Accurate monitoring of Heart Rate and ECG
- SpO2, Blood Pressure and Respiratory Rate monitoring 
- Reliable and Open-Source.
- Runs on cheap embedded hardware. (e.g. Raspberry Pi, Must have at least BLE capabilities)
- Easy configuration (GUI Configuration)
- Live Console to monitor issues (can be disabled, requires more computing)

## Compatible Hardware

- Pulsar H10, [Buy now](https://www.polar.com/ca-fr/sensors/h10)

## Compatible Software

- Windows 11, WIP
- Linux (Raspberry Pi and RHEL-like distros), WIP 
- Mac, not planned

### TODO LIST :pushpin:

```markdown
- [ ] Connection with sensors (see Compatible Hardware section)
- [ ] Hardware Testing (Raspberry Pi 3/4 with FHD screen, basic computer)
- [~] GUI Interface (Data Monitoring and Settings)
- [ ] Heart Rate (BPM) and EKG/ECG (mV)
- [ ] SpO2 (%)
- [ ] Blood Pressure (NIBP/mmHg)
- [ ] Skin Temperature (°C or °F)
- [ ] Respiratory Rate (Dimensionless Quantity, unitless)
```

## __DISCLAIMER__


**This software is provided "as is," without warranty of any kind, express or implied.**
**Use it at your own risk. The author and contributors are not liable for any damages or issues arising from the use of this software.**

**The data accuracy relies mostly on the hardware, choose the equipment thoughtfully.**
**

```
Note :
Monitoring devices MUST to be isolated from electrical grid to avoid accidental shocks
This software is not a substitute for medical-grade equipment.
It should be used for informational and educative purposes only.
if the software detects any anomalies or irregularities,
It is strongly recommended  to promptly share the data generated by this software with an healthcare professionals.
and it is strongly advised to take subsequent test with a certified medical equipment for precise and reliable health assessments.
```

## Fix Notes :loudspeaker:

```markdown
v0 - 2023-10-26
    * Lorem Ipsum
```

## Documentations

 - [Raspberry Docs](https://www.raspberrypi.com/documentation/)
 - [BLE on Windows](https://github.com/urish/win-ble-cpp)
 - [SDL2 Documentation](https://wiki.libsdl.org/SDL2/FrontPage)

## Tools used
<div width="100%">
 <a href="https://jetbrains.com"><img src="https://resources.jetbrains.com/storage/products/company/brand/logos/CLion.png" alt="CLion" height="200px"/></a>
</div>
