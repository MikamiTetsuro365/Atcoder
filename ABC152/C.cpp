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

    ll mn = INF;
    vector<ll > mnn;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
        if(mn > t){
            mn = t;
        }
        mnn.push_back(mn);
        
    }

    ll ans = 0;

    for(ll j = 0; j < N; j++){
        //cout << mnn[j] << " " << vec[j] << endl;
        if(mnn[j] < vec[j]){
            ans++;
        }
    }

    cout << N - ans << endl;



}