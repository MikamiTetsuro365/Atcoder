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

    ll N; string S;
    cin >> N >> S;

    ll ans = 0;

    for(ll i = 0; i <= 999; i++){
        ostringstream ss;
        ss << setw(3) << setfill('0') << i << "\n";
        string s(ss.str());

        ll cn = 0;
        for(ll i = 0; i < N; i++){
            if(s[cn] == S[i]){
                cn++;
            }
            if(cn > 2){
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
}