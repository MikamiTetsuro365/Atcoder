#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N, M;
    cin >> N >> M;
    ll mod = 100000;
    ll value = 0;
    //余白大事
    //vector<vector<ll > > dp(N + 1, vector<ll >(M + 1, 0));
    //vector<vector<ll > > dp(N + 1, vector<ll >(M + 1, 0));
    vector<vector<vector<ll > > > dp(N + 5, vector<vector<ll > >(M + 5, vector<ll >(4, 0)));

    //初期化：枠外に初期値を入れておく(バグらせないように)
    for(ll i = 1; i < N; i++){
        dp[i][0][0] = 1;
        dp[i][0][2] = 1;
    }
    for(ll i = 1; i < M; i++){
        dp[0][i][1] = 1;
        dp[0][i][3] = 1;
    }

    for(ll x = 1; x < N; x++){
        //cout << x << endl;
        for(ll y = 1; y < M; y++){
            //次に曲がれる
            //横から
            //前の辺で曲がれた辺，曲がれなかった辺(曲がれなかったは次には曲がれるようになるので加算)
            dp[x][y][0] = (dp[x-1][y][0] + dp[x-1][y][3]) % mod;
            //縦から
            dp[x][y][1] = (dp[x][y-1][1] + dp[x][y-1][2]) % mod;
            //曲がることができない→
            //前に曲がったので今回は曲がれない
            dp[x][y][2] = dp[x-1][y][0];
            //次に曲がることができない↑
            dp[x][y][3] = dp[x][y-1][1];
            //if(dp[x+1][y] != -1 && x+1 < N) dp[x+1][y] += dp[x][y];
            //if(dp[x][y+1] != -1 && y+1 < M) dp[x][y+1] += dp[x][y];
             
        }    
    }
    
    //目標地点に西から侵入する辺と南から侵入する辺の合計
    //曲がれる曲がれない両方を含む
    ll ans = 0;
    ans = (dp[N-2][M-1][0] + dp[N-2][M-1][3] + dp[N-1][M-2][1] + dp[N-1][M-2][2]) % mod;
    cout << ans << endl;



}