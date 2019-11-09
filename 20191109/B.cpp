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
    ll N;
    cin >> N;

    map<ll, ll> mp;
    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        if(i == 0 && t > 0){
            cout << 0 << endl;
            return 0;
        }
        if(i > 0){
            mp[t]++;
        }
        
    }

    map<ll, ll> mp;
    //ここになにか入力
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        
    }


}