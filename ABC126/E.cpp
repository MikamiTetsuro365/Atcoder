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
 
    ll N, M;
    cin >> N >> M;
    //初期化
    UnionFind G(N);

 
    //友達関係
    for(ll i = 0; i < M; i++){
        ll u, v, z;
        ll w = 0;
        cin >> u >> v >> z;
        u--;
        v--;
        G.unite(u, v);
    }

    map<ll, ll> mp;
    for(ll i = 0; i < N; i++){
        mp[G.root(i)]++;
    }

    cout << mp.size() << endl;
 
}