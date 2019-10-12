#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N; cin >> N;
    string S; cin >> S;

    vector<ll > E(N + 1, 0);
    vector<ll > W(N + 1, 0);

    for(ll i = 1; i < N + 1; i++){
        if(S[i - 1] == 'E'){
            E[i] += E[i - 1] + 1;
        }else{
            E[i] = E[i -1];
        }

        if(S[i - 1] == 'W'){
            W[i] += W[i - 1] + 1;
        }else{
            W[i] = W[i -1];
        }
    }

    ll ans = INFINITY;
    for(ll i = 0; i < N; i++){
        ll t_ans = 0;
        //cout << W[i+1] << " " << E[N] - E[i+1] << endl;
        t_ans += E[N] - E[i+1];
        t_ans += W[i];
        //cout << i << " " << t_ans << endl;
        ans = min(ans, t_ans);

    }

    cout << ans << endl;

}