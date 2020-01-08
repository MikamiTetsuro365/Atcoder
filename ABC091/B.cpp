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

    ll ans = 0;
    
    ll N; cin >> N;
    map<string, ll> S;

    for(ll i = 0; i < N; i++){
        string k; cin >> k;
        S[k]++;
    }
    
    ll M; cin >> M;
    map<string, ll> T;
    for(ll i = 0; i < M; i++){
        string k; cin >> k;
        T[k]++;
    }

    //確認
    auto begin = S.begin(), end = S.end();
    for (auto iter = begin; iter != end; iter++) {
        ll tmp = iter -> second - T[iter -> first];
        ans = max(tmp, ans);
    }    

    cout << ans << endl;

}