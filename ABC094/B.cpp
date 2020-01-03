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

    ll N, M, X;
    cin >> N >> M >> X;

    vector<ll > A(M, 0);
    vector<ll > ruiseki(N+1, 0);
    for(ll i = 0; i < M; i++){
        cin >> A[i];
        ruiseki[A[i]]=1;
    }

    for(ll i = 1; i <= N; i++){
        ruiseki[i] += ruiseki[i-1];
        //cout << ruiseki[i] << endl;
    }

    cout << min(ruiseki[X], ruiseki[N] - ruiseki[X]) << endl;;

}