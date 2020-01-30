#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//すべての組み合わせを列挙して一番多く使われるp, qが答え
int main() {

    ll N;
    cin >> N;
    map<vector<ll >, ll> mp;
    vector<pi > p;
    for(ll i = 0; i < N; i++){
        ll x, y; cin >> x >> y;
        p.push_back(make_pair(x, y));
    }

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(i == j) continue;
            mp[vector<ll>{p[i].first - p[j].first, p[i].second - p[j].second}]++;
        }        
    }

    ll mx = 0;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        mx = max(mx, iter->second);
    }    

    cout << N - mx << endl;

}