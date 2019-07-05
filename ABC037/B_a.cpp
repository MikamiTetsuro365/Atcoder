#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>
#include <map>

using namespace std;
typedef long long int ll;
ll flg[1145141];
vector<ll > G[1145141];
//flg = 1 すでに到達済み 0＝まだ到達していない
ll dfs(ll idx, ll from = -1){
    ll f = 1;
    if(flg[idx] == 1){
        return 0;
    }

    //参照したので到達済みフラグを１にする
    flg[idx] = 1;

    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i];
        //同じだったらもう処理しない
        if(to == from){
            continue;
        }
        //from = idx > toへ
        //もしすでに到達済みの場所を参照したら、木ではなく閉路のある無向グラフ
        if(dfs(to, idx) == 1){
            //閉路ですよ
            f = 0;
        }
    }
    //1が帰ったら木ですよ
    return f;

}

int main(){

    ll N, M;
    cin >> N >> M;
    vector<ll > u(M);
    vector<ll > v(M);

    for(ll i = 0; i < M; i++){
        cin >> u[i];
        cin >> v[i];

        G[u[i]].push_back(v[i]);
    
    }

    ll ans = 0;
    for(ll i = 1; i<= N; i++){
        if(flg[i] == 1){
            continue;
        }
        if(dfs(i) == 1){
            ans++;
        }
    }

    cout << ans << endl;

} 