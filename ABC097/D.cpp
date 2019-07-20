#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;
typedef long long ll;

int N = 0;
int M = 0;
int x = 0;
int y = 0;

//?????????????????

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
    void unite(int x, int y){
        int tx = root(x);
        int ty = root(y);
        //xとyの根が同じならくっつけない
        if(tx == ty){
            return;
        }

        ll s = size[tx] + size[ty];
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

        //return s1;

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

    cin >> N >> M;
    vector<int > p(N,0);

    UnionFind u(N);
    
    for(int i = 0; i < N; i++){
        cin >> p[i];
    }
    //グループ分け(連結)
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        u.unite(x - 1, y - 1);
    }
    //確認
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(u.same(i, p[i] - 1)){
            ans++;
        }
        
    }
    cout << ans << endl;

}