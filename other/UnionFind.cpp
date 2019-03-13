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

    UnionFind test(N);

    for(int i = 0; i < M; i++){
        cin >> x >> y;
        test.unite(x - 1, y - 1);
        
        //確認
        cout << "Tree: " ;
        for(int j = 0; j < N; j++){
            cout << test.tree[j] << " ";
        }
        cout << endl;
        /*
        cout << "Hight: " ;
        for(int j = 0; j < N; j++){
            cout << test.rank[j] << " ";
        }
        cout << endl;
        */

    }
    //ture is 1, false is 0
    cout << "please inpunt 2 num" << endl;
    cin >> x >> y;
    cout << std::boolalpha << test.same(x - 1, y - 1) << endl;

}