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
#include "input_data.h" // Input Data Classes

using namespace std;


#ifndef DECISIONTREE_H
#define DECISIONTREE_H

class DecisionTree {
public:

	// Constructor
	DecisionTree();
	DecisionTree(DataTable data, vector<string> X_columns, vector<string> y_columns); //  Constructor

	// Destructor
	//~DecisionTree();

	// Member functions

	// Setter functions sets fields in private
	//virtual long getInformationEntropy(Column x);			// Calculates the information entropy of a given column
	virtual vector<double> calculateGiniIndex(Column x);    // Calculates the Gini Index of a given column
	virtual void setBranches();				// Generates branches of a tree structure
	virtual void setBranchName(string branchName);          // Set the branch name

	// Getter functions access fields in private
	virtual vector<double> getSortedGiniIndexes() const;  // Returns sorted weighted Gini Index of an entire data set
	virtual vector<int> getFeatureOrder() const;	      // Returns the order of features in ascending order with respect to Gini Index

	// Output functions
	virtual void printGiniIndex() const;                          // Outputs the entire dataset
	//virtual void printColumnSummary(string columnName) const; // Outputs a given column summary

private: // Private member is only accessible within a function

	// Data Members or Fields
	string branchName{"Root Node"};
	vector<string> X_columns;      // Independent column names
	vector<string> y_columns;      // Dependent column names
	vector<Column> X;				  // Independent variables
	vector<Column> y;				  // Dependent variable
	//vector <long> informationEntropy; // Here we store the information entropy for each column
	vector<vector<double>> giniIndex;		  // Here we store the Gini Index for each column
	vector<double> weightedGiniIndex;		  // Here we store the weighted Gini Index for each column

	// Branches of the tree
	vector<DecisionTree> branches;

}; // end of the class Decision Tree

#endif 