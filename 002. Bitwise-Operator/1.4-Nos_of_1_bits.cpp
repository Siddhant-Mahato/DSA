#include <iostream>

using namespace std;


class Nos_of_1_bits
{
private:
    /* data */
public:
    int setBits(int N)
    {
        // Write Your Code here
        int count = 0;
        while (N != 0)
        {
            N = N & (N - 1);
            count++;
        }

        return count;
    }
};
