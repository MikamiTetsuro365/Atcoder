#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N;
    cin >> N;

    map<ll, ll > mp;
    mp[0]++;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vector<ll > tmp;
        auto begin = mp.begin(), end = mp.end();
        for (auto iter = begin; iter != end; iter++) {
            tmp.push_back(iter->first);
            tmp.push_back(iter->first + t);
        }
        
        for(ll j = 0; j < tmp.size(); j++){
            mp[tmp[j]]++;
        }
    }

    ll ans = 0;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        if(iter->first % 10 != 0){
            ans = max(ans, iter->first);
        }
    }

    cout << ans << endl;

}