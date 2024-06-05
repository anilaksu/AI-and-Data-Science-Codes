#include <iostream>		// Input output stream from console
#include <fstream>      // Input output stream from file
#include <string>		// String Operations library
#include <sstream>      // String Stream Library
#include <vector>		// Vector library

using namespace std;    // Standard Name Space

void simple_tokenizer(string s); // Function Template for String Tokenizer

int main()
{

	vector<string> inputVector; // Here we create a vector to store the numbers in the input file
	vector<string> inputTitles; // Here we read input table titles
	string  inputData; // Here we create a vector to store the numbers in the input file

	ifstream weatherFile;				 // For reading name file
	weatherFile.open("weatherFile.txt"); // Here we open the name file

	while (!weatherFile.eof())
	{
		getline(weatherFile, inputData); // get line help us to read entire line
		//weatherFile >> inputData;
		inputVector.push_back(inputData);
	}
	
	weatherFile.close();				     // Here we close the file

	// Here we output input data to check if we read it correctly
	for (auto data : inputVector)
		cout << data << endl;

	// Here we get the titles in the table data
	simple_tokenizer(inputVector[0]);

	return 0;
}

// A quick way to split strings separated via spaces.
void simple_tokenizer(string s)
{
	stringstream ss(s);
	string word;
	while (ss >> word) {
		cout << word << endl;
	}
}