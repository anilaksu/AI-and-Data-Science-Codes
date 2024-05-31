/*
	Here we create a class to read input data and format it to feed Machine Learning Algorithms
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:

	// Constructor
	Rectangle();
	Rectangle(double height, double width);
	// Destructor
	~Rectangle();
	// Member functions

	// Setter functions sets fields in private
	void setHeight(double height);
	void setWidth(double width);

	// Getter functions access fields in private
	double getHeight() const;
	double getWidth() const;
	double area() const;
	double perimeter() const;

private: // Private member is only accessible within a function
	// Data Members or Fields
	double height;
	double width;

}; // end of the class Rectangle

#endif 