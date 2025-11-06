#include<bits/stdc++.h>
#define ll long long
using namespace std;



void Johnsnow(){
    int n;
    cin >> n;
    vector<int> arr(n) , odd , even;


    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if( arr[i] % 2 == 0 ) even.push_back(arr[i]);
        else odd.push_back(arr[i]);
    }

    if( even.size() == 0 || odd.size() == 0 ){
        for(auto i : arr) cout << i << " ";
        cout << endl;
        return ;
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    int i = 0 , e = 0 , o = 0 ;
    while( i < n && e < even.size() && o < odd.size() ){
        if( even[e] < odd[o] ){
            arr[i] = even[e];
            e++;
        }
        else{
            arr[i] = odd[o];
            o++;
        }
        i++;
    }
    while( i < n && e < even.size() ){
        arr[i] = even[e];
        e++;
        i++ ;
    }
    while( i < n &&  o < odd.size() ){
        arr[i] = odd[o];
        o++;
        i++ ;
    }

    for(auto i : arr) cout << i << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        Johnsnow();
    }
    return 0;
}
