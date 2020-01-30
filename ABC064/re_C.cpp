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
        if(t >= 3200) mp[8]++;
        else mp[t/400]++;
    }
    //mapは参照しただけで要素数が増えるのでクソ
    ll num = mp.size();
    ll red = mp[8];

    ll mn = num;
    if(red > 0) mn = max((ll)1, num-1);

    ll mx = num;
    if(red > 0) mx = mx-1+red;

    cout << mn << " " << mx << endl;
}