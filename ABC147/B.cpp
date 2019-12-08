#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() {

    string N; cin >> N;
    string S = N;
    reverse(S.begin(), S.end());

    ll ans = 0;
    for(ll i = 0; i < N.length(); i++){
        if(N[i] != S[i]){
            ans++;
        }
    }
    cout << ans / 2 << endl;
}