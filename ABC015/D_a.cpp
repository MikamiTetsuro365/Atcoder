#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;



int main(){

    ll W, N, K;
    cin >> W >> N >> K;
    //メモリ糞
    vector<vector<vector<ll >>> dp(N+5, vector<vector<ll >>(K+5, vector<ll >(W+5, -1)));
    //ll dp[100][100][10100];
    dp[0][0][0] = 0;

    vector<pair<ll,ll> > BA;
    //AとB逆転注意
    ll A, B;
    for(ll i = 0; i < N; i++){
        cin >> A >> B;
        BA.push_back(make_pair(B,A));
    }
    //重要度の大きい順
    sort(BA.begin(),BA.end());

    ll ans = -1;
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < K; j++){
            for(ll w = 0; w < W; w++){
                //更新が発生しない時
                if(dp[i][j][w] == -1) continue;

                //使用しない時
                dp[i + 1][j][w] = max(dp[i][j][w], dp[i + 1][j][w]);
                ans = max(ans, dp[i + 1][j][w]);

                //幅を超えていたら更新しない
                if(w + BA[i].second  > W) continue;
                //使用する時
                ll cost = dp[i][j][w] + BA[i].first;
                dp[i + 1][j + 1][w + BA[i].second] = max(dp[i + 1][j + 1][w + BA[i].second], cost);
                ans = max(ans, dp[i + 1][j + 1][w + BA[i].second]);

                


            }
        }       
    }

    cout << ans << endl;

}