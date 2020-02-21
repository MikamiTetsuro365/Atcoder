#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
vector<vector<pi > > G;
vector<bool > seen;
ll N, K;

void dfs(ll idx, ll from = -1){
    seen[idx] = true;

    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //探査済み
        if(seen[to] == true){
            continue;
        }
 
        dfs(to , idx);
    }
}

int main(){
    
    cin >> N >> K;
    if(N < K){
        cout << -1 << endl;
        return 0;
    }
    //初期化
    G.assign(N, vector<pi >());
    seen.assign(N, false);
 
    //グラフ入力
    for(ll i = 0; i < N - 1; i++){
        ll u, v, w;
        w = 0;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    dfs(0);

    //実はDFSとか関係ない
    cout << K - 1 << endl;

}