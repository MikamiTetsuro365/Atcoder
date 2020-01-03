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
    string s; cin >> s;
    ll ans = 0;
    for(ll i = 1; i < s.length(); i++){
        ll tmp = 0;
        vector<bool > X(26, false);
        vector<bool > Y(26, false);
        for(ll j = 0; j < i; j++){
            X[s[j]-'a'] = true;
        }
        for(ll j = i; j < s.length(); j++){
            Y[s[j]-'a'] = true;
        }

        for(ll j = 0; j < 26; j++){
            if(X[j] == true && Y[j] == true){
                tmp++;
            }
        }

        ans = max(ans, tmp);

    }

    cout << ans << endl;

}