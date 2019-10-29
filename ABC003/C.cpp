#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N, K; cin >> N >> K;
    vector<double > input;
    //初期化
    for(ll i = 0; i < N; i++){
        double t; cin >> t;
        input.push_back(t);
    }

    sort(input.begin(), input.end());
    
    double ans = 0;
    for(ll i = N - K; i < N; i++){
        ans = (ans + input[i]) / 2;
    }
    
    cout << fixed << setprecision(10) << ans << endl;
}