#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll dp[5019][5019];
//Longest Common Subsequence
int main() {

    string S, T;
    cin >> S >> T;

    //何も字目が共通しているか？
    //Sの長さ分だけ気ににすれば良い
    //空文字もありうるので i <= S.length()
    for(ll i = 0; i <= S.length(); i++){
        for(ll j = 0; j <= S.length(); j++){
            //通常遷移
            //cout << S[i] << endl;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            //Sのi文字目とTのj文字目が等しい時
            if(i < S.length() && j < S.length() && S[i] == T[j]){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
            }
        }        
    }

    cout << dp[S.length()][T.length()] + 1 << endl;

}