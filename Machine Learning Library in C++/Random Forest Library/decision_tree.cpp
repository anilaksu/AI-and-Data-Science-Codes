// Implementation File

/*
	Here we create a class to apply decision tree algorithm to various data types
*/

#include "decision_tree.h"

/*

	Decision Tree Member Functions

*/


// Constructor for Data Table Class
DecisionTree::DecisionTree(DataTable data, vector<string> X_columns, vector<string> y_columns)
{
	this->X = data.returnColumns(X_columns);
	this->y = data.returnColumns(y_columns);
	//Here we calculate Gini Index for each independent column
	for (Column x : this->X)
		this->giniIndex.push_back(calculateGiniIndex(x));
}



// Calculate Gini Index for each independent variable
vector<double> DecisionTree::calculateGiniIndex(Column x) const
{
	vector<double> GiniIndex;
	double p = 0;    // Probability of a given value

	for (int i = 0; i < x.getUniques().size(); i++)
	{
		p = x.getUniqueCounts()[i]/ (double) x.getColumnData().size();	// Probability to pick i th outcome
		GiniIndex.push_back(1. - pow(p, 2) - pow((1 - p), 2));  // Gini Index for i th outcome

	}
	return GiniIndex;

}

// Calculate Gini Index for each independent variable
void DecisionTree::printGiniIndex() const
{

	for (int i = 0; i < this->X.size(); i++)					// For each column
	{
		for (int j = 0; j < X[i].getUniques().size(); j++) // For each unique value
		{
			cout << X[i].getUniques()[j] << " ";
		}

		cout << endl;  // Space between unique values and corresponding Gini Indexes

		for (int j = 0; j < this->X[i].getUniques().size(); j++) // For each unique value
		{
			cout << this->giniIndex[i][j] << " ";
		}

		cout << endl;  // Space between independent variables
	}
}