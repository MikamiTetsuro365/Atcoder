#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 998244353;
ll INF = 11451419194545;

ll mod_pow(ll a, ll n){
    if(n == 0) return 1;
    //べき数nが奇数, aを前にだして, a^n-1の気持ちに
    if(n % 2 == 1){
        return a * mod_pow(a, n - 1) % MOD;
    }else{
        //べき数nが偶数のとき，べき数を半分にして, aをまとめる. べき数を半分にする
        return mod_pow(a * a % MOD, n / 2) % MOD;
    }
}


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
        if(i != 0) mp[t]++;
    }

    ll cn = 1;
    ll ans = 1;
    ll tmp = 1;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        if(iter -> first != cn){
            cout << 0 << endl;
            return 0;
        }
        cn++;
        ans = ans * mod_pow(tmp, iter->second) % MOD;
        //cout << iter->second << endl;
        tmp = iter->second;
    }

    cout << ans << endl;


}