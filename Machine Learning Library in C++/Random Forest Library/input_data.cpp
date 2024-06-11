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

	// Here we close the input file 
	inputFile.close();
	
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
	// Add an empty line to separate the next output
	cout << endl;
}

// Returns all column names
vector<string> DataTable::columns() const
{
	return this->inputTitles;
}

// A quick way to return a given column data.
vector<string> DataTable::returnColumn(string columnName) const
{
	vector<string> columnData;
	// Here we return the corresponding index
	auto it = find(this->inputTitles.begin(), this->inputTitles.end(), columnName);

	// If element was found 
	if (it != this->inputTitles.end())
	{

		// calculating the index of columnName 
		int index = it - this->inputTitles.begin();
		// Output the data
		for (int i = 0; i < this->dataFields.size(); i++)
			columnData.push_back(this->dataFields[i][index]);
	}
	else {
		// If the element is not present in the vector, print out it does not have the column name
		cout << "You don't have such a column" << endl;
	}

	return columnData;
}

// A quick way to return unique values in a column data.
vector<string> DataTable::returnUniques(string columnName) const
{

	vector<string> columnData = returnColumn(columnName); // Retreive a column data;
	// Here we return the corresponding index
	auto it = find(this->inputTitles.begin(), this->inputTitles.end(), columnName);

	// Here we return unique elements
	sort(columnData.begin(), columnData.end());		     // First sort it
	auto uniqueData = unique(columnData.begin()
		, columnData.end()); // Here we define it as an iterator to point out unique element
	columnData.erase(uniqueData, columnData.end());      // Here we remove duplicates

	return columnData;
}

// A quick way to return counts of unique values in a column data.
vector<int> DataTable::returnUniqueCounts(string columnName) const
{

	vector<string> columnData = returnColumn(columnName); // Retreive a column data
	vector<string> uniqueData = returnUniques(columnName);// Retreive unique values a column data
	
	vector<int> uniqueCounts;                             // Here we store the unique values
	int counter = 0;

	for (auto unique : uniqueData)
	{
		for (auto data : columnData)
		{
			if (data == unique)
				counter++;
			else
				continue;
		}
		uniqueCounts.push_back(counter); // Here we add the count of the unique element
		counter = 0;					 // Here we reset the counter
	}

	return uniqueCounts;
}

// A quick way to output column data.
void DataTable::outputColumn(string columnName) const
{
	// Here we return the corresponding index
	auto it = find(this->inputTitles.begin(), this->inputTitles.end(), columnName);

	// If element was found 
	if (it != this->inputTitles.end())
	{

		// calculating the index of columnName 
		int index = it - this->inputTitles.begin();
		// Output the data
		for (int i = 0; i < this->dataFields.size(); i++)
			cout << this->dataFields[i][index] << endl;
	}
	else {
		// If the element is not present in the vector, print out it does not have the column name
		cout << "You don't have such a column" << endl;
	}
}