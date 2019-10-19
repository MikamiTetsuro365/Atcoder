#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){
    ll N; cin >> N;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        for(ll j = i + 1; j < N; j++){
            ans += vec[j] * vec[i];
        }        
    }

    cout << ans << endl;

}