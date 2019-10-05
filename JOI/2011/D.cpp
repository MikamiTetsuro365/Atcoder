#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;

    vector<ll > A(N, 0);

    for(ll i = 0; i < N; i++){
        ll in;
        cin >> in;
        A[i] = in;
    }
    
    vector<vector<ll > > dp(N + 1, vector<ll >(22, 0));
    dp[0][A[0]] = 1;

    //答え
    ll ans = 0;

    for(ll i = 1; i < N - 1; i++){
        //cout << dp[i][A[N-1]] << endl;
        for(ll j = 0; j < dp[0].size(); j++){
            if(dp[i-1][j] == 0) continue;
            //cout << "a" << endl;
            if(!((j + A[i]) > 20)){
                dp[i][j + A[i]] += dp[i - 1][j];
            }
            if(!((j - A[i]) < 0)){
                dp[i][j - A[i]] += dp[i - 1][j];
            }
            
        }
    }

    cout << dp[N - 2][A[N-1]] << endl;

}