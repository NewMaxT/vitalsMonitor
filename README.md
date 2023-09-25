[![Issues](https://img.shields.io/github/issues-raw/NewMaxT/OpenCV-Face-Tracking?label=Issues&style=for-the-badge)]()

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
 <a href="https://opencv.org/"><img src="https://github.com/opencv/opencv/wiki/logo/OpenCV_logo_black.png" alt="OpenCV" height="200px"/></a>
</div>
