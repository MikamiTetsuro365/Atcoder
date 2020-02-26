#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//全探査でFirstが勝つ場所を見つける
//Groundy数

ll dp[19][19];
ll dx[4] = {-2, -2, 1, -1};
ll dy[4] = { 1, -1,-2, -2};

//Groundy数を求める
//対角線上に操作していけばうまくいきそう
void setG(){
    //X方向
    for(ll i = 0; i < 15; i++){
        for(ll j = i; j >= 0; j--){
            vector<bool > mex(10, false);
            for(ll k = 0; k < 4; k++){
                ll nextY = j + dy[k];
                ll nextX = (i - j) + dx[k];
                if(nextY >= 0 && nextY < 15 && nextX >= 0 && nextX < 15){
                    mex[dp[nextY][nextX]] = true;
                }
            }
            //最小の非負整数isどれ？
            for(ll k = 0; k < 10; k++){
                if(mex[k] == false){
                    dp[j][i-j] = k;
                    break;
                }
            }
        }
    }
    //Y方向
    for(ll i = 0; i < 15; i++){
        for(ll j = i; j < 15; j++){
            vector<bool > mex(10, false);
            //cout << j << " " << 15 + i - j - 1 << endl;
            ll x = j;
            ll y = 15 + i - j - 1;
            for(ll k = 0; k < 4; k++){
                ll nextY = x + dy[k];
                ll nextX = y + dx[k];
                if(nextY >= 0 && nextY < 15 && nextX >= 0 && nextX < 15){
                    mex[dp[nextY][nextX]] = true;
                }
            }
            //最小の非負整数isどれ？
            for(ll k = 0; k < 10; k++){
                if(mex[k] == false){
                    dp[x][y] = k;
                    break;
                }
            }            
        }
    }
}

int main() {

    ll N;
    cin >> N;

    //0状態が先行負け
    //列挙
    //初期化
    for(ll i = 0; i < 15; i++){
        for(ll j = 0; j < 15; j++){
            //初期化
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 1;
    dp[1][0] = 0;
    dp[1][1] = 0;
    dp[2][0] = 1;

    //列挙
    setG();

    // for(ll i = 0; i < 15; i++){
    //     for(ll j = 0; j < 15; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(ll i = 0; i < N; i++){
        ll A, B; cin >> A >> B;
        if(dp[A-1][B-1] > 0){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }

}