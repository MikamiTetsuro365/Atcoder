#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    string s;
    cin >> s;
    
    ll ans = 0;

    for(ll i = 0; i < s.length(); i++){
        if(s[i] == '1') ans++;
    }

    cout << ans << endl;

}