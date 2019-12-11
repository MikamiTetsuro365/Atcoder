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

ll dx[4] ={0, 1, 0, -1};
ll dy[4] ={-1, 0, 1, 0};

int main(){

    ll H, W; cin >> H >> W;
    //初期化
    UnionFind solv((H + 2) * (W + 2));

    vector<vector<ll > > G(H+2, vector<ll >(W+2, 0));

    for(ll row = 1; row <= H; row++){
        for(ll col = 1; col <= W; col++){
            cin >> G[row][col];
        }
    }

    for(ll row = 1; row <= H; row++){
        for(ll col = 1; col <= W; col++){
            if(G[row][col] != 1) continue;
            for(ll i = 0; i < 4; i++){
                if(G[row][col] == G[row + dy[i]][col + dx[i]]){
                    solv.unite(row * (W+2) + col, (row + dy[i]) * (W+2) + (col + dx[i]));
                }
            }
        }
    }

    map<ll, ll> mp;
    ll cn = 0;
    for(ll row = 0; row < H+2; row++){
        for(ll col = 0; col < W+2; col++){
            cn++;
            if(G[row][col] != 1) continue;
            cout << solv.tree[cn] << endl;
            mp[solv.tree[cn]]++; 
        }
    }

    cout << mp.size() << endl;
    

}
