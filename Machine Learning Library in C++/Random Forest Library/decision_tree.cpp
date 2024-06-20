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
	this->X_columns = X_columns;
	this->y_columns = y_columns;
	this->X = data.returnColumns(X_columns);
	this->y = data.returnColumns(y_columns);
	//Here we calculate Gini Index for each independent column
	for (Column x : this->X)
		this->giniIndex.push_back(calculateGiniIndex(x));
}


/*

	Setter Functions

*/

// Calculate Gini Index for each independent variable
vector<double> DecisionTree::calculateGiniIndex(Column x) 
{
	vector<double> GiniIndex;
	double p = 0;    // Probability of a given value
	double giniIndex = 0, weightedGiniIndex = 0;
	int total = 0;	 // Total occurence
	int positive = 0;// Positive occurence


	for (auto unique : x.getUniques())
	{
		for (int i = 0; i < x.getColumnData().size(); i++)
		{
			if (x.getColumnData()[i] == unique &&                             // Check if it is true
				this->y[0].getColumnData()[i] == this->y[0].getUniques()[1])
			{
				positive++; total++;
			}
			else if (x.getColumnData()[i] == unique &&                        // Check if it is false
				this->y[0].getColumnData()[i] == this->y[0].getUniques()[0])
				total++;
			else
				continue;

		}

		// Here we calculate Gini Index
		p = positive / (double) total;							// Probability to pick i th outcome
		giniIndex = 1. - pow(p, 2) - pow((1 - p), 2);          // Gini Index for i th outcome
		GiniIndex.push_back(giniIndex);
		
		// Here we calculate weighted Gini Index
		weightedGiniIndex += (total / (double)x.getColumnData().size()) * giniIndex;
		// Here we reset counters
		total = 0;	 positive = 0;
	}

	// Here we append to the class based vector
	this->weightedGiniIndex.push_back(weightedGiniIndex);

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
		cout << "Weighted Gini Index: " << this->weightedGiniIndex[i] << endl;

	}
}

/*

	Getter Functions

*/

// This function sorts weighted Gini Indexes
vector<double> DecisionTree::getSortedGiniIndexes() const
{
	vector<double> sortedGiniIndex = this->weightedGiniIndex;
	sort(sortedGiniIndex.begin(), sortedGiniIndex.end());    // Here we sort it 
	return sortedGiniIndex;
}


// This function returns indexes of sorted Gini Indexes
vector<int> DecisionTree::getFeatureOrder() const
{
	vector<int> featureOrder;

	for (double giniIndex : this->weightedGiniIndex)
	{
		vector<double> sortedGiniIndex = getSortedGiniIndexes();  // Here we call Gini Index vector once to save computational effort
		auto it = find(sortedGiniIndex.begin(), sortedGiniIndex.end(), giniIndex);
		int index = it - sortedGiniIndex.begin();
		featureOrder.push_back(index);
	}

	return featureOrder;
}

void DecisionTree::setBranchName(string branchName) {
	this->branchName = branchName;
}

// Generates branches of tree strucuture
void DecisionTree::setBranches()
{

	vector<string> X_columns;					// Independent column names
	vector<string> y_columns = this->y_columns; // Dependent column names
	vector<Column> X;				  // Independent variables
	vector<Column> y;				  // Dependent variable
	vector<int> featureOrder = getFeatureOrder();
	

	for (auto branchName : this->X[featureOrder[0]].getUniques())
	{
		for (int i = 1; i < featureOrder.size(); i++)
		{
			for (int i = 1; i < featureOrder.size(); i++)
				X_columns.push_back(this->X_columns[featureOrder[i]]);  // Here we add column names for the sub branch
		}
		cout << branchName << endl;
	}
}


