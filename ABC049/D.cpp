#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
typedef pair<ll ,pair<ll, ll > > iip;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1e15;
 
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

    ll N, K, L;
    cin >> N >> K >> L;

    UnionFind douro(N);
    UnionFind tetsudo(N);

    for(ll i = 0; i < K; i++){
        ll p, q; cin >> p >> q;
        p--; q--;
        douro.unite(p, q);
    }

    for(ll i = 0; i < L; i++){
        ll r, s; cin >> r >> s;
        r--; s--;
        tetsudo.unite(r, s);
    }

    //根と根が同じかどうかでまとめる
    //道路と鉄道両方を使ってたどり着けるなら同じ根要素になっているはず
    //ある都市から鉄道と道路のどちらをつかってもたどり着ける都市の
    //UnionFind上での根要素はおなじになるはず
    //そのペアについて数を数えると連結している都市を数えることになる
    map<vector<ll >, ll> mp;
    for(ll i = 0; i < N; i++){
        mp[vector<ll >{douro.root(i), tetsudo.root(i)}]++;
    }    


    for(ll i = 0; i < N; i++){
        cout << ( i ? " " : "" ) << mp[vector<ll >{douro.root(i), tetsudo.root(i)}];
    }
    cout << endl;

}