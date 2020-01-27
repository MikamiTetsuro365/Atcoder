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

    ll N, M;
    cin >> N >> M;

    for(ll i = 0; i < M; i++){
        ll t; cin >> t;
        N -= t;
    }

    if(N > 0){
        cout << "No" << endl;
    } else{
        cout << "Yes" << endl;
    }


}