#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<ll > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    for(ll i = 0; i < 5; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    map<ll, bool> mp;
    for(ll i = 0; i <= (1<<5); i++){
        ll sum = 0;
        if(__builtin_popcount(i) != 3) continue;
        for(ll j = 0; j < 5; j++){
            if((i>>j) & 1 == 1){
                sum += vec[j];
            }
        }
        mp[sum] = true;
    }  

    ll idx = 0;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        if(idx == mp.size()-3){
            cout << iter->first << endl;
            return 0;
        }
        idx++;
    }    

}
