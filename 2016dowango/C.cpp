#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    ll N;
    cin >> N;

    map<ll, ll > mp;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        mp[t]++;
    }

    //cout << mp[1] << " " << mp[2] << " " << mp[3] << " " << mp[4] << endl;

    ll ans = 0;

    ans += mp[4];

    ans += mp[3];

    mp[1] = max(mp[1] - mp[3], 0LL);

    //cout << ans << endl;

    ans += mp[2] / 2;

    if(mp[2] % 2 > 0){
        ans++;
        mp[1] -= min(mp[1], 2LL);
    }

    ans += mp[1] / 4;

    if(mp[1] % 4 > 0) ans++;


    cout << ans << endl;

}