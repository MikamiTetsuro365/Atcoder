#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N, K; cin >> N >> K;

    map<ll, ll> mp;
    for(ll i = 0; i < K; i++){
        ll t = 0; cin >> t;
        mp[t] = 1;
    }

    bool f = true;
    
    for(;;){
        f = true;
        ll t = N;
        while(t != 0){
            //cout << t % 10 << endl;
            if(mp[t % 10] == 1 ){
                f = false;
                break;
            }
            t /= 10;
        }
        if(f == true){
            break;
        }
        N++;
    }

    cout << N << endl;
}