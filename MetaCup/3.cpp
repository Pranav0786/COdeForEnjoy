#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int case_no = 1; case_no <= T; ++case_no) {
        int N, A, B;
        cin >> N >> A >> B;

        vector<int> ans;
        // First N: multiply by 1 (minimum value to guarantee product doesn't exceed A)
        int cool = 1;
        for (int i = 0; i < N; ++i) {
            ans.push_back(1);
            cool *= 1;
        }

        // After N days, coolness is 1. We need the next N multipliers to multiply to B/1 = B.
        int left = B;
        for (int i = 0; i < N - 1; ++i) {
            ans.push_back(1); // multiply by 1 for all but the last (safe, valid)
            left /= 1;
        }
        ans.push_back(left); // Last multiplier sets the product to exactly B.

        cout << "Case #" << case_no << ": ";
        for (int x : ans) cout << x << " ";
        cout << endl;
    }
    return 0;
}
