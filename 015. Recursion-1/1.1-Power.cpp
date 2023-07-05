#include<iostream> 
using namespace std;

int power(int n) {

    //base case 
    if(n == 0)
        return 1;

    //recursive relation
    return 2 * power(n-1);    
}

int main() {

    int n;
    cin >> n;

    int ans = power(n);

    cout << ans << endl;

    return 0;
}


// https://www.codingninjas.com/studio/guided-paths/data-structures-algorithms/content/118522/offering/1380913