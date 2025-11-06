#include<bits/stdc++.h>
#define ll long long
using namespace std;


long long solve(int totalElements, vector<long long> inputArray) {
    // your required code start from here
    int n = totalElements;
    if (n <= 1) {
        return 0;
    }
    sort(inputArray.begin(), inputArray.end());
    vector<long long> previousCosts(n, 0);
    for (int groupSize = 2; groupSize <= n; ++groupSize) {
        vector<long long> currentCosts(n - groupSize + 1);
        for (int startIdx = 0; startIdx <= n - groupSize; ++startIdx) {
            long long range = inputArray[startIdx + groupSize - 1] - inputArray[startIdx];
            long long minPrev = min(previousCosts[startIdx], previousCosts[startIdx + 1]);
            currentCosts[startIdx] = range + minPrev;
        }
        previousCosts = currentCosts;
    }
    return previousCosts[0];
    // your required code end here
}

int main() {
    int n = 6;
    vector<long long> arr = {1, 2, 2, 2, 3, 3};
    cout << solve(n, arr) << endl;
    return 0;
}

