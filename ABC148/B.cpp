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

    string S, T;
    
    cin >> S >> T;

    vector<char > ans(S.length() + T.length());

    ll cn = 0;
    for(ll i = 0; i < S.length(); i++){
        ans[cn] = S[i];
        cn += 2;
    }

    cn = 1;
    for(ll i = 0; i < T.length(); i++){
        ans[cn] = T[i];
        cn += 2;
    }

    for(ll i = 0; i <ans.size(); i++){
        cout << ans[i];
    }
    cout << endl;

}