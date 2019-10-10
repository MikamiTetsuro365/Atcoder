#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi; 
typedef pair<pair<ll ,ll >,ll > pii; 
ll MOD = 1000000007;

int main(){
    
    ll H, W, K;
    cin >> H >> W >> K;

    vector<vector<ll > >dp(H+10, vector<ll >(W + 10, 0));
    //初期化
    dp[0][0] = 1;
    
    for(ll row = 0; row < H; row++){
        //横棒の数だけループを回す
        for(ll col = 0; col < (1 << W - 1); col++){
            //ビットの位置を確認
            bool continue_f = false;
            for(ll conf = 0; conf < W - 2; conf++){
                //1が連続していたら制約に当てはまらない
                if((col >> conf) & 1 && (col >> conf + 1) & 1){
                    continue_f = true;
                    break;
                }
            }
            if(continue_f == true){
                continue;
            }

            vector<ll > col_line(W, 0);
            //初期化
            for(ll i = 0; i < W; i++){
                col_line[i] = i;
            }

            for(ll i = 0; i < W - 1; i++){
                if((col >> i) & 1 == 1){
                    //入れ替える→横棒がはられている縦棒同士の移動
                    swap(col_line[i], col_line[i + 1]);
                }
            }
            
            //場合の数を更新
            //移動する先は横棒がはられていなければ下，はられていれば左右のどちらか
            for(ll r_row = 0; r_row < W; r_row++){
                dp[row + 1][col_line[r_row]] += dp[row][r_row] % MOD;
                dp[row + 1][col_line[r_row]] %= MOD;
                //cout << dp[row + 1][col_line[r_row]] << endl;
            }

        }
    }

    ll ans = dp[H][K - 1];
    cout << ans << endl;

}