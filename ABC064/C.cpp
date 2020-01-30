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
        if(t >= 1 && t <= 399) mp[0]++;
        else if(t >= 400 && t <= 799) mp[1]++;
        else if(t >= 800 && t <= 1199) mp[2]++;
        else if(t >= 1200 && t <= 1599) mp[3]++;
        else if(t >= 1600 && t <= 1999) mp[4]++;
        else if(t >= 2000 && t <= 2399) mp[5]++;
        else if(t >= 2400 && t <= 2799) mp[6]++;
        else if(t >= 2800 && t <= 3199) mp[7]++;
        else if(t >= 3200) mp[8]++;
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