[![Issues](https://img.shields.io/github/issues-raw/NewMaxT/vitalsMonitor?label=Issues&style=for-the-badge)]()
[![Build Status](https://img.shields.io/github/actions/workflow/status/NewMaxT/vitalsMonitor/msbuild.yml?style=for-the-badge)]()

/!\ WIP

# ECG, SpO2, Blood Pressure and Respiratory Rate monitoring software

Reliable C++ Software that can monitor and save data locally of you vitals constants.
For security purposes, the software will only be able to read selected, wireless sensors hardware (e.g. Polar H10) (Needs to be isolated from electrical grid to avoid accidental shocks)

## Repo Structure :open_file_folder:

```markdown
* vitalsMonitor/
  * (Headers Files)
  * (Sources Files)
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
- Linux, WIP
- Mac, Not Planned

### TODO LIST :pushpin:

```markdown
- [ ] Connection with sensors
- [ ] Hardware Testing (Raspberry Pi 3)
- [ ] GUI Interface (Data Monitoring and Settings)
- [ ] Heart Rate calculations
- [ ] SpO2 data reading
- [ ] Blood Pressure data reading
- [ ] Respiratory Rate
```

## Fix Notes :loudspeaker:

```
FIX NOTES
```

## Documentations

 - [Raspberry Docs](https://www.raspberrypi.com/documentation/)

## Tools used
<div width="100%">
 <a href="https://jetbrains.com"><img src="https://resources.jetbrains.com/storage/products/company/brand/logos/CLion.png" alt="CLion" height="200px"/></a>
</div>
