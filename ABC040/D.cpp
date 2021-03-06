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

    ll N, M; cin >> N >> M;
    //初期化
    UnionFind solv(N);

    priority_queue<iip> road;
    priority_queue<iip> people;

    for(ll i = 0; i < M; i++){
        ll a, b, y; cin >> a >> b >> y;
        a--;
        b--;
        road.push(make_pair(y, make_pair(a, b)));
    }

    ll Q; cin >> Q;
    vector<ll > ans(Q, 0);

    for(ll i = 0; i < Q; i++){
        ll v, w; cin >> v >> w;
        v--;
        people.push(make_pair(w, make_pair(v, i)));
    }  
    
    while(!people.empty()){
        ll w = people.top().first;
        ll v = people.top().second.first;
        ll i = people.top().second.second;
        while(!road.empty()){
            ll y = road.top().first;

            ll a = road.top().second.first;
            ll b = road.top().second.second;

            if(y <= w) break;

            solv.unite(a, b);
            road.pop();
            //cout << y << " " << w << endl;
        }
        ans[i] = solv.FindSize(v);
        //cout << solv.FindSize(v) << endl;
        people.pop();
    }

    for(ll i = 0; i < Q; i++){
        cout << ans[i] << endl;
    }
}