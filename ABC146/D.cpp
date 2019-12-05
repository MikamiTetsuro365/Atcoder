#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi; 

ll mx = -1;
map<pi, ll> memo;
vector<ll > ans;
vector<bool > seen;
vector<vector<pi > > G;

void dfs(ll idx, ll from = -1){

    seen[idx] = true;

    if(from == -1){
        memo[make_pair(from, idx)] = -1;
    }

    ll cn = 1;
    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        ll num = G[idx][i].second;
        //探査済み
        if(seen[to] == true){
            continue;
        }
        
        if(memo[make_pair(from, idx)] == cn){
            cn++;
        }

        memo[make_pair(idx, to)] = cn;
        ans[num] = cn;

        cn++;
        dfs(to , idx);
        
    }
    mx = max(cn-1, mx);
}

int main(){
    ll N;
    cin >> N;
    //初期化
    G.assign(N, vector<pi >());
    seen.assign(N, false);
    ans.assign(N-1, 0);

    //グラフ入力
    for(ll i = 0; i < N-1; i++){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, i));
        G[v].push_back(make_pair(u, i));
    }

    dfs(0);

    cout << mx << endl;

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }


}