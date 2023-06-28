#include <bits/stdc++.h>

using namespace std;

class Selection_Sort
{

public:
    int select(int arr[], int i)
    {
        // code here such that selectionSort() sorts arr[]
        selectionSort(arr, i);
    }

    void selectionSort(int arr[], int n)
    {
        // code here
        int mini = 0;
        for (int i = 0; i <= n - 2; i++)
        {
            mini = i;
            for (int j = i; j < n; j++)
            {
                if (arr[mini] > arr[j])
                {
                    mini = j;
                }
            }
            swap(arr[mini], arr[i]);
        }
    }
};
