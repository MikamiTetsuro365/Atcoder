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

    ll N, M; cin >> N >> M;
    /*
    ll ans = N + (N - 1) / (M - 1);
    */

    ll cn = 0;
    while(true){
        if(cn % M == 0) N++;
        N--;
        if(N == 0) break;
        cn++;
    }

    cout << cn << endl;

}