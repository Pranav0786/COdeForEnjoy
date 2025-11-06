#include <bits/stdc++.h>
using namespace std;

long long getMaxRequests(vector<int>& serverCapacity, vector<int>& incomingRequests, int k) {
    vector<int> v ;
    long long ans = 0 ;
    for( int i = 0 ; i < serverCapacity.size() ; i++ ) {
        int req = incomingRequests[i] ;
        int cap = serverCapacity[i] ;
        if( req <= cap ) {
            ans += req ;
        } else {
            int rem = req - cap ;
            int diff = rem > cap ? rem - cap : 0 ;
            v.push_back(rem - diff) ;
        }
    }
    sort(v.rbegin(), v.rend()) ;
    for( int i = 0 ; i < v.size() ; i++ ) {
        if( k <= 0 ) break; 
        ans += v[i] ;
        k-- ;
    }
    return ans ;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> serverCapacity(n);
    for (int i = 0; i < n; i++) {
        cin >> serverCapacity[i];
    }

    vector<int> incomingRequests(n);
    for (int i = 0; i < n; i++) {
        cin >> incomingRequests[i];
    }

    int k;
    cin >> k;

    cout << "ans =>" <<  getMaxRequests(serverCapacity, incomingRequests, k) << "\n";

    return 0;
}
