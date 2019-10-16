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

    map<ll, ll > mp;

    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        mp[t]++;
    }

    ll ans = 0;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        if(iter->second < iter->first){
            ans += iter->second;
        }else{
            ans += iter->second - iter->first;
        }
    }

    cout << ans << endl;

}