#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
typedef pair<ll, pair<ll, ll > > iip;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N, A, B; cin >> N >> A >> B;
    vector<ll > d(N, 0);
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        cin >> d[i];
        if(i != 0){
            ans += min(B, (d[i]-d[i-1]) * A);
        }
    }

    cout << ans << endl;
}