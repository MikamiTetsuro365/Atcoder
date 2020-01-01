#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

int main(){

    ll N; cin >> N;

    vector<ll > vec;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    //sort(vec.begin(), vec.end());

    /*
    if(vec[0] < 0){
        ll tmp = abs(vec[0]);
        for(ll i = 0; i < N; i++){
            vec[i] += tmp;
        }      
    }
    */

    vector<ll > ruiseki(N, 0);

    for(ll i = 0; i < N; i++){
        if(i == 0) ruiseki[0] = vec[0];
        else ruiseki[i] = ruiseki[i-1] + vec[i];
    }

    ll ans = INF;

    for(ll i = 0; i < N - 1; i++){
        ans = min(ans, abs(ruiseki[i] - (ruiseki[N-1] - ruiseki[i])));
        //cout << ruiseki[i] << " " << ruiseki[N-1] - ruiseki[i] << endl;
    }    
    
    cout << ans << endl;

}