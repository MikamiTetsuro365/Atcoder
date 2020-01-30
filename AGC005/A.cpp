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

    string X;
    cin >> X;
    X = 'T' + X;
    ll ans = 0;
    ll t_cn = 0;
    ll s_cn = 0;
    for(ll i = X.length()-1; i >= 0; i--){
        if(X[i] == 'T') t_cn++;
        if(X[i] == 'S') s_cn++;
        if(X[i] == 'S' && X[i-1] == 'T'){
            ans += 2 * min(t_cn, s_cn);
            t_cn -= min(t_cn, s_cn);
            s_cn = 0;
        }
        //cout << t_cn << " " << s_cn << endl;
    }

    cout << X.length() - ans - 1 << endl;
    
}