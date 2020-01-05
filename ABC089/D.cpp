#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll H, W, D;
    cin >> H >> W >> D;

    map<ll, pi> mp;

    //どこからどこへ？がわかる一覧表
    for(ll row = 1; row <= H; row++){
        for(ll col = 1; col <= W; col++){
            ll t; cin >> t;
            mp[t] = make_pair(row, col);
        }
    }

    //配るDP的な発想
    //今までにある場所から移動してきたことがあるならそこからも任意のN+Dへ移動できる
    vector<ll > dp(H * W + 19, 0);

    //準備
    for(ll i = 1; i <= H * W; i++){
        ll next = i + D;
        if(i + D > H * W) continue;
        dp[i + D] = dp[i] + abs(mp[i].first-mp[i+D].first) + abs(mp[i].second-mp[i+D].second);
    }

    ll Q; cin >> Q;

    vector<ll > ans;
    for(ll i = 0; i < Q; i++){
        ll a, b; cin >> a >> b;
        //コストを知りたいときは行き先と現在地から引くだけ
        //aが始点なら，これまでどの場所からも移動されてないのでコストは0になっているはず
        ans.push_back(dp[b]-dp[a]);
    }

    for(ll i = 0; i < Q; i++){
        cout << ans[i] << endl;
    }

}