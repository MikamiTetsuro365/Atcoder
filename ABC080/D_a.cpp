#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<double, double > pi; 
typedef pair<pair<double, double >, double > pii; 

int main(){

    ll N, C;
    cin >> N >> C;
    vector<vector<ll > > memo(C, vector<ll >(100010, 0));
    for(ll i = 0; i < N; i++){
        ll S, T, C; cin >> S >> T >> C;
        //どこから始まったかどこ以降で終わったかを記録
        for(ll j = S; j <= T; j++){
            memo[C-1][j] = 1;
        }
        /* 
        //始点に1加算
        memo[C-1][S]++;
        //終点から1つ後に1減算
        memo[C-1][T + 1]--; 
        */
    }

    vector<ll > t_ans(100010, 0);
    for(ll i = 1; i < 100010; i++){
        //ll count = 0;
        ll sum = 0;
        for(ll j = 0; j < C; j++){
            sum += memo[j][i];
        }
        //sum += t_ans[i-1];
        t_ans[i] = sum;
    }

    //重なりが一番多いところを探す
    ll mx = 0;
    for(ll i = 1; i <100010; i++){
        mx = max(mx, t_ans[i]);
    }

    cout << mx << endl;

}