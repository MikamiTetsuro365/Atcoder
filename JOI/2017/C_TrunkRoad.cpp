#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll N, M;

int main(){

    cin >> N >> M;
    vector<vector<ll > > cost(N, vector<ll >(M, 0));

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            cin >> cost[i][j]; 
        }        
    }

    ll ans = 1145141919;
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            ll t_ans = 0;
            for(ll k = 0; k < N; k++){
                for(ll h = 0; h < M; h++){
                    if(k == i || h == j) continue;
                    t_ans += cost[k][h] * min(abs(k-i), abs(h-j));
                }        
            }  
            ans = min(ans, t_ans);      
        }        
    }

    cout << ans << endl;

}