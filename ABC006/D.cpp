#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//昇順になっている箇所の間に数字を挿れていくと昇順に並ぶ
//最小の手数で昇順に並べたいなら最長で増加している（昇順）になっているところに
//入れ込むのが一番良い
int main() {

    ll N;
    cin >> N;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    //最長増加部分列
    ll mx = 0;
    vector<ll > dp(N, INF);
    for(ll i = 0; i < N; i++){
        //注目している数字以上になる最初の最小の箇所を見つける
        //その方がのちのちに最長なりやすい
        ll it = lower_bound(dp.begin(), dp.end(), vec[i]) - dp.begin();
        dp[it] = vec[i];
        mx = max(mx, it);
    }

    cout << N - mx - 1 << endl;

}