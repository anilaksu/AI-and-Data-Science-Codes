// Specification File

/*
	Here we create a class to read input data and format it to feed Machine Learning Algorithms
*/

#include <iostream>		// Input output stream from console
#include <fstream>      // Input output stream from file
#include <string>		// String Operations library
#include <sstream>      // String Stream Library
#include <vector>		// Vector library

using namespace std;

#ifndef DATATABLE_H
#define DATATABLE_H

class DataTable {
public:

	// Constructor
	DataTable();
	DataTable(string inputFile); // For reading name file via COnstructor

	// Destructor
	//~DataTable();

	// Member functions

	// Setter functions sets fields in private
	//virtual void setHeight(double height);
	
	// Getter functions access fields in private
	virtual vector<string> simple_tokenizer(string s) const; // Tokenizes line of data
	virtual vector<string> columns() const;				     // Returns column names
	virtual void outputData() const;

private: // Private member is only accessible within a function

	// Data Members or Fields
	string inputFileName;
	ifstream inputFile;
	string  inputData;					// Here we create a vector to store each line in the input
	vector<string> inputVector;			// Here we create a vector to store the raw data in the input file
	vector<string> inputTitles;			// Here we read input table titles
	vector<vector<string>> dataFields;  // Here we create a vector to store the data in the table form
	

}; // end of the class Data Table

#endif 