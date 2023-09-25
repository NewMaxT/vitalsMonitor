#include <iostream>

int main()
{
    char buffer;

    std::cout << "******************************************************************\n";
    std::cout << "ECG, SpO2, Blood Pressure and Respiratory Rate monitoring software\n\n";

    std::cout << "                           Starting...\n\n\n";

    try
    {
        /* MANAGE HARDWARE */

        /* CODE HERE */

        if (true) {
            std::cout << "HARDWARE API " << "\033[1;32m" << "OK" << "\033[1;0m\n";
        }
        else {
            throw std::runtime_error("HARDWARE API STARTUP FAILURE");
        }

        /* MANAGE BLUETOOTH LOW ENERGY */

        /* CODE HERE */

        if (true) {
            std::cout << "BLE " << "\033[1;32m" << "OK" << "\033[1;0m\n";
        }
        else {
            throw std::runtime_error("BLE STARTUP FAILURE");
        }

        /* MANAGE THREADS AND ASYNC FUNCTIONS */

        /* CODE HERE */

        if (true) {
            std::cout << "THREADS " << "\033[1;32m" << "OK" << "\033[1;0m\n\n";
        }
        else {
            throw std::runtime_error("THREADS STARTUP FAILURE");
        }


    }
    catch (const std::exception& exc)
    {
        std::cout << "\033[1;31m" << "FATAL: " << exc.what() << "\033[1;0m\n";
        std::cout << "\033[7;31m" << "FATAL: " << "STARTUP FAILURE" << "\033[1;0m\n\n";
        std::cout << "\033[7;31m" << "FATAL: " << "Enter to quit the program..." << "\033[1;0m";
        std::cin.get();
        throw exc;
    }


    std::cout << "WAITING FOR SENSORS\n\n";


    std::cout << "\033[7;32mSTARTED UP\033[4;0m\n";

    std::cout << "\033[1;32mSTARTING GUI\033[1;0m\n";


}



