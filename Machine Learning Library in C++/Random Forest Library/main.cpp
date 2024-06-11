#include <iostream>		// Input output stream from console
#include <fstream>      // Input output stream from file
#include <string>		// String Operations library
#include <sstream>      // String Stream Library
#include <algorithm>    // std::unique, std::distance
#include <vector>		// Vector library
#include "input_data.h" // Input data formatting library

using namespace std;    // Standard Name Space

int main()
{


	DataTable weatherData("weatherFile.txt"); // Here we create data table using weather data

	weatherData.outputData();
	
	// Here we output a given column
	string columnName = "Outlook";
	vector<string> uniqueData = weatherData.returnUniques(columnName);	  // Retreive unique values in temperature data
	vector<int> uniqueCount = weatherData.returnUniqueCounts(columnName); // Retreive counts of  unique values in temperature data
	
	for (int i = 0; i < uniqueData.size(); i++)
		cout << uniqueData[i] << " " << uniqueCount[i] << endl;

	return 0;
}
