#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<double > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    string S;
    cin >> S;

    ll ans = 0;
    for(ll i = 0; i < S.length(); i++){
        bool f = false;
        ll cn = 0;
        string tmp;
        if(S[i] == '*') continue;
        for(ll j = i; j < S.length(); j++){
            if(S[j] == '*') continue;
            if(f == false && S[j] == '2'){
                f = true;
                tmp += S[j];
                S[j] = '*';
                cn++;
            }else if(f == true && S[j] == '5'){
                f = false;
                tmp += S[j];
                S[j] = '*';
                cn++;                
            }
        }
        if(tmp.length() == 0 || tmp.back() == '2'){
            ans = -1;
            break;
        }
        ans++;
    }

    cout << ans << endl;

}