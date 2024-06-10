// Implementation File

/*
	Here we create a class to read input data and format it to feed Machine Learning Algorithms
*/

#include "input_data.h"

// Constructor for Data Table Class
DataTable::DataTable(string inputFileName)
{
	this->inputFileName = inputFileName;
	this->inputFile.open(this->inputFileName); // Here we open the name file

	// Here we read data line by line before separating column names and data
	while (!this->inputFile.eof())
	{
		getline(this->inputFile, this->inputData);		// get line help us to read entire line
		this->inputVector.push_back(this->inputData);   // Raw data including column names
	}

	
	// Here we output input data to check if we read it correctly
	for (int i = 0; i < this->inputVector.size(); i++)
	{
		if (i == 0)
			this->inputTitles = simple_tokenizer(this->inputVector[i]);			// Here we get the titles in the table data
		else 
			this->dataFields.push_back(simple_tokenizer(this->inputVector[i])); // Actual Data
	}	


	// Here we clear the input vector to open space
	this->inputVector.clear();

	for (int i = 0; i < this->dataFields.size(); i++)
		cout << this->dataFields[i][2] << endl;
	
	
}

// A quick way to split strings separated via spaces.
vector<string> DataTable::simple_tokenizer(string s) const
{
	stringstream ss(s);
	string word;
	vector<string> dataLine;

	while (ss >> word) {
		dataLine.push_back(word);
	}

	return dataLine;
}

// A quick way to output data.
void DataTable::outputData() const
{
	// Output titles
	for (auto data : this->inputTitles)
		cout << data << " ";
	// Start new line
	cout << endl;

	// Output data
	for (auto dataLine : this->dataFields)
	{
		for (auto data : dataLine)
			cout << data << " ";
		// Start new line
		cout << endl;
	}
}

vector<string> DataTable::columns() const
{
	return this->inputTitles;
}