#include <iostream>		// Input output stream from console
#include <fstream>      // Input output stream from file
#include <string>		// String Operations library
#include <sstream>      // String Stream Library
#include <algorithm>    // std::unique, std::distance
#include <vector>		// Vector library
#include "input_data.h"    // Input data formatting library
#include "decision_tree.h" // Decision Tree library

using namespace std;    // Standard Name Space

int main()
{


	DataTable weatherData("weatherFile.txt"); // Here we create data table using weather data

	weatherData.outputData();                 // Here we check the data table

	vector<string> indepColumnNames{"Outlook", 
		"Temperature", "Humidity", "Wind"};			  // Independent variables
	vector<string> depColumnName{ "Decision" };		  // Dependent variable			
	DecisionTree weatherTree(weatherData, 
		indepColumnNames, depColumnName);			  // Here we initiate the decision tree model

	weatherTree.printGiniIndex();

	for (auto giniOrder : weatherTree.getFeatureOrder())
		cout << giniOrder << endl;

	weatherTree.setBranches();
	/*
	vector<Column> X = weatherData.returnColumns(indepColumnNames);
	Column y(depColumnName, weatherData.returnColumn(depColumnName));
	*/



	//outlookColumn.printUniques();

	return 0;
}
