// Implementation File

/*
	Here we create a class to read input data and format it to feed Machine Learning Algorithms
*/

#include "input_data.h"

/*

	Column Class Member Functions

*/

// Constructor for Column Class
Column::Column(string columnName, vector<string> columnData)
{
	this->columnName = columnName; // Here we set the column name

	// Here we read data line by line before separating column names and data
	for (string data : columnData)
		this->columnData.push_back(data);

	this->uniqueValues = findUniques(); // Here we find the unique values
	this->uniqueCounts = countUniques(); // Here we find the count of unique values
}

// Sets column for given data
void Column::setColumn(string columnName, vector<string> columnData)
{
	this->columnName = columnName; // Here we set the column name

	// Here we read data line by line before separating column names and data
	for (string data : columnData)
		this->columnData.push_back(data);

	this->uniqueValues = findUniques(); // Here we find the unique values
	this->uniqueCounts = countUniques(); // Here we find the count of unique values
}

// Returns column data
vector<string> Column::getColumnData() const
{
	return this->columnData;
}

// Print out the column data
void Column::printColumnData() const
{

	for (auto data : this->columnData)
		cout << data << endl;
}

// A quick way to return unique values in a column data.
vector<string> Column::findUniques()
{

	vector<string> columnData = getColumnData();		// Retreive a column data;

	// Here we return unique elements
	sort(columnData.begin(), columnData.end());		     // First sort it
	auto uniqueData = unique(columnData.begin()
		, columnData.end()); // Here we define it as an iterator to point out unique element
	columnData.erase(uniqueData, columnData.end());      // Here we remove duplicates

	return columnData;
}

// Returns unique values
vector<string> Column::getUniques() const
{
	return this->uniqueValues;
}


// A quick way to return counts of unique values in a column data.
vector<int> Column::countUniques() 
{

	vector<int> uniqueCounts;                             // Here we store the unique values
	int counter = 0;

	for (auto unique : this->uniqueValues)
	{
		for (auto data : this->columnData)
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

// Returns unique values
vector<int> Column::getUniqueCounts() const
{
	return this->uniqueCounts;
}

// Print out the column data
void Column::printUniques() const
{

	for (int i = 0; i < this->uniqueValues.size(); i++)
		cout << this->uniqueValues[i] << " " << this->uniqueCounts[i] << endl;
}

/*

	Data Table Class Member Functions

*/


// Constructor for Data Table Class
DataTable::DataTable(string inputFileName)
{
	ifstream inputFile;                 // Here we read the input file
	string  inputData;					// Here we create a vector to store each line in the input
	vector<string> inputVector;			// Here we create a vector to store the raw data in the input file

	this->inputFileName = inputFileName;
	inputFile.open(this->inputFileName); // Here we open the name file

	// Here we read data line by line before separating column names and data
	while (!inputFile.eof())
	{
		getline(inputFile, inputData);		// get line help us to read entire line
		inputVector.push_back(inputData);   // Raw data including column names
	}

	// Here we close the input file 
	inputFile.close();
	
	// Here we output input data to check if we read it correctly
	for (int i = 0; i < inputVector.size(); i++)
	{
		if (i == 0)
			this->inputTitles = simple_tokenizer(inputVector[i]);			// Here we get the titles in the table data
		else 
			this->dataFields.push_back(simple_tokenizer(inputVector[i]));   // Actual Data
	}	

	// Here we create column pointer vector
	for (string columnName : this->inputTitles)
	{
		// Here we add a new employee as many as we want
		Column tempColumn(columnName, returnColumn(columnName));
		columns.push_back(tempColumn);
	}

	// Here we clear the input vector to open space
	inputVector.clear();
	
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
vector<string> DataTable::columnNames() const
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

// A quick way to return a given column data.
vector<Column> DataTable::returnColumns(vector<string> columnNames) const
{
	vector<Column> columns;

	for (string columnName : columnNames)
	{
		// Here we return the corresponding index
		auto it = find(this->inputTitles.begin(), this->inputTitles.end(), columnName);

		// If element was found 
		if (it != this->inputTitles.end())
		{

			// calculating the index of columnName 
			int index = it - this->inputTitles.begin();
			// Output the data
			columns.push_back(this->columns[index]);
		}
		else {
			// If the element is not present in the vector, print out it does not have the column name
			cout << "You don't have such a column" << endl;
		}

	}
	

	return columns;
}


// A quick way to print a given column data.
void DataTable::printColumnSummary(string columnName) const
{
	

	// Here we return the corresponding index
	auto it = find(this->inputTitles.begin(), this->inputTitles.end(), columnName);


	// If element was found 
	if (it != this->inputTitles.end())
	{
		// calculating the index of columnName 
		int index = it - this->inputTitles.begin();
		// Output the data            
		this->columns[index].printUniques();
	}
	else {
		// If the element is not present in the vector, print out it does not have the column name
		cout << "You don't have such a column" << endl;
	}
}

