#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  

ll ans = 0;

ll dfs(vector<vector<ll> > G, vector<bool > seen, ll idx, ll from = -1){
    seen[idx] = true;
    
    vector<ll > tmp;
    //部下が1人もいない
    /*
    if(G[idx].size() == 0){
        return 1;
    }
    */

    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i];
        //探査済み
        if(seen[to] == true){
            continue;
        }
 
        ll s = dfs(G, seen ,to , idx);
        //cout << s << endl;
        tmp.push_back(s);
    }

    sort(tmp.begin(), tmp.end());
    if(tmp.size() == 1){
        return tmp[0] * 2 + 1;
    }else if(tmp.size() == 0){
        return 1;
    }else{
        return tmp[0] + tmp[tmp.size()-1] + 1;
    }

}

int main(){
    ll N;
    cin >> N;
    //初期化
    vector<vector<ll > > G;
    G.assign(N, vector<ll >());
    vector<bool > seen(N, false);
 
    //グラフ入力
    for(ll i = 1; i < N; i++){
        ll u; cin >> u; u--;
        //双方向に貼りましょうね
        G[u].push_back(i);
        G[i].push_back(u);
    }
    //cout << G.size() << endl;
    cout<< dfs(G ,seen ,0) << endl;
}