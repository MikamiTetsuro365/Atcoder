#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    ll N, d, K;
    cin >> N >> d >> K;
    //Nと段数
    vector<vector<ll > > dp(319, vector<ll >(191919, 0));
    dp[0][0] = 1;
    ll s = 0;
    ll e = 1;

    for(ll i = 0; i < N; i++){
        //5
        //cout << i << endl;
        ll t_s, t_e;
        for(ll j = s; j < e; j++){
            for(ll h = 1; h <= d; h++){
                //cout << "yes" << endl;
                if(j + h + (N-i-1) * d < K) continue;
                else{
                    dp[i+1][j+h] += dp[i][j];
                    if(j == s) t_s = j + h;
                    break;
                }
                
            }
            if(j+1+d > K) continue;
            dp[i+1][j+1+d] += -dp[i][j];
            t_e = j + 1 + d;
            //cout << t_e << " ";
        }
        //cout << endl;
        //累積和
        // for(ll i = 0; i <= N; i++){
        //     for(ll j = 0; j <= K; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        s = t_s;
        e = t_e;
        //cout << s << " " << e << endl;
        for(ll j = s; j <= e; j++){
            dp[i+1][j] += dp[i+1][j-1];
            dp[i+1][j] %= MOD;
        }
        //cout << endl;
    }

    // for(ll i = 0; i <= N; i++){
    //     for(ll j = 0; j <= K; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if(dp[N][K] < 0){
        dp[N][K] += MOD;
    }
    cout << dp[N][K] << endl;

}
