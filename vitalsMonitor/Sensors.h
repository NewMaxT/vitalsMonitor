#pragma once
#include <vector>


#ifdef __linux__ 
	// Linux Code
#elif _WIN32
	/*
			@brief Sensors Class.
			@brief Handles the hardware sensors and data stream.
	*/
	class Sensors
	{
	private:
		/*
		 * @brief Stores Raw Data from sensors.
		 * @brief [0] = HRM Sensor raw value, [1] = O2Sat Sensor raw value, [2] = RR Sensor raw value.
		 */
		short int _rawData[3];


		/*
		 * @brief Start Bluetooth Low Energy Service.
		 * @brief Use the interface to make a BLE API Object.
		 * @see Windows BLE API: https://github.com/urish/win-ble-cpp/tree/master
		 */
		void init_BLE();




	public:
		/*
			 @brief Constructor of Sensors Class.
			 @brief Creates an object of the class Sensors.

			 @param[in] isHRM (bool, true if use of Hear Rate Monitor)
			 @param[in] isOxSat (bool, true if use of O2Sat)
			 @param[in] isRR (bool, true if use of Respiratory Rate Monitor),
			 @param[in] conType[] (bool array, true if BLE, false if Wired, [0] = HRM Sensor, [1] = O2Sat Sensor, [2] = RR Sensor)
		*/
		Sensors(bool isHRM, bool isOxSat, bool isRR, bool conType[]);
		~Sensors();

		short int get_RawHRData();
		short int get_RawOxSatData();
		short int get_RawRRData();
		std::vector<float> get_SampleData();
		bool ready = false;
	};
#elif __APPLE__

#else

#endif



