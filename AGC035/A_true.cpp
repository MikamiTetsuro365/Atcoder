#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N;
    cin >> N;
    map<ll, ll> mp;
    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        mp[t]++;
    }

    if(mp.size() > 3){
        cout << "No" << endl;
        return 0;
    }

    



}