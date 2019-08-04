#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>

using namespace std;
typedef long long ll;
ll N;

int main(){
    
    cin >> N;
    vector<ll > a(N,0);
    
    for(ll i = 0; i < N; i++){

        cin >> a[i];
    }


    //cout << aa ^ bb << endl;

    for(ll i = 1; i < N - 1 ; i++){
        ll xr = a[i - 1] ^ a[i] ^ a[i + 1];
        if(xr != 0){
            //cout << xr << endl;
            cout << "No" << endl;
            return 0;
        }
    }
    ll xr = a[N - 1] ^ a[0] ^ a[1] ;
    //cout << xr << endl;
    if(xr != 0){
        //cout << xr << endl;
        cout << "No" << endl;
        return 0;
    }
    
    xr = a[0] ^ a[N-1] ^ a[N-2];
    if(xr != 0){
        cout << "No" << endl;
        return 0;
    } 

    cout << "Yes" << endl;

} 