#include<iostream> 
using namespace std;

#define PI 3.14

int main() {

    int r = 5;
    //double pi = 3.14;

    double area = PI * r * r;

    cout << "Area is " << area << endl;

    return 0;
}


// https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/




/*
// C program to illustrate macros
#include <stdio.h>

// Macro definition
#define AREA(l, b) (l * b)

// Driver Code
int main()
{
	// Given lengths l1 and l2
	int l1 = 10, l2 = 5, area;

	// Find the area using macros
	area = AREA(l1, l2);

	// Print the area
	printf("Area of rectangle"
		" is: %d",
		area);

	return 0;
}



*/
