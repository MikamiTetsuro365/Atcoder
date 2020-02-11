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

    vector<ll > a(M, 0);
    vector<ll > b(M, 0);

    for(ll i = 0; i < M; i++) cin >> a[i] >> b[i];

    for(ll i = 0; i < N; i++){
        ll cn = 0;
        for(ll j = 0; j < M; j++){
            if(i == a[j]-1) cn++;
            if(i == b[j]-1) cn++;
        }         
        cout << cn << endl;
    } 

}