#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
typedef pair<ll, pair<ll, ll > > iip;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N, K; cin >> N >> K ;

    map<ll, ll> mp;
    
    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        mp[t]++;
    }

    if(mp.size() <= K){
        cout << 0 << endl;
        return 0;
    }

    priority_queue<ll , vector<ll > , greater<ll > > que;

    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        que.push(iter->second);
    }   

    ll ans = 0;

    while(que.size() > K){
        ans += que.top(); que.pop();
    }

    cout << ans << endl;

}