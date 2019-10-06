#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;


int main(){
    ll N, M;
    cin >> N >> M;
    
    //初期化
    G.assign(N, vector<pair<ll, ll > >());
    //ans.assign(N, 0);
    //vector<vector<pair<ll, ll > > > newG;
 
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

    //友達はいない
    if(G[0].size() == 0){
        cout << 0 << endl;
        return 0;
    }

    seen.assign(N, false); 
    dfs(0);

    cout << ans << endl;
}