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
	weatherData.printColumnSummary(columnName);

	vector<string> indepColumnNames{"Outlook", 
		"Temperature", "Humidity", "Wind"};   // Independent variables
	string depColumnName{ "Decision" };		  // Dependent variable				    
	vector<Column> X = weatherData.returnColumns(indepColumnNames);
	Column y(depColumnName, weatherData.returnColumn(depColumnName));

	for (auto column : X)
		column.printColumnData();



	//outlookColumn.printUniques();

	return 0;
}
