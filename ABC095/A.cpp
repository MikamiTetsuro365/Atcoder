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

    string S;
    cin >> S;

    ll ans = 700;

    if(S[0] == 'o') ans += 100;
    if(S[1] == 'o') ans += 100;
    if(S[2] == 'o') ans += 100;

    cout << ans << endl;
}