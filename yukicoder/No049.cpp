#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    string S; cin >> S;
    //番兵
    S += '=';

    ll ans = 0;
    ll s = 0;
    ll k = 0;
    ll cn = 0;
    for(ll i = 0; i < S.length(); i++){
        if(S[i] >= '0' && S[i] <= '9'){
            cn++;
        }else{
            ll num = stoi(S.substr(s, cn));
            if(k == 0){
                ans += num;
            }else{
                ans *= num;
            }
            if(S[i] == '*'){
                k = 0;
            }else{
                k = 1;
            }
            s = i + 1;
            cn = 0;
        }
    }

    cout << ans << endl;

}