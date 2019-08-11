#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>
#include <map>
 
using namespace std;
typedef long long int ll;

ll MOD = 1000000007;
 
int main(){

    string S;
    cin >> S;

    vector<vector<ll > > dp(S.length() + 1, vector<ll >(13, 0));

    dp[0][0] = 1;

    for(ll i = 0; i < S.length(); i++){

        //0~9までを入れたとき前からのMODがどう変化するか
        for(ll j = 0; j < 10; j++){
            //？ではなく数字が書かれているときは数字分の遷移しか考えない
            if(S[i] != '?' && (S[i] - '0') != j ){
                continue;
            }
            for(ll h = 0; h < 13; h++){
                dp[i + 1][(h * 10 + j) % 13] += dp[i][h];
            }
        }

        //答えが超えないように割っておく
        for(ll j = 0; j < 13; j++){
            dp[i + 1][j] %= MOD;
        }
    }
 
    cout << dp[S.length()][5] << endl;

} 