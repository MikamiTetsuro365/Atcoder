#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

//最大値の中央値あたりが怪しい
int main() {

    ll N, M;
    cin >> N >> M;
    
    vector<ll > A(N, 0);
    
  	for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    
    ll ans = INF;
    ll r = 0;
    ll l = M - 1;
    for(ll i = 0; i <= N - M; i++){
        ans = min(ans, A[l]-A[r]+min(abs(A[r]), abs(A[l])));
        //cout << A[r] << " " << A[l] << endl;
        r++;
        l++;
    }
    
    cout << ans << endl;

}