#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N;
    cin >> N;

    map<ll, ll> mp;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
        mp[t] = 0;
    }

    ll idx = 1;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        mp[iter->first] = idx;
        idx++;
    }

    for(ll i = 0; i < N; i++){
        cout << mp[vec[i]] << endl;
    }
}