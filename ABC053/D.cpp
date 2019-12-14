#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() { 

    ll N; cin >> N;
    ll ans = N;
    map<ll, ll> mp;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        mp[t]++;
        //同じ数字が3つで2つ消せる
        if(mp[t] == 3){
            mp[t] = 1;
            ans -= 2;
        }
    }

    ll cn = 0;
    auto begin = mp.begin(); auto end = mp.end();
    for(auto iter = begin; iter != end; iter++){
        if(iter->second == 2){
            cn++;
        }
    }
    //同じ数字が2つある塊が2つあるとお互いに1つずつ残せる
    if(cn % 2 == 0){
        ans -= cn;
    }else{
        ans -= cn + 1;
    }

    cout << ans << endl;

}