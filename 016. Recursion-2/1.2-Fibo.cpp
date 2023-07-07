
#include <iostream>
using namespace std;

class Fibonnaci
{
public:
    int fib(int n)
    {

        if (n <= 1) // base case
            return n;

        return fib(n - 1) + fib(n - 2); // recurrence relation
    }
};



// Question Links: 
// - Fibonnacci Series: https://leetcode.com/problems/fibonac...
 
// - Climb Stairs: https://bit.ly/32VA96H
