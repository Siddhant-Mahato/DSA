#include <bits/stdc++.h>

using namespace std;



int main()
{
    int a = 4;

    int *p = &a;

//? Here  p -> Address of a ||  p -> &a ;    

    int *q = p;

//? So as we know that pointer store's the address and thus q -> p   as   p   itself  has  address of a    so GOT SAME VALUE FOR q AND p.

    cout<<q<<" "<<p<<endl;


    return 0;
}