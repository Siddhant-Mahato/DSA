#include <iostream>
#include <vector>

using namespace std;

class InversionCount {
public:
    static long inversionCount(vector<long long>& arr, long long N) {
        return count(arr, 0, N - 1);
    }

    static long long count(vector<long long>& arr, long long s, long long e) {
        if (s >= e)
            return 0;

        long long mid = (s + e) / 2;

        long long inv = count(arr, s, mid);
        inv += count(arr, mid + 1, e);
        inv += merge(arr, s, e);
        return inv;
    }

    static long long merge(vector<long long>& arr, long long s, long long e) {
        long long ans = 0;

        long long mid = (s + e) / 2;

        long long l1 = mid - s + 1;
        long long l2 = e - mid;

        vector<long long> a1(l1);
        vector<long long> a2(l2);

        long long idx = s;

        for (long long i = 0; i < l1; i++) {
            a1[i] = arr[idx++];
        }

        for (long long i = 0; i < l2; i++) {
            a2[i] = arr[idx++];
        }

        long long idx1 = 0;
        long long idx2 = 0;
        idx = s;
        while (idx1 < l1 && idx2 < l2) {
            if (a1[idx1] > a2[idx2]) {
                ans += (l1 - idx1);
                arr[idx++] = a2[idx2++];
            }
            else {
                arr[idx++] = a1[idx1++];
            }
        }

        while (idx1 < l1) {
            arr[idx++] = a1[idx1++];
        }
        while (idx2 < l2) {
            arr[idx++] = a2[idx2++];
        }

        return ans;
    }
};

int main() {
    vector<long long> arr = { 1, 3, 2, 4, 5 };
    long long N = arr.size();

    long long inversions = InversionCount::inversionCount(arr, N);

    cout << "Number of inversions: " << inversions << endl;

    return 0;
}
