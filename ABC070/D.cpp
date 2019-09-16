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
#include <queue>
#include <functional> 

using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll > > > G;
vector<ll > ans;

//経由地点からの距離
vector<ll > dis;

void dfs(ll idx, ll from = -1){
 
    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //同じだったらもう処理しない
        //頂点に戻ってきたら
        //後戻りを許さない
        if(to == from){
            continue;
        }

        dis[to] += dis[idx] + G[idx][i].second;
 
        dfs(to, idx);
 
    }
}


int main(){
    ll N;
    cin >> N;
    
    //初期化
    G.assign(N, vector<pair<ll, ll > >());
    dis.assign(N, 0);
 
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

    ll Q, K;
    cin >> Q >> K;
    //ここでRE吐いてしまった．．．答えはQ個分なのに最初はN個にしてた
    //あほばかまぬけ
    ans.assign(Q, 0);
    //経由地点からdfs
    dfs(K-1);

    //確認
    /*
    for(ll i = 0; i < N; i++){
        cout << dis[i] << endl;
    }
    */
    
    for(ll i = 0; i < Q; i++){
        ll x, y;
        cin >> x >> y;
        ans[i] =  dis[x-1] + dis[y-1];
        //cout << dis[x-1] + dis[y-1] << endl;
    }

    for(ll i = 0; i < Q; i++){
        cout << ans[i] << endl;
    }

}