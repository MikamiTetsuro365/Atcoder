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
    ll N = 0;
    cin >> N;
    //i個おいたものがすでに何個あるかを記憶する
    //
    map<ll, ll> mp;
    //最初は3色のうちどれかを確実に選べる
    mp[0] = 3;
    
    ll ans = 1;
    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        ans *= mp[t];
        ans %= MOD;
        mp[t]--;
        mp[t+1]++;
    }

    cout << ans << endl;
}