#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;

//スター型のグラフを作ると直径が2なので後はちょうど2の辺がK個できるか数えるだけ
int main(){

    ll N, K; cin >> N >> K;

    if((N-1) * (N-2) / 2 >= K){
        //スターグラフを書くと最大(N-1)*(N-2)/2の条件に当てはまる最短距離2のノードのペアができる
        //数を調整したいときは最短距離が2のペアのノードに直通の距離1のパスを貼ってやる
        ll tmp = (N-1) * (N-2) / 2;
        cout << N - 1 + tmp - K << endl;
        for(ll i = 1; i <= N - 1; i++){
            cout << i << " " << N << endl;
        }

        //最短距離2のペアが多すぎるときは調整する
        //ペア同士を辺で直接つなぐ
        ll edge1 = 1;
        ll edge2 = 2;
        for(ll i = 0; i < tmp - K; i++){
            cout << edge1 << " " << edge2 << endl;
            edge2++;
            //edge2が限界に達したらedge1を更新
            //edge1とedge2(edge1+1)から再度ループを回す
            if(edge2 == N){
                edge1++;
                edge2 = edge1 + 1; 
            }
        }

    }else{
        cout << -1 << endl;
    }
} 