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

    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll ans = 0;
    for(ll i = 0; i < N - 2; i++){
        if(S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C'){
            ans++;
        }
    }

    cout << ans << endl;

}