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

    ll ans = 0;
    if(M - N * 2 >= 0){
        ans += N;
        M = M - ans * 2;
        ans += M / 4;
    }else{
        ans += M / 2;
        M = M - ans * 2;
    }

    cout << ans << endl;
}