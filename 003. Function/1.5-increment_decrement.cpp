#include <iostream>
using namespace std;

int main()
{
    // int i = 2;
    // int a = 4;
    // int sum = 0;
    // sum = a + i++;

    // cout << sum << endl;

    int a = 1;
    int b = 2;

    // if (a-- > 0 && ++b > 2)
    if (a-- > 0 || ++b > 2)
    {
        cout << "Stagel - Inside If ";
    }
    else
    {

        cout << "Stage2 - Inside else ";

    }
    cout<< a << " " << b << endl;

    return 0;
}