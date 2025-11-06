#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;
    for (int tc = 1; tc <= test_cases; ++tc) {
        int N;
        cin >> N;
        vector<int> array(N);
        for (int i = 0; i < N; ++i) {
            cin >> array[i];
        }
        int max_diff = 0;
        for (int i = 0; i < N - 1; ++i) {
            max_diff = max(max_diff, abs(array[i + 1] - array[i]));
        }
        cout << "Case #" << tc << ": " << max_diff << endl;
    }
    return 0;
}
