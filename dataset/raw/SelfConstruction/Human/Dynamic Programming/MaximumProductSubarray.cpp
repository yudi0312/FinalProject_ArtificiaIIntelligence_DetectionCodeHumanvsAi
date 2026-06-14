#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    long long maxProd = arr[0];
    long long minProd = arr[0];
    long long result = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] < 0) {
            swap(maxProd, minProd);
        }

        maxProd = max((long long)arr[i], maxProd * arr[i]);
        minProd = min((long long)arr[i], minProd * arr[i]);

        result = max(result, maxProd);
    }

    return (int)result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << maxProduct(arr) << endl;
    return 0;
}
