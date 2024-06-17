// Specification File

/*
	Here we create a class to read input data and format it to feed Machine Learning Algorithms
*/

#include <iostream>		// Input output stream from console
#include <fstream>      // Input output stream from file
#include <string>		// String Operations library
#include <sstream>      // String Stream Library
#include <vector>		// Vector library
#include <algorithm>    // std::unique, std::distance

using namespace std;


#ifndef COLUMN_H
#define COLUMN_H

class Column {
public:

	// Constructor
	Column();
	Column(string columnName, vector<string> columnData); // For building a column via COnstructor

	// Destructor
	//~Column();

	// Member functions

	// Setter functions sets fields in private
	virtual void setColumn(string columnName, vector<string> columnData); // For building a column via externally

	// Getter functions access fields in private
	virtual vector<string> getColumnData() const;					  // Returns column data
	virtual void printColumnData() const;					  // Returns column data
	virtual vector<string> findUniques();				  // Finds the unique values in column data
	virtual vector<string> getUniques() const;					  // Returns the unique values in column data
	virtual vector<int> countUniques();               // Counts each unique value in the entire data table
	virtual vector<int> getUniqueCounts() const;      // Returns the counts of unique values in column data
	virtual void printUniques() const;				  // Returns the unique values and their count in column data

	/*virtual vector<string> simple_tokenizer(string s) const;		      // Tokenizes line of data
	
	virtual vector<string> returnColumn(string columnName) const;         // Returns the column data
	
	virtual vector<int> returnUniqueCounts(string columnName) const;   // Returns the counts of unique values in column data

	// Output functions
	virtual void outputData() const;                         // Outputs the entire dataset
	virtual void outputColumn(string columnName) const;      // Outputs the entire dataset*/

private: // Private member is only accessible within a function

	// Data Members or Fields
	string columnName;           // Column Name
	vector<string> columnData;	 // Here we create a vector to store the column
	vector<string> uniqueValues; // Here we store the unique values
	vector<int> uniqueCounts;	 // Here we store the count of unique values

}; // end of the class Column

#endif 

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
	virtual vector<string> simple_tokenizer(string s) const;		            // Tokenizes line of data
	virtual vector<string> columnNames() const;							        // Returns column names
	virtual vector<string> returnColumn(string columnName) const;				// Returns the column data
	virtual vector<Column> returnColumns(vector<string> columnNames) const;     // Returns the columns in a column data format

	// Output functions
	virtual void outputData() const;                          // Outputs the entire dataset
	virtual void printColumnSummary(string columnName) const; // Outputs a given column summary

private: // Private member is only accessible within a function

	// Data Members or Fields
	string inputFileName;
	vector<string> inputTitles;			// Here we read input table titles
	vector<vector<string>> dataFields;  // Here we create a vector to store the data in the table form
	vector <Column> columns;			// Here we create a pointer vector to store all columns

}; // end of the class Data Table

#endif 



