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


vector<vector<pair<ll, ll > > > G;
//行きがけ順番を記憶（どんな順番で走査されたかを記憶）
vector<ll > pre;
//頂点から到達しうる最小の頂点
vector<ll > low;
//到達済みの頂点か
vector<bool > reach;
vector<pair<ll, ll > > ans;
//カウンター
void dfs(ll idx, ll from = -1, ll pre_count = -1){
    reach[idx] = true;
    pre[idx] = pre_count++;
    low[idx] = pre[idx];


    for(ll i = 0; i < G[idx].size(); i++){
        //cout << idx << endl;
        //次の行き先は？
        ll to = G[idx][i].first;
        //未探査のとき
        if(pre[to] == -1){
            //dfsを実行する
            //到達できる頂点の中で一番小さいpreを採用する
            dfs(to, idx, pre_count);
            low[idx] = min(low[idx], low[to]);
            //dfs(to, idx, pre_count);
            //low[idx] = min(low[idx], low[to]);

            //後退辺を使ったとしても根やそれ以上に戻ってきていない→つまりここが橋
            if( low[to] > pre[idx]){
                ans.push_back(make_pair(idx, to));
            }
        }else if(to != from){
            //すでに探査済みかつ根に戻ってきていないなら
            low[idx] = min(low[idx], pre[to]);
        }
 
    }

    //return low[idx];
}


int main(){
    ll N, M;
    cin >> N >> M;
    
    //初期化
    G.assign(N, vector<pair<ll, ll > >());
    //ns.assign(N, 0);
    pre.assign(N, -1);
    low.assign(N, -1);
    reach.assign(N, false);
 
    //グラフ入力
    for(ll i = 0; i < M; i++){
        ll u, v;
        //重みは今回は0
        ll w = 0;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    for(ll i = 0; i < N; i++){
        if(!reach[i])dfs(i);
    }
    
    cout << ans.size()<< endl;
    
    /*
    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i].first << "," << ans[i].second << endl;
    }
    */
    

}