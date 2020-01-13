#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

using namespace std;

struct UnionFind{
    //ご本体
    vector<ll > tree;
    //高さ
    vector<ll > rank;
    //グループごとのサイズ
    vector<ll > size;
 
    //定義
    UnionFind(ll N) : tree(N), rank(N), size(N){
        for(int i = 0; i < N; i++){
            tree[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
 
    //どの根っこに属しているのか？さかのぼり続ける
    int root(int x){
        if(tree[x] == x){
            return x;
        }
        //経路圧縮
        return tree[x] = root(tree[x]);
    }
 
    //木と木を(高さが低い方に)くっつける
    ll unite(int x, int y){
        int tx = root(x);
        int ty = root(y);
        //xとyの根が同じならくっつけない
        if(tx == ty){
            return 0;
        }
        
        ll s = size[tx] + size[ty];
        ll r = size[tx] * size[ty];
        size[tx] = s;
        size[ty] = s;
 
        //tree[tx] = ty;
        //高くない方にくっつけたい：効果がいまいちわからん
        //下：ランク付けのつもり 
        if(rank[tx] < rank[ty]){
            //小さい方を大きい方
            //txの根が大きい方の根に更新
            tree[tx] = ty; 
        }else{
            tree[ty] = tx;
            //つなげるときに同じ高さだったらつなげた後に高さを＋１する
            if(rank[tx] == rank[ty]){
                rank[tx]++;
            }
        }
 
        return r;
 
    }
 
    //同じ木に属しているか？根っこをさかのぼって調べてみる
    bool same(int x, int y){
        int tx = root(x);
        int ty = root(y);
        if(tx == ty){
            return true;
        }else{
            return false;
        }
    }
    //グループのサイズを返す
    int FindSize(int x){
        return size[root(x)];
    }
 
};

ll w[1919];
ll v[1919];

int main(){

    ll n, m, limitW;
    cin >> n >> m >> limitW;

    UnionFind solv(n);

    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        w[i] = a;
        v[i] = b;
    }

    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        a--;
        b--;
        solv.unite(a, b);
    }

    //vector<vector<ll > > ans(n + 19, vector<ll >(2, INF));

    map<ll, pi> mp;

    for(ll i = 0; i < n; i++){
        ll num = solv.root(i);
        //cout << num << endl;
        mp[num].first  += w[i];
        mp[num].second += v[i];

    }
    
    vector<vector<ll > > dp(n+19, vector<ll >(10019, -1));
    //初期化
    dp[0][0] = 0;
    ll idx = 0;
    ll ans = 0;

    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        //N個目の荷物を詰めるかどうか
        ll W = iter->second.first;
        ll V = iter->second.second;
        //cout << W << " " << V << endl;
        for(ll i = 0; i < limitW; i++){
            ll next_W = i + W;
            //cout << next_W << endl;
            if(dp[idx][i] == -1) continue;

            dp[idx + 1][i] = max(dp[idx][i], dp[idx + 1][i]);
            ans = max(dp[idx + 1][i], ans);

            if(next_W <= limitW){
                //cout << i << " " << next_W << endl;
                dp[idx+1][next_W] = max(dp[idx+1][next_W], dp[idx][i] + V);
                ans = max(dp[idx+1][next_W], ans);
            }
        }

        idx++;
    }
    /*
    for(ll i = 0; i <= 10; i++){
        for(ll j = 0; j <= limitW; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << ans << endl;

}