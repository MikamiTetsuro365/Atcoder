#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){
    ll N, K; cin >> N >> K;
    
    ll cn = 0;
    ll ans = 0;
    bool f = false;
    map<ll, ll> mp;
    for(ll i = 0; i < N; i++){
        ll a, b; cin >> a >> b;
        mp[a] += b;
    }

    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        if(K <= iter->second + cn){
            cout << iter->first << endl;
            return 0;
        }
        cn += iter->second;
    }

}