#pragma once


#ifdef __linux__ 
	// Linux Code
#elif _WIN32
	class Sensors
	{
	private:
		/*
		 * @brief Stores Raw Data from sensors
		 * var: _rawData (Array short int)
		 * [0] = HRM Sensor raw value, [1] = O2Sat Sensor raw value, [2] = RR Sensor raw value
		 */
		short int _rawData[3];


		/*
		 * @brief Start Bluetooth Low Energy Service
		 *
		 * Use the interface to make a BLE API Object
		 * Windows BLE API: https://github.com/urish/win-ble-cpp/tree/master
		 */
		void init_BLE();




	public:
		/*
			 function: Sensors()
			 use case: Constructor of Sensors Class

			 vars: isHRM (bool, true if use of Hear Rate Monitor), isOxSat (bool, true if use of O2Sat), isRR (bool, true if use of Respiratory Rate Monitor),
			 conType[] (bool array, true if BLE, false if Wired, [0] = HRM Sensor, [1] = O2Sat Sensor, [2] = RR Sensor)

			 Create an object while storing what the user will connect to the software
		*/

		Sensors(bool isHRM, bool isOxSat, bool isRR, bool conType[]);
		~Sensors();

		short int get_RawHRData();
		short int get_RawOxSatData();
		short int get_RawRRData();
		bool ready = false;
	};
#elif __APPLE__

#else

#endif



