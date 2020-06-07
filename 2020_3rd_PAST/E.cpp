#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
vector<vector<pi > > G;
vector<bool > seen;
ll N, M, Q;

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
    
    cin >> N >> M >> Q;
    //初期化
    G.assign(N, vector<pi >());
 
    //グラフ入力
    for(ll i = 0; i < M; i++){
        ll u, v, w;
        w = 0;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    //色
    vector<ll > C(N, 0);
    for(ll i = 0; i < N; i++){
        ll c;
        cin >> c;
        C[i] = c;
    }

    vector<ll > ans;
    for(ll i = 0; i < Q; i++){
        ll s, x;
        cin >> s >> x;
        if(s == 1){
            ans.push_back(C[x-1]);
            //スプリンクラー起動
            for(ll j = 0; j < G[x-1].size(); j++){
                C[G[x-1][j].first] = C[x-1];
            }
        }else{
            ll y;
            cin >> y;
            ans.push_back(C[x-1]);
            C[x-1] = y;
        }
    }

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}