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

using namespace std;
typedef long long ll;

//辺の重みも設定できるグラフ
//to , weight の順
vector<vector<pair<ll, ll > > > G;
vector<ll > ans;

void dfs(ll idx, ll from = -1){

    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //同じだったらもう処理しない
        //頂点に戻ってきたら
        if(to == from){
            continue;
        }

        if(G[idx][i].second % 2 == 0){
            ans[to] = ans[idx];
        }else{
            ans[to] = 1 - ans[idx];
        }

        dfs(to, idx);

    }
}

int main(){

    ll N;
    cin >> N;
    
    //初期化
    G.assign(N, vector<pair<ll, ll > >());
    ans.assign(N, 0);

    //ans[0] = 0;

    //グラフ入力
    for(ll i = 0; i < N-1; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    //伝搬実行
    dfs(0);
    for(ll i = 0; i < N; i++){
        cout << ans[i] << endl;;
    }

}