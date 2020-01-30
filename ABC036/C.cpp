#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<ll > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N;
    cin >> N;

    ll idx = 1;
    map<ll, ll> mp;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
        vec2.push_back(t);
    }
    sort(vec.begin(), vec.end());

    for(ll i = 0; i < N; i++){
        if(mp[vec[i]] == 0){
            mp[vec[i]] = idx;
            idx++;
        }
    }

    for(ll i = 0; i < N; i++){
        cout << mp[vec2[i]]-1 << endl;
    }

}