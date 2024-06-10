#include <iostream>		// Input output stream from console
#include <fstream>      // Input output stream from file
#include <string>		// String Operations library
#include <sstream>      // String Stream Library
#include <vector>		// Vector library
#include "input_data.h" // Input data formatting library

using namespace std;    // Standard Name Space

int main()
{


	DataTable weatherData("weatherFile.txt"); // Here we create data table using weather data

	for (auto columnName : weatherData.columns())
		cout << columnName << " ";
	cout << endl;

	weatherData.outputData();

	return 0;
}
