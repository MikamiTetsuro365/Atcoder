#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//Grundy数やってみる
int main(){

    ll N;
    cin >> N;

    vector<ll >G(1919, -1);
    //初期状態
    G[0] = 0;
    G[1] = 0;
    G[2] = 1;
    G[3] = 1;
    G[4] = 2;

    //現在の状態に移動してくる状態においてGrundy数の集合の内存在しない最小の非負整数
    //0:先手負け
    //1:先手勝ち
    //とりあえず移動してくる状態に0が含まれているかどうかをチェック
    //含まれていないと負け確定
    for(ll i = 5; i <= 100; i++){
        vector<bool > tmp(5, false);
        tmp[G[i-2]] = true;
        tmp[G[i-3]] = true;
        tmp[G[i-5]] = true;
        for(ll j = 0; j < 5; j++){
            if(tmp[j] == false){
                G[i] = j;
                break;
            }
        }
    }

    for(ll i = 0; i < N; i++){
        ll A; cin >> A;
        //cout << G[A] << endl;
        if(G[A] != 0){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }
}