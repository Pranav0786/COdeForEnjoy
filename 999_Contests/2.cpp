#include<bits/stdc++.h>
#define ll long long
using namespace std;

void Johnsnow(){
    int n ;
    cin >> n ;
    string s , t ;
    cin >> s >> t ;
    vector<int> vs(26,0) , vt(26,0) ;
    for( int i = 0 ; i < n ; i++ ){
        vs[s[i]-'a']++ ;
        vt[t[i]-'a']++ ;
    }
    for( int i = 0 ; i < 26 ; i++ ){
        if( vs[i] != vt[i] ){
            cout << "NO" << endl ;
            return ;
        }
    }
    cout << "YES" << endl ;
}

int main()
{
    int t ;
    cin >> t ;
    while(t--){
        Johnsnow() ;
    }
    return 0 ;
}