#include<bits/stdc++.h>
#define ll long long
using namespace std;

void Johnsnow(){
    int a , b , c , d ;
    cin >> a >> b >> c >> d ;
    if( a == b && b == d && c == d ){
        cout << "YES" << endl ;
    }
    else{
        cout << "NO" << endl ;
    }
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