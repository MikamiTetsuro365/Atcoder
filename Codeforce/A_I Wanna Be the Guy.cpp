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

    ll N; cin >> N;

    vector<bool > tmp(N + 19, false);

    ll p;
    cin >> p;
    for(ll i = 0; i < p; i++){
        ll t; cin >> t;
        tmp[t] = true;
    }
    
    cin >> p;
    for(ll i = 0; i < p; i++){
        ll t; cin >> t;
        tmp[t] = true;
    }

    for(ll i = 1; i <= N; i++){
        if(tmp[i] == false){
            cout << "Oh, my keyboard!" << endl;
            return 0;
        }
    }    
    cout << "I become the guy." << endl;
}