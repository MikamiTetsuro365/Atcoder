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

using namespace std;
typedef long long ll;
int MOD = 1000000007;
int dp[110][4][4][4];

int main(){

    int S;
    cin >> S;
    //AGCT 0123
   
    //初期化
    dp[0][3][3][3] = 1;

    for(int i = 0; i < S; i++){
        //cout << i << endl;
        for(int c1 = 0; c1 < 4; c1++){
            for(int c2 = 0; c2 < 4; c2++){
                for(int c3 = 0; c3 < 4; c3++){
                    if(dp[i][c1][c2][c3] == 0) continue;
                    //新しく前に追加するものをループで回す
                    for(int a = 0; a < 4; a++){
                        //追加の仕方で違反するもの
						if (a == 2 && c1 == 1 && c2 == 0) continue;
						if (a == 2 && c1 == 0 && c2 == 1) continue;
						if (a == 1 && c1 == 2 && c2 == 0) continue;
						if (a == 2 && c1 == 1 && c3 == 0) continue;
						if (a == 2 && c2 == 1 && c3 == 0) continue;

                        //文字列が作れるのでdp[n+1]に何個くれたのかを記録する
						dp[i + 1][a][c1][c2] += dp[i][c1][c2][c3];
						dp[i + 1][a][c1][c2] %= MOD;

                    }
                    
                }
            }
        }
    }

    int ans = 0;
    for(int c1 = 0; c1 < 4; c1++){
        for(int c2 = 0; c2 < 4; c2++){
            for(int c3 = 0; c3 < 4; c3++){
                ans += dp[S][c1][c2][c3];
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;

} 