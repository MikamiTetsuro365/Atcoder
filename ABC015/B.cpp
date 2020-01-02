#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

int main(){

    ll N; cin >> N;
    
    double sum = 0;
    double cn = 0;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        if(t != 0){
            sum += t;
            cn++;
        }
    }

    cout << ceil(sum/cn) << endl;

}