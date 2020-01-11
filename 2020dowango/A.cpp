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

    ll N; cin >> N;

    //ll s[5000];
    ll t[5000];

    map<string, ll > mp; 
    for(ll i = 0; i < N; i++){
        string s; cin >> s;
        cin >> t[i];
        mp[s] = i;
    }
    string X; cin >> X;

    ll ans = 0;
    for(ll i = mp[X] + 1; i < N; i++){
        ans += t[i];
    }

    cout << ans << endl;

}