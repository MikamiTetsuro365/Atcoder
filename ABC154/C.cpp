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
        mp[t]++;
    }

    if(mp.size() == N){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }



}