#include <iostream>
#include "Sensors.h"


#ifdef __linux__ 
// Linux Code
#elif _WIN32

	Sensors::Sensors(bool isHRM, bool isOxSat, bool isRR, bool conType[]) {
		init_BLE();
	};

	Sensors::~Sensors()
	{
	}

	void Sensors::init_BLE() {
		ready = true;
	}

	short int Sensors::get_RawHRData() {
		return _rawData[0];
	}

	short int Sensors::get_RawOxSatData() {
		return _rawData[1];
	}
	short int Sensors::get_RawRRData() {
		return _rawData[2];
	}

#elif __APPLE__

#else

#endif


