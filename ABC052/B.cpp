#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N;
    cin >> N;
    string S;
    cin >> S;

    ll ans = 0;
    ll t_ans = 0;
    for(ll i = 0; i < S.length(); i++){
        ans = max(ans, t_ans);
        if(S[i] == 'I'){
            t_ans++;
        }else if(S[i] == 'D'){
            t_ans--;
        }
    }
    ans = max(ans, t_ans);
    cout << ans << endl;

}