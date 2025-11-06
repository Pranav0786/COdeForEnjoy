#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        
        long long min_ladder = 0;
        // Snake can go from ground to any platform and between platforms
        min_ladder = max(abs(A[0] - 0LL), abs(A[N-1] - 0LL));
        for (int i = 0; i + 1 < N; ++i) {
            min_ladder = max(min_ladder, abs(A[i+1] - A[i]));
        }
        
        cout << "Case #" << cas << ": " << min_ladder << endl;
    }
    return 0;
}
