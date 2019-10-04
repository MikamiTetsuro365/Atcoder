#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N, M;
    cin >> N >> M;

    vector<ll > day(N, -1);

    for(ll i = 0; i < M; i++){
        ll d, p;
        cin >> d >> p;
        day[d] = p;
    }

    ll value = 0;
    //vector<vector<ll > > dp(N + 1, vector<ll >(3, value));
    //0日目から初めて　メニュー0 = 前日は何も食べていない
    vector<vector<vector<ll > > > dp(N, vector<vector<ll > >(4, vector<ll >(4, -1)));
    //経過日数、前々日、前日
    dp[0][0][0] = 0;

    for(ll i = 1; i < N; i++){
        for(ll j = 0; j < 3; j++){
            dp[i][j][k] = dp[i-1][j][k];
            for(ll k = 0; k < 3; k++){

            }
        }
    }  


}