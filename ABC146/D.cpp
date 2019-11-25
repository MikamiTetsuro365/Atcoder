#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi; 

vector<ll > ans;

vector<bool > seen;

void dfs(vector<vector<pi > > G,  ll idx, ll from = -1){
    seen[idx] = true;

    ll cn = 1;
    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //探査済み
        if(seen[to] == true){
            continue;
        }

        if(cn == ans[idx]){
            cn++;
        }
        ans[to] = cn;
        cn++;
        dfs(G, to , idx);
        
    }
}

int main(){
    ll N;
    cin >> N;
    //初期化
    vector<vector<pi > > G;
    G.assign(N, vector<pi >());
    seen.assign(N, false);
    ans.assign(N, -1);
    
 
    //グラフ入力
    for(ll i = 0; i < N-1; i++){
        ll u, v, w;
        w = 0;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    dfs(G ,0);

    ll mx = -1;
    for(ll i = 1; i < N; i++){
        mx = max(ans[i], mx);
    }
    cout << mx << endl;
    for(ll i = 1; i < N; i++){
        cout << ans[i] << endl;
    }
}