#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
vector<vector<pi > > F;
vector<vector<pi > > B;
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

int main(){

    ll N, M, K; cin >> N >> M >> K;
    //初期化
    UnionFind tomo(N);
    F.assign(N, vector<pi >());
    B.assign(N, vector<pi >());

    //友達関係
    for(ll i = 0; i < M; i++){
        ll u, v;
        ll w = 0;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        F[u].push_back(make_pair(v, w));
        F[v].push_back(make_pair(u, w));
        tomo.unite(u, v);
    }
    //ブロック関係
    for(ll i = 0; i < K; i++){
        ll u, v;
        ll w = 0;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        B[u].push_back(make_pair(v, w));
        B[v].push_back(make_pair(u, w));
        // block.unite(u, v);
    }

    //ブロック関係でもなく，友人関係でもない人は？
    //連結成分のサイズ-自分と直接つながっている人の数(隣接リストのサイズ)

    for(ll i = 0; i < N; i++){
        ll cn = 0;
        for(ll j = 0; j < B[i].size(); j++){
            if(tomo.same(i, B[i][j].first) == true) cn++;
        }
        cout << tomo.FindSize(i) - F[i].size() - 1 - cn << endl;
    }


}