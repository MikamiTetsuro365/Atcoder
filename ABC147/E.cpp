#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll A[81][81];
ll B[81][81];
ll D[81][81];
bool dp[81][81][6600];

int main() {

    ll H, W; cin >> H >> W;
 
    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            cin >> A[i][j];
        }
    }

    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            cin >> B[i][j];
            D[i][j] = abs(A[i][j] - B[i][j]);
        }
    }

    //初期化
    dp[0][0][D[0][0]] = true;

    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            for(ll k = 0; k < 6500; k++){
                if(dp[i][j][k]){
                    dp[i][j+1][abs(k - D[i][j+1])] = true;
                    dp[i][j+1][abs(k + D[i][j+1])] = true;
                    
                    dp[i+1][j][abs(k - D[i+1][j])] = true; 
                    dp[i+1][j][abs(k + D[i+1][j])] = true;
                     
                }
            }
        }
    }

    for(ll k = 0; k < 6500; k++){
        if(dp[H-1][W-1][k]){
            cout << k << endl;
            return 0;
        }
    }
}