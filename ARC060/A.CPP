#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//中身は0になっているはず
//ll dp[1919][1919][3019];

//配るDP
int main() {

    ll N, A; cin >> N >> A;
    vector<ll > card(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> card[i];
    }
    vector<vector<vector<ll > > > dp(55, vector<vector<ll > >(55, vector<ll >(3019, 0)));
    //今までに何をいくつ配り、その時の総和を記録しておく
    //平均がAとすると平均A満たすある数Bは必ずAの倍数である
    //そのようなBをとる総和を考えてやると今までに配った全てのカードに対する平均記録しておかなくて良い
    dp[0][0][0] = 1;
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        for(ll num = 0; num <= N; num++){
            //制約的に最大総和50*50が考えられるので余裕を持って3000
            for(ll sum = 0; sum <= 3000; sum++){
                if(dp[i][num][sum] == 0) continue;

                //そのカードを使わないとき
                dp[i+1][num][sum] += dp[i][num][sum];
                
                //カードを使う時
                ll tmp = dp[i][num][sum];
                ll new_sum = sum + card[i];
                ll new_num = num + 1;
                //平均値Aになるかの判定
                if(new_sum == new_num * A){
                    ans += tmp;
                }
                dp[i+1][new_num][new_sum] += tmp;
            }
        }
    }

    cout << ans << endl;

}