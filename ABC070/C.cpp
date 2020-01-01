#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll MOD = 1000000007;

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}



int main(){

    ll N; cin >> N;

    vector<ll > vec;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    sort(vec.rbegin(), vec.rend());

    ll ans = 0;

    for(ll i = 0; i < N; i++){
        if(i == 0) ans = vec[0];
        else ans = lcm(ans, vec[i]);
    }

    cout << ans << endl;

}